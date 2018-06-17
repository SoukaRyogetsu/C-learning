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
void find_mid(pNode *phead) {
	pNode pre = *phead, pcur = (*phead)->next;
	int f = 0;
	while (pcur) {
		pcur = pcur->next;
		if (pcur == NULL) {
			f = 1; break;
		}
		pre = pre->next;
		pcur = pcur->next;
	}
	if (f == 1)
		printf("%c %c\n", pre->data, pre->next->data);
	else
		printf("%c\n", pre->data);
}
int main(){
	pNode head1=NULL,tail1=NULL; 
	char c;
	while ((c = getchar()) != EOF) 
		add_end(&head1, &tail1, c);	
	print(head1);
	find_mid(&head1);
	return 0;
}
