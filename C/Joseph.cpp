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
 
LinkList InitList();//初始化单循环链表 
int getRandom(int m);//获取随机数 
void loop(LinkList head);//逐一弹出结点 
 
int main(){ 
 	LinkList head = InitList();
 	loop(head);
}

LinkList InitList(){
	//L为带头结点的循环单链表的头指针 
	int n, m, M;
 	printf("请分别输入人数，报数上限值:\n");
 	scanf("%d %d",&n,&m);
 	
 	LinkList head = (LNode *)malloc(sizeof(LNode));
 	head->next = NULL;
 	LinkList tail = head;
 	
 	
 	printf("手动输入每人手持密码请按 1 ，随机生成密码请按 2 :\n");
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
		printf("那么就请分别输入密码吧：\n");
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
	
	printf("每个人的序号及其手握的密码分别为:\n");
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
 	printf("设定初始密码值:");
 	scanf("%d",&M);
 	
 	LinkList p = head->next;
 	LinkList q;
 	int count = 1;
 	
 	while(p->next != p){
 		//找到要删除结点的前一个结点 
 		while(count++ < M-1){
 			p = p->next;
		}
		
		q = p->next;//q指向要删除的结点 
		p->next = q->next;//p->next指向q的下一个结点，这样保持单循环列表的结构 
		M = q->person.password;//获取要删除结点的密码， 
		printf("%d ",q->person.order);//并打印其序号。 
		free(q); //释放q 

        p = p->next;//p指向下一个结点 
		count = 1;
	 }
 	printf("%d",p->person.order);
 }
 
