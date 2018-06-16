//大整数加法.实现任意范围的两个整数的加法（整数的范围用int 型的变量无法表示,50位）
//大概是PAT甲级送分题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans[111] = { 0 };
void strrev(char a[]) {
	int len = strlen(a);
	for (int i = 0; i<len / 2; i++) {
		char t = a[i];
		a[i] = a[len - 1 - i];
		a[len - i - 1] = t;
	}
}
void add(char a[], char b[]) {
	int lena = strlen(a), lenb = strlen(b), c = 0;
	strrev(a); strrev(b);
	for (int i = 0; i<lena && i<lenb; i++) {
		ans[i] = (a[i] - '0' + b[i] - '0' + c) % 10;
		c = (a[i] - '0' + b[i] - '0') / 10;
	}
	while (lena<lenb) {
		ans[lena] = (b[lena] - '0' + c) % 10;
		c = (b[lena] - '0' + c) / 10;
		lena++;
	}
	while (lenb<lena) {
		ans[lenb] = (a[lenb] - '0' + c) % 10;
		c = (a[lenb] - '0' + c) / 10;
		lenb++;
	}
	if (c != 0)
		ans[lena] = c;
	for (int i = lena - 1; i >= 0; i--)
		printf("%d", ans[i]);
}
int main() {
	char a[111] = "111409875023498570238239586";
	char b[111] = "23948757023948702398093488";
	add(a, b);
	return 0;
}
