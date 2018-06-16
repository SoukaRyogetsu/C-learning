//输入一行字符串，把字符串翻转
//（1）直接翻转一下 （2）把每个单词找出来，原地自身翻转
//自己做时第二问做的很蠢，没贴
#include<stdio.h>
#include<stdlib.h>
char* allReverse(char a[], int len) {
	char *p = a;
	for (int i = 0; i < len / 2; i++) {
		int t = *(p + i);
		*(p + i) = *(p + len - i - 1);
		*(p + len - i - 1) = t;
	}
	return a;
}
char* wordReverse(char a[], int len) {
	char *p = allReverse(a, len); 
	int p1 = 0, p2 = 0;
	while (p2 <= len)
	{
		if (p2 == len || a[p2] == ' ')
		{
			allReverse(&a[p1], p2 - p1);
			p1 = p2 + 1;
		}
		p2++;
	}
	return a;
}
int main() {
	char a[67], b[67];
	gets(a); gets(b);
	char *a1 = allReverse(a, strlen(a));
	char *b1 = wordReverse(b, strlen(b));
	printf("%s\n%s\n", a1, b1);
	return 0;
}
