#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ע��Ԫ���޶�ΪСд��ĸ�ַ�['a'-'z'] 
//���ڿ��Գ������֣�����������ʱҪ�޳�
//��������A�м�ȥB���е� 

#define LIST_INIT_SIZE 100

typedef struct{
 	char* base;
 	int length;//���ϳ��� 
 	int listsize; 
}SqList; 
 

int InitList_Sq(SqList &L);//��ʼ������˳��� 
void InitList(SqList &La, SqList &Lb);//��ʼ������ 
void MergeList(SqList &La,SqList &Laa, SqList Lb,SqList &Lc);//������ 
void IntersectList(SqList La, SqList Lb, SqList Lc, SqList &Ld);//�������� 
void SubtractList(SqList &La, SqList Ld,SqList &Lc);//������ 

//���������㷨 
void deleteCh(SqList &La,char ch);//ɾ������La�е��ض�Ԫ�� 
void sort(SqList &L);//���� 

int main(){
	SqList La,Laa,Lb,Lc,Ld;
	//La--����a 
	//Laa--��ʱ����a 
	//Lb--����b 
	//Lc--���� 
	//ld--���� 
	InitList(La, Lb);
	
	MergeList(La,Laa,Lb,Lc);//������ 
	IntersectList(La, Lb,Lc,Ld);//�������� 
	SubtractList(La, Ld,Lc);//����� 
	return 1;
} 

int InitList_Sq(SqList &L){
	L.base = (char *)malloc(LIST_INIT_SIZE*sizeof(char));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	
	return 1;	
}
 
void InitList(SqList &La, SqList &Lb){
	//��ʼ��La 
	printf("������Set1:\n");
	char strLa[40] = {0};
	gets(strLa);
	int lenLa = strlen(strLa);
	
	int a = InitList_Sq(La);
	for(int i = 0; i < lenLa; i++){
		if('a' <= strLa[i] && strLa[i] <= 'z'){
			La.base[La.length++] = strLa[i];
		}
	}	

    //��ʼ��Lb 
	printf("������Set2:\n");
	char strLb[40] = {0};
	gets(strLb);
	
	InitList_Sq(Lb);
	int lenLb = strlen(strLb);
	for(int i = 0; i < lenLb; i++){
		if('a' <= strLb[i] && strLb[i] <= 'z'){
			Lb.base[Lb.length++] = strLb[i];
		}
	}	
}

void sort(SqList &L){//���� 
	int i,pre,after,temp;
	int n = L.length;
	for( i = 0; i < n - 1; i++){
		for(pre = i, after = i + 1; after < n; after++){
			if(L.base[after] < L.base[pre]) pre = after;
		}
		
		if(pre != i){
			temp = L.base[i];
			L.base[i] = L.base[pre];
			L.base[pre] = temp;
		}
	}
}

void MergeList(SqList &La,SqList &Laa, SqList Lb,SqList &Lc){//������

	InitList_Sq(Laa);
	for(int i = 0; i < La.length; i++){//���� 
		Laa.base[Laa.length++] = La.base[i];
	}
	
	for(int i = 0; i < Lb.length; i++){//��Laa�в���Lb�е�Ԫ�� 
		if(!strchr(Laa.base,Lb.base[i])) Laa.base[Laa.length++] = Lb.base[i];
	}
	
	
	InitList_Sq(Lc);
	for(int i = 0; i < Laa.length; i++){//��Lc��¼��û���ظ���Ԫ�� 
		if(!strchr(Lc.base,Laa.base[i])) Lc.base[Lc.length++] = Laa.base[i];
	}
	
	
	printf("����Ϊ:\n");
	sort(Lc);
	for(int i = 0; i < Lc.length; i++){
		printf("%c",Lc.base[i]);
	}	
	printf("\n");
}

void IntersectList(SqList La, SqList Lb, SqList Lc, SqList &Ld){//�������� 
	InitList_Sq(Ld);
	for(int i = 0; i < Lc.length; i++){
		if((strchr(La.base,Lc.base[i]) )&& (strchr(Lb.base,Lc.base[i]))){
			Ld.base[Ld.length++] = Lc.base[i];
		}
	}
	
	if(Ld.length == 0){
		printf("����Ϊ:\n�ռ���");
	}
	
	else{ 
		printf("����Ϊ:\n");
		for(int i = 0; i < Ld.length; i++){
			printf("%c",Ld.base[i]);
		}
	}
}


void SubtractList(SqList &La, SqList Ld,SqList &Lc){
	for(int i = 0; i < Ld.length; i++){
		if(strchr(La.base,Ld.base[i])){
			deleteCh(La,Ld.base[i]);
		}
	}	
	
	InitList_Sq(Lc);
	for(int i = 0; i < La.length; i++){//��Lc��¼��û���ظ���Ԫ�� 
		if(!strchr(Lc.base,La.base[i])) Lc.base[Lc.length++] = La.base[i];
	}
	
	printf("\n�Ϊ:\n");
	sort(Lc);
	for(int i = 0; i < Lc.length; i++){
		printf("%c",Lc.base[i]);
	}
}

void deleteCh(SqList &La,char ch){//ɾ��a�����е�chԪ�� 
	for(int i = 0; i < La.length; i++){
		if(La.base[i] == ch){
			for(int j = i; j < La.length - 1; j++){//�������ǰŲһ��λ�� 
				La.base[j] = La.base[j+1];
			}
			La.length--;//ɾȥһ��Ԫ�أ�����Ҫ�ǵü�һ 
		}
	}
}





