//给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，请找出这个数
#include <stdio.h>
#define n 1001
int ran() {
	return rand() % 1000+1;
}
int main() {
	srand((unsigned)time(NULL));
	int a[n];
	for (int i = 0; i<n - 1; i++)
		a[i] = i + 1;
	a[n - 1] = ran();
	int sum = a[0];
	for (int i = 1; i<n; i++)
		sum = sum^a[i];
	printf("%d", sum);
	return 0;
}
