//求一个字符串数组的最大值和次大值  void big(char *arr[],int size ,char** big1,char** big2)
//一开始被给的参考函数形参列表吓到了，最大值和次大值也是二级指针，还要考虑最大值不唯一？
//后来证明我想多了，只是把字符数组的地址传进去便于写值而已
#include <stdio.h>
#include <string.h>
//默认最大值和次大值存在且唯一
void big(char *arr[], int size, char** big1, char** big2) {
	int blen = 0, sblen = 0;
	for (int i = 0; i < size; i++) {
		int curlen = strlen(arr[i]);
		if (curlen > blen) {
			sblen = blen;
			blen = curlen;
			*big2 = *big1;
			*big1 = *(arr + i);
		}
		else if (curlen > sblen) {
			sblen = curlen;
			*big2 = *(arr + i);
		}
	}
}
int main() {
	char *src[] = { "hello","cat","no","believe","anything" };
	char *big1, *big2;
	int row = sizeof(src) / sizeof(src[0]);
	big(src, row, &big1, &big2);
	printf("%s\n%s", big1, big2);
	return 0;
}
