//将一个整数链表 L1拆分成两个链表 L2，L3。一个链表上的值全部是奇数，另一个链表上的值全部是偶数。
//例如：L1: 1,2,3,4,5,6,7,8,9,10 
//L2: 1,3,5,7,9 
//L3: 2,4,6,8,10 
//练习链表不要停
#include <stdio.h>
#include <string.h>
typedef struct tag{
	int m_ival;
	struct tag* next;
}Node, *pNode;
void add_front(pNode *phead, int x) {
	pNode pnew = (pNode)calloc(1, sizeof(Node));
	pnew->m_ival = x;
	if (*phead == NULL) {
		*phead = pnew;
	}
	else {
		pnew->next = *phead;
		*phead = pnew;
	}
}
void split(pNode L1, pNode *L2, pNode *L3) {
	while (L1) {
		if (L1->m_ival % 2) {
			add_front(L2, L1->m_ival);
		}
		else {
			add_front(L3, L1->m_ival);
		}
		L1 = L1->next;
	}
}
void print(pNode head) {
	while (head) {
		printf("%d ", head->m_ival);
		head = head->next;
	}
	printf("\n");
}
int main() {
	pNode L1 = NULL, L2 = NULL, L3 = NULL;
	int x;
	while (scanf("%d", &x) != EOF) {
		add_front(&L1, x);
	}
	split(L1, &L2, &L3);
	print(L1);
	print(L2);
	print(L3);
	return 0;
}
