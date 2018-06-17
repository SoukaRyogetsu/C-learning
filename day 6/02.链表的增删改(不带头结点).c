//还是不熟，删除和有序花了不少时间，二级指针慢慢习惯了
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}Node,*pNode;
//新建一个结点指针
pNode init(char data) {
	pNode pnew = (pNode)calloc(1, sizeof(Node));
	pnew->data = data;
	return pnew;
}
//尾插法
void add_end(pNode* phead, pNode* ptail ,char data) {
	if (data == '\n') return;
	pNode pcur = *phead;
	pNode pnew = init(data);
	if (*phead == NULL) {
		*phead = pnew;
		*ptail = pnew;
	}
	else {
		(*ptail)->next = pnew;
		*ptail = pnew;
	}
}
//头插法
void add_front(pNode* phead, pNode* ptail, char data) {
	if (data == '\n') return;
	pNode pnew = init(data);
	if (*phead == NULL) {
		*phead = pnew;
		*ptail = pnew;
	}
	else {
		pnew->next = *phead;
		*phead = pnew;
	}
}
////有序插入
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
//删除指定元素结点
void delete_node(pNode *phead, pNode *ptail, char data) {
	pNode pcur = *phead, pre = *phead;
	int f = 0;
	while (pcur) {
		if (pcur->data == data) {
			f = 1;
			if (pcur == *phead) {
				*phead = pcur->next;
				pre = pre->next;
				pcur = pcur->next;
				continue;
			}
			else if (pcur == *ptail) {
				*ptail = pre;
				pre->next = NULL;
				break;
			}
			pre->next = pcur->next;
			pcur = pcur->next;
		}
		else {
			pre = pcur;
			pcur = pcur->next;
		}
	}
	if(f==0)
		printf("所删除的结点不存在\n");
}
//修改链表元素
void modify(pNode *phead, pNode *ptail, char before, char after) {
	int f = 0;
	pNode pcur = *phead;
	while (pcur) {
		if (pcur->data == before) {
			pcur->data = after;
			f = 1;
		}
		pcur = pcur->next;
	}
	if (f == 0)
		printf("输入错误，未找到该节点\n");
}
//打印
void print(pNode head) {
	while (head) {
		printf("%c ", head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	pNode head1=NULL,tail1=NULL; //同时维护头尾指针
	pNode head2 = NULL, tail2 = NULL;
	pNode head3 = NULL, tail3 = NULL;
	char c;
	while ((c = getchar()) != EOF) {
		add_front(&head1, &tail1, c);
		add_end(&head2, &tail2, c);
		add_sort(&head3, &tail3, c);
	}
	print(head1);
	print(head2); 
	print(head3);
	delete_node(&head1, &tail1, 'k');
	print(head1);
	modify(&head2, &tail2, 'a', 'A');
	print(head2);
	return 0;
}
