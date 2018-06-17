//比较重要，打个*，题解网上搜索的，网上题解很多，不过我这智商目前也就看得懂下面这个，够消化一段时间了。
#include <stdio.h>
#include <string.h>
#define swap(x,y) {int t=x;x=y;y=t;}
int findKthMinNumOfArrays(int *a, int lena, int *b, int lenb, int k){
	if (lena == 0)return b[k - 1];  //递归终点
	if (lenb == 0)return a[k - 1];
	int mid_a = lena >> 1, mid_b = lenb >> 1;
	int *p, *q, t;
	//if-else保证a[mid_a] <= b[mid_b]，便于统一求解
	if (a[mid_a] <= b[mid_b]) {
		p = a, q = b;
	}
	else {
		p = b;	q = a;
		swap(mid_a, mid_b); swap(lena, lenb);
	}
	t = mid_a + mid_b + 1;
	if (t >= k)  return findKthMinNumOfArrays(p, lena, q, mid_b, k);
	else if (t < k)return findKthMinNumOfArrays(p + mid_a + 1, lena - mid_a - 1, q, lenb, k - mid_a - 1);
}
int main() {
	int k = 19;
	int a[] = { 1,2,3,5,7,11,13,17,19,23 };
	int b[] = { 2,4,6,8,10,12,14,16,18,20 };
	int lena = sizeof(a) / sizeof(int);
	int lenb = sizeof(b) / sizeof(int);
//	int a[] = { 23,19,17,13,11,7,5,3,2,1 };
//	int b[] = { 20,18,16,14,12,10,8,6,4,2 };
	printf("%d\n", findKthMinNumOfArrays(a, lena, b, lenb, k));
	return 0;
}
