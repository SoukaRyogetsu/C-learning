//给定一个存放整数的数组，重新对数组排序使得数组的左边为奇数，右边为偶数，要求空间复杂度为O(1)。 
//void sort(int* arr, int len);
//有快排的影子
#include <stdio.h>
#include <string.h>
void sort(int* arr, int len) {
	int l = 0, r = len - 1;
	while (l < r) {
		int t = arr[l];
		while (l < r && arr[r] % 2 == 0) r--;
		arr[l] = arr[r];
		while (l < r && arr[l] % 2 == 1) l++;
		arr[r] = arr[l];
		arr[l] = t;
	}
}
int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int i,len = sizeof(a) / sizeof(9);
	sort(a, len);
	for(i=0;i<len;i++)
		printf("%d ", a[i]);
	return 0;
}
