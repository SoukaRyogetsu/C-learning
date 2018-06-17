//手写链栈，还是磨练书写链表的能力
#include <stdio.h>
#include <string.h>
typedef struct tag{
	int m_ival;
	struct tag* next;
}Node, *pNode;
typedef struct tagstack{
	pNode m_head;
	int m_size;
}STACK, *pSTACK;

void pop(pSTACK stack) {	//出栈 
	stack->m_head = stack->m_head->next;
	stack->m_size--;
}
int top(pSTACK stack) {  //返回栈顶元素 
	return stack->m_head->m_ival;
}
int empty(pSTACK stack) {  //判断栈是否为空
	return (stack->m_size) == 0 ? 1 : 0;
}
int size(pSTACK stack) {  //返回栈中数据的元素个数
	return stack->m_size;
}
void push(pSTACK stack, int val) {  //入栈
	pNode pnew_node = (pNode)calloc(1, sizeof(Node));
	pnew_node->m_ival = val;
	if (empty(stack)) {
		stack->m_head = pnew_node;
		stack->m_size++;
	}
	else {
		pnew_node->next = stack->m_head;
		stack->m_head = pnew_node;
		stack->m_size++;
	}
}
void print(pSTACK stack) {  //打印
	pNode pcur = stack->m_head;
	while (pcur) {
		printf("%d ", pcur->m_ival);
		pcur = pcur->next;
	}
	printf("\n");
}
int main() {
	int val;
	pSTACK stack=(pSTACK)calloc(1,sizeof(STACK));
	while (scanf("%d", &val) != EOF) {		
		push(stack, val);		
	}
	print(stack);
	pop(stack);
	print(stack);
	printf("当前栈顶：%d\n", top(stack));
	pop(stack);
	printf("当前栈中元素个数：%d\n", size(stack));
	return 0;
}
