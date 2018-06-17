//链表里面套了棵树，捋了好久才捋清关系，任重而道远……
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char c;
	struct node *left;
	struct node *right;
}Node, *pNode;
typedef struct list {   //这个是链表，里面有个树结点
	pNode elem;
	struct list *next;
}List,*pList;
void inorder(pNode node) {
	if (node != NULL) {
		inorder(node->left);
		printf("%c ", node->c);
		inorder(node->right);
	}
}
int main(){
	pNode tree = NULL;
	pList head=NULL,tail=NULL;
	int i,j;
	char c;
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') break;  //认为读到回车结束
		pNode pnew_node = (pNode)calloc(1, sizeof(Node));  //为要插入的树结点开辟空间
		pList pnew_list = (pList)calloc(1, sizeof(List));  //为要插入的链表结点开辟空间
		pnew_node->c = c;	//树结点内容是字符c
		pnew_list->elem = pnew_node;  //链表结点内容是上一行的树结点

		if (tree == NULL) {  //如果树空
			tree = pnew_node;
			head = pnew_list;   //自然，链表也是空的
			tail = pnew_list;   //有尾指针，尾插方便
			continue;
		}
		tail->next = pnew_list;  //树不空，链表也肯定不空。将链表的尾指针指向新开辟的链表结点
		tail = pnew_list;

		pNode pncur = tree;  //建立一个用于遍历的当前树结点
		pList plcur = head;  //建立一个用于遍历的当前链表结点
		while (plcur) {  //这里面写pncur也行，一样的，这两个结构体链表肯定一样长
			if (pncur->left == NULL) {
				pncur->left = pnew_node;
				break;
			}
			else if (pncur->right == NULL) {
				pncur->right = pnew_node;
				break;
			}
			pncur = plcur->next->elem;  //当前树结点左右都有孩子了，层序找下一个树结点
			plcur = plcur->next;   
		}
	}
	inorder(tree);
	return 0;
}
