//将两个有序链表合并成一个有序链表。
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}Node,*pNode;
pNode init(char data) {
	pNode pnew = (pNode)calloc(1, sizeof(Node));
	pnew->data = data;
	return pnew;
}
void add_sort(pNode* phead, pNode* ptail, char data) {
	if (data == '\n') return;
	pNode pcur = *phead,pre=*phead;
	pNode pnew = init(data);
	if (pcur== NULL) {
		*phead = pnew;
		*ptail = pnew;
	}
	else if (pcur->data > data) {  //插入起始处
		pnew->next = pcur;
		*phead = pnew;
	}
	else {
		while (pcur) {
			if (pcur->data > data) {
				pnew->next = pcur;
				pre->next = pnew;
				break;
			}
			pre = pcur;
			pcur = pcur->next;
		}
		if (pcur==NULL) {
			(*ptail)->next = pnew;
			*ptail = pnew;
		}
	}
}
void print(pNode head) {
	while (head) {
		printf("%c ", head->data);
		head = head->next;
	}
	printf("\n");
}
pNode add_linklist(pNode head1, pNode head2) {
	pNode head = NULL,tail=NULL;
	while (head1) {
		add_sort(&head, &tail, head1->data);
		head1 = head1->next;
	}
	while (head2) {
		add_sort(&head, &tail, head2->data);
		head2 = head2->next;
	}

	return head;
}
int main(){
	pNode head1=NULL,tail1=NULL; 
	pNode head2 = NULL, tail2 = NULL;
	char c;
	while ((c = getchar()) != EOF) 
		add_sort(&head1, &tail1, c);	
	while ((c = getchar()) != EOF) 
		add_sort(&head2, &tail2, c);
	pNode head3 = add_linklist(head1, head2);
	print(head1);
	print(head2); 
	print(head3);
	return 0;
}
