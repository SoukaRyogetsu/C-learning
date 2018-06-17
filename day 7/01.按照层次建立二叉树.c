//比较蠢的方法，能建出来就行，慢慢学习
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
typedef struct node {
	char c;
	struct node *left;
	struct node *right;
}Node, *pNode;
void preorder(pNode node) {
	if (node != NULL) {
		printf("%c ", node->c);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(pNode node) {
	if (node != NULL) {
		inorder(node->left);
		printf("%c ", node->c);
		inorder(node->right);
	}
}
void postorder(pNode node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		printf("%c ", node->c);
	}
}
int main(){
	pNode tree ,p[N];
	char c[N] = { 'A','B','C','D','E','F','G','H','I','J' };
	int i,j;
	for (i = 0; i < N; i++) {
		p[i] = (pNode)calloc(1, sizeof(Node));
		p[i]->c = c[i];
	}
	tree = p[0];
	for (i = 1; i < N; i++) {  //进树的元素
		for (j = 0; j < i; j++) {  //找位置
			if (p[j]->left == NULL) {
				p[j]->left = p[i];
				break;
			}
			else if(p[j]->right==NULL){
				p[j]->right = p[i];
				break;
			}
		}
	}
	preorder(tree); printf("\n");
	inorder(tree); printf("\n");
	postorder(tree); printf("\n");
	return 0;
}
