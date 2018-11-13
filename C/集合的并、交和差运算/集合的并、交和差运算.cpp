#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//注意元素限定为小写字母字符['a'-'z'] 
//表内可以出现数字，但是再运算时要剔除
//减运算是A中减去B中有的 

#define LIST_INIT_SIZE 100

typedef struct{
 	char* base;
 	int length;//集合长度 
 	int listsize; 
}SqList; 
 

int InitList_Sq(SqList &L);//初始化单个顺序表 
void InitList(SqList &La, SqList &Lb);//初始化输入 
void MergeList(SqList &La,SqList &Laa, SqList Lb,SqList &Lc);//合运算 
void IntersectList(SqList La, SqList Lb, SqList Lc, SqList &Ld);//交集运算 
void SubtractList(SqList &La, SqList Ld,SqList &Lc);//差运算 

//两个辅助算法 
void deleteCh(SqList &La,char ch);//删除集合La中的特定元素 
void sort(SqList &L);//排序 

int main(){
	SqList La,Laa,Lb,Lc,Ld;
	//La--集合a 
	//Laa--临时集合a 
	//Lb--集合b 
	//Lc--并集 
	//ld--交集 
	InitList(La, Lb);
	
	MergeList(La,Laa,Lb,Lc);//合运算 
	IntersectList(La, Lb,Lc,Ld);//交集运算 
	SubtractList(La, Ld,Lc);//差集运算 
	return 1;
} 

int InitList_Sq(SqList &L){
	L.base = (char *)malloc(LIST_INIT_SIZE*sizeof(char));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	
	return 1;	
}
 
void InitList(SqList &La, SqList &Lb){
	//初始化La 
	printf("请输入Set1:\n");
	char strLa[40] = {0};
	gets(strLa);
	int lenLa = strlen(strLa);
	
	int a = InitList_Sq(La);
	for(int i = 0; i < lenLa; i++){
		if('a' <= strLa[i] && strLa[i] <= 'z'){
			La.base[La.length++] = strLa[i];
		}
	}	

    //初始化Lb 
	printf("请输入Set2:\n");
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

void sort(SqList &L){//排序 
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

void MergeList(SqList &La,SqList &Laa, SqList Lb,SqList &Lc){//合运算

	InitList_Sq(Laa);
	for(int i = 0; i < La.length; i++){//复制 
		Laa.base[Laa.length++] = La.base[i];
	}
	
	for(int i = 0; i < Lb.length; i++){//往Laa中插入Lb中的元素 
		if(!strchr(Laa.base,Lb.base[i])) Laa.base[Laa.length++] = Lb.base[i];
	}
	
	
	InitList_Sq(Lc);
	for(int i = 0; i < Laa.length; i++){//往Lc中录入没有重复的元素 
		if(!strchr(Lc.base,Laa.base[i])) Lc.base[Lc.length++] = Laa.base[i];
	}
	
	
	printf("并集为:\n");
	sort(Lc);
	for(int i = 0; i < Lc.length; i++){
		printf("%c",Lc.base[i]);
	}	
	printf("\n");
}

void IntersectList(SqList La, SqList Lb, SqList Lc, SqList &Ld){//交集运算 
	InitList_Sq(Ld);
	for(int i = 0; i < Lc.length; i++){
		if((strchr(La.base,Lc.base[i]) )&& (strchr(Lb.base,Lc.base[i]))){
			Ld.base[Ld.length++] = Lc.base[i];
		}
	}
	
	if(Ld.length == 0){
		printf("交集为:\n空集！");
	}
	
	else{ 
		printf("交集为:\n");
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
	for(int i = 0; i < La.length; i++){//往Lc中录入没有重复的元素 
		if(!strchr(Lc.base,La.base[i])) Lc.base[Lc.length++] = La.base[i];
	}
	
	printf("\n差集为:\n");
	sort(Lc);
	for(int i = 0; i < Lc.length; i++){
		printf("%c",Lc.base[i]);
	}
}

void deleteCh(SqList &La,char ch){//删除a中所有的ch元素 
	for(int i = 0; i < La.length; i++){
		if(La.base[i] == ch){
			for(int j = i; j < La.length - 1; j++){//后面的往前挪一个位置 
				La.base[j] = La.base[j+1];
			}
			La.length--;//删去一个元素，长度要记得减一 
		}
	}
}





