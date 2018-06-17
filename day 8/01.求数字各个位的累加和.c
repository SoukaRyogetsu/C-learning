//从键盘任意输入一个4位数x，编程计算x的每一位数字相加之和（忽略整数前的正负号）。
//例如，输入x为1234，则由1234分离出其千位1、百位2、十位3、个位4，然后计算1+2+3+4=10，并输出10。
#include <stdio.h>
#include <stdlib.h>
int func(int x) {
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int main() {
	int x,sum;
	scanf("%d", &x);
	sum = func(x);
	printf("%d\n", sum);
}
