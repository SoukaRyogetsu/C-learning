//借用03中二进制转十进制的程序
#include <stdio.h>
#include <string.h>
int main() {
	int x, i,cnt=0;
	scanf("%d", &x);
	for (i = 31; i >= 0; i--)
		if (x >> i & 1 == 1)
			cnt++;
	printf("%d", cnt);
	return 0;
}
