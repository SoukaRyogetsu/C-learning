//有103个整数，其中有50个数出现了两次，3个数出现了一次，找出出现了一次的那3个数。
//做不出来，网上找的题解
//两个数还好说，很容易将数组分成两摞，然后把这两个数分开
//三个数就麻烦了，分成三摞是不可能的，以0划分，有可能三个数字这一位全是0，也有可能2个1和1个0。以1划分，有可能这三个数这一位全是1，或者是两个0一个1
//百思不得其解后搜答案，得到的结果是：枚举每一位！
//因为总存在那么一位，使得（一个数字在这一位为1，另两个为0）||（一个数字在这一位为0，另两个为1）==1 
//反证：如果上述条件不成立，那么全部位置上三个数要么同时为1，要么同时为0，这个时候三个数相等，与条件相违背！
#include<stdio.h>
#include<stdlib.h>
#define N 103
int a[N + 1], ans1 = 0, ans2 = 0, ans3 = 0;  //数组多开一个位置，有用
void findTheSecondAndTheThird() {
	int sum = 0, pos = 0;
	for (int i = 0; i<N + 1; i++) sum ^= a[i];
	int tsum = sum;
	while (1) {
		if (tsum % 2) break;
		tsum >>= 1;
		pos++;
	}
	for (int i = 0; i < N + 1; i++) {
		if (i == 99) {
			int k = 3;
		}
		if ((a[i] >> pos) & 1)
			ans2 ^= a[i];
	}
	ans3 = ans2^sum;
}
void findTheFirst() {
	for (int i = 0; i<32; i++) {  //i循环int的每一位
		int tmp1 = 0, tmp0 = 0, cnt0 = 0, cnt1 = 0;
		for (int j = 0; j<N; j++) {   //同样，也要按0 1分组的
			if (a[j] & (1 << i)) {
				cnt1++;   //记录1组的个数
				tmp1 ^= a[j];   //记录1组全部数据的异或值
			}
			else {
				cnt0++;     //记录0组的个数
				tmp0 ^= a[j];    //记录0组全部数据的异或值
			}
		}//变量j的for
		if (cnt1 % 2) {  
     //如果1组的数组为奇数，那么这一组里面可能有1个待求数字，也可能有3个，不可能有两个
     //（出现两次的数字总是在同一组内出现两次的，如果这一组没有出现一次的数字或者有两个出现一次的数字，那么这一组元素个数必然为偶数）
			if (tmp0 != 0) {   
      //第1组个数为奇数且第0组全部数据异或值不为0，说明第1组有一个待求数字，第0组有两个
      //（如果第1组有3个待求元素，那么第0组全部是由出现两次的元素组成的，那么这一组异或和肯定是0）
				ans1 = tmp1;  //第1组的异或和就是所求的三个数之中的一个
				a[N] = tmp1;  //把这个数放入文件末尾，那么这个问题就转化为在104个数当中有两个仅出现一次的数，有51个出现两次的数，与05（2）完全相同
				findTheSecondAndTheThird();  //找剩下的两个数
				return;
			}
		}//if
		else {   //对称处理
			if (tmp1 != 0) {
				ans1 = tmp0;
				a[N] = tmp0;
				findTheSecondAndTheThird();
				return;
			}
		}//else
	}//变量i的for
}
void init() {
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		a[i] = t;
	}
}
int main() {
	init();
	findTheFirst();
	printf("%d %d %d", ans1, ans2, ans3);
	return 0;
}
