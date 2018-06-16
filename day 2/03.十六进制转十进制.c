#include <stdio.h>
#include <math.h>
#include <string.h>
int flag = 1;
int ctn(char c) {
	if (c >= '0'&&c <= '9')
		return c - '0';
	else if (c >= 'a'&&c <= 'f')
		return c - 'a' + 10;
	else if (c >= 'A'&&c <= 'F')
		return c - 'A' + 10;
	else flag = 0;
}
int htd(char s[]) {
	int len = strlen(s), sum = 0;
	for (int i = 0; i<len; i++) {
		sum += ctn(s[i])*pow(16, len - 1 - i);
	}
	return sum;
}
int main() {
	char s[33];
	while (scanf("%s", s) != EOF) {
		int ans = htd(s);
		if (flag)
			printf("%d\n", ans);
		else printf("输入格式错误");
	}
	return 0;
}
