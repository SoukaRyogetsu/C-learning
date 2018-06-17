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
void add_end(pNode* phead, pNode* ptail, char data) {
	if (data == '\n') return;
	pNode pcur = *phead, pre = *phead;
	pNode pnew = init(data);
	if (pcur == NULL) {
		*phead = pnew;
		*ptail = pnew;
	}
	else {
		(*ptail)->next = pnew;
		*ptail = pnew;
	}
}
void print(pNode head) {
	while (head) {
		printf("%c ", head->data);
		head = head->next;
	}
	printf("\n");
}
void revList(pNode* phead) {
	pNode pcur = *phead, pre = NULL,t;
	while (pcur) {
		t = pcur->next;
		pcur->next = pre;
		pre = pcur;
		pcur = t;
	}
	*phead = pre;
}
int main(){
	pNode head1=NULL,tail1=NULL; 
	char c;
	while ((c = getchar()) != EOF) 
		add_end(&head1, &tail1, c);	
	print(head1);
	revList(&head1);
	print(head1);
	return 0;
}
