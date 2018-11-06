 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <time.h> 
 
using namespace std;

typedef struct {
	int order;
	int password;
}Person; 

 typedef struct LNode{
 	Person person;
 	struct LNode *next;
 }LNode, *LinkList; 
 
LinkList InitList();//��ʼ����ѭ������ 
int getRandom(int m);//��ȡ����� 
void loop(LinkList head);//��һ������� 
 
int main(){ 
 	LinkList head = InitList();
 	loop(head);
}

LinkList InitList(){
	//LΪ��ͷ����ѭ���������ͷָ�� 
	int n, m, M;
 	printf("��ֱ�������������������ֵ:\n");
 	scanf("%d %d",&n,&m);
 	
 	LinkList head = (LNode *)malloc(sizeof(LNode));
 	head->next = NULL;
 	LinkList tail = head;
 	
 	
 	printf("�ֶ�����ÿ���ֳ������밴 1 ��������������밴 2 :\n");
 	int flag;
 	scanf("%d",&flag);
 	
 	if(flag == 2){
 	srand(time(NULL));
 	for(int i = 0; i < n; i++){
 		LNode* p = (LNode *)malloc(sizeof(LNode)); 
 		p->person.order = i + 1;
 		p->person.password = getRandom(m);
 		
 		p->next = tail->next;
 		tail->next = p;
 		tail = p;	
	}
	}
	
	else {
		printf("��ô����ֱ���������ɣ�\n");
		for(int i = 0; i < n; i++){
 		LNode* p = (LNode *)malloc(sizeof(LNode)); 
 		p->person.order = i + 1;
 		scanf("%d",&p->person.password);
 		
 		p->next = tail->next;
 		tail->next = p;
 		tail = p;	
 	}
	}
	tail->next = head->next;
	
	LinkList k= head->next;
	
	printf("ÿ���˵���ż������յ�����ֱ�Ϊ:\n");
	for(int j = 0; j < n; j++){
		printf("%d ",k->person.order);
		k = k->next;
	}
	printf("\n");
	for(int j = 0; j < n; j++){
		printf("%d ",k->person.password);
		k = k->next;
	}
	printf("\n");
	
	return head;	
 }
 
 int getRandom(int m){
 	return rand()%(m)+1;
 }
 
 void loop(LinkList head){
 	int M;
 	printf("�趨��ʼ����ֵ:");
 	scanf("%d",&M);
 	
 	LinkList p = head->next;
 	LinkList q;
 	int count = 1;
 	
 	while(p->next != p){
 		//�ҵ�Ҫɾ������ǰһ����� 
 		while(count++ < M-1){
 			p = p->next;
		}
		
		q = p->next;//qָ��Ҫɾ���Ľ�� 
		p->next = q->next;//p->nextָ��q����һ����㣬�������ֵ�ѭ���б�Ľṹ 
		M = q->person.password;//��ȡҪɾ���������룬 
		printf("%d ",q->person.order);//����ӡ����š� 
		free(q); //�ͷ�q 

        p = p->next;//pָ����һ����� 
		count = 1;
	 }
 	printf("%d",p->person.order);
 }
 
