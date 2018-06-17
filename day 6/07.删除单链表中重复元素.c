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
	pNode pcur = *phead, pre = *phead;
	pNode pnew = init(data);
	if (pcur == NULL) {
		*phead = pnew;
		*ptail = pnew;
	}
	else if (pcur->data > data) {  
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
		if (pcur == NULL) {
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
void delete_rep(pNode *phead,pNode *ptail) {
	pNode pre = *phead, pcur = (*phead)->next, t;
	while (pcur) {
		if (pcur->data == pre->data) {
			t = pcur;
			pcur = pcur->next;
			pre->next = pcur;
			free(t);
		}
		else {
			pre = pcur;
			pcur = pcur->next;
		}
		if (pre->next == NULL) 
			*ptail = pre;
	}
}
int main(){
	pNode head1=NULL,tail1=NULL; 
	char c;
	while ((c = getchar()) != EOF) 
		add_sort(&head1, &tail1, c);	
	print(head1);
	delete_rep(&head1,&tail1);
	print(head1);
	return 0;
}
