//利用二级指针排序好处，不改变原有数组/链表在内存里的位置
#include <stdio.h>
#include <string.h>
#define N 5
//二级指针的偏移
int main() {
	char b[5][15] = { "Google","Facebook","Linkin","Amazon","Microsoft" };
	char *p[5],*tmp;
	char **p2 = (char**)malloc(5 * sizeof(char*));
	int i,j;
	for (i = 0; i < N; i++) p2[i] = b[i];
	for (i = 0; i < N; i++) puts(b[i]);
	//索引式排序
	for (i = N-1; i > 0; i--) {//外层控制无序数的个数
		for (j = 0; j < i; j++) {
			if (strcmp(p2[j], p2[j + 1]) == 1) {
				tmp = p2[j];
				p2[j] = p2[j+1];
				p2[j+1] = tmp;
			}
		}
	}
	printf("\n");
	for (i = 0; i < N; i++) puts(p2[i]);
	printf("\n");
	for (i = 0; i < N; i++) puts(b[i]);
	return 0;
}
