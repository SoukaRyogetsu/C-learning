//有102个整数，其中有50个数出现了两次，2个数出现了一次，找出出现了一次的那2个数。
#include<stdio.h>
#define N 102
int main() {
	int a[N], ans = 0, cans = 0, ans1 = 0, ans2 = 0, p = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		ans ^= a[i];    //102个数字全部异或
	}
	cans = ans;
	while (1) {
		if (ans % 2 == 1) break;  
    //ans非0，二进制表示时至少有一位是1，这个1是两个只出现一次的数字异或出来的结果
		p++;
		ans >>= 1;
	}
	for (int i = 0; i<N; i++)
		if ((a[i] >> p) & 1)      //以之前找到的位置将102个数字划分分两半，题目转化为05(1).
			ans1 ^= a[i];
	ans2 = ans1^cans;
	printf("%d %d", ans1, ans2);
	return 0;
}
