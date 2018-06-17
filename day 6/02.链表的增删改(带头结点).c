//尽管带头结点比不带头结点的链表考虑的东西少，但自己手太生，写的太慢，需多加练习
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
void add_end(pNode head, char data) {
	pNode pcur = head;
	pNode pnew = init(data);
	while (pcur->next) {
		pcur = pcur->next;
	}
	pcur->next = pnew;
	return head;
}
//头插法
void add_front(pNode head, char data) {
	pNode pnew = init(data);
	pnew->data = data;
	pnew->next = head->next;
	head->next = pnew;
	return head;
}
////有序插入
void add_sort(pNode head, char data) {
	int f = 0;
	pNode pcur = head->next,pre=head;
	pNode pnew = init(data);
	if (head->next== NULL) {
		head->next = pnew;
	}
	else {
		while (pcur) {
			if (pcur->data > pnew->data) {
				pre->next = pnew;
				pnew->next = pcur;
				f = 1;
				break;
			}
			pre = pcur;
			pcur = pcur->next;
		}
	}
	if(f==0)
		pre->next = pnew;
	return head;
}
//删除指定元素结点
void delete_node(pNode head, char data) {
	pNode pcur = head->next, pre = head,t;
	int f = 0;
	while (pcur) {
		if (pcur->data == data) {
			t = pcur;
			pre->next = pcur->next;
			pcur = pcur->next;
			free(t);
			f = 1;
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
void modify(pNode head, char before, char after) {
	int f = 0;
	pNode pcur = head->next;
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
	while (head->next) {
		printf("%c ", head->next->data);
		head = head->next;
	}
	printf("\n");
}
int main()
{
	char *s = "HelloTHEWORLD!!!";
	printf("%s\n", s);
	pNode head1 = (pNode)calloc(1, sizeof(Node));
	pNode head2 = (pNode)calloc(1, sizeof(Node));
	pNode head3 = (pNode)calloc(1, sizeof(Node));
	while (*s != '\0') {
		add_end(head1, *s);
		add_front(head2, *s);
		add_sort(head3, *s);
		s++;
	}
	print(head1);
	print(head2);
	print(head3);

	delete_node(head1, '!');
	print(head1);

	char before, after;
	printf("现对链表2进行修改，输入要修改的链表内容：\n");
	scanf("%c", &before);
	printf("输入修改后内容：\n");
	setbuf(stdin, NULL);
	scanf("%c", &after);
	modify(head2, before, after);
	print(head2);


	return 0;
}
