//计算一个整数对应的二进制中1的个数。例如7包含1的个数为3。int sum1bits(int ival);
//这次换了种方法
#include <stdio.h>
int sum1bits(int ival) {
	int cnt = 0;
	while (ival) {
		cnt++;
		ival &=(ival - 1);
	}
	return cnt;
}
int main() {
	int x, i, cnt = 0;
	scanf("%d", &x);
	cnt = sum1bits(x);
	printf("%d", cnt);
	return 0;
}
