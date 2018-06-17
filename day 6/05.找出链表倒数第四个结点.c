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
void find_last(pNode *phead, int index) {
	pNode pre = *phead, pcur = *phead;
	while (index--) {
		if (pcur == NULL) {
			printf("链表长度小于4！\n");
			return;
		}
		pcur = pcur->next;
	}
	while (pcur) {
		pre = pre->next;
		pcur = pcur->next;
	}
	printf("%c\n", pre->data);
}
int main(){
	pNode head1=NULL,tail1=NULL; 
	char c;
	while ((c = getchar()) != EOF) 
		add_end(&head1, &tail1, c);	
	print(head1);
	find_last(&head1,4);
	return 0;
}
