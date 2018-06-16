//看到N直接蒙了，下意识使用了cpp的vector，解题过程也是十分暴力，一点技巧都没有
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
vector<vector<int> >v, ans;  //相当于开俩二维数组
void input() {
	string s;
	while (getline(cin, s)) {   //将每一行作为一个数组进行输入
		vector<int>tv;  
		istringstream is(s);  //将这一行写入一个输入流
		int num;
		while (is >> num)    //从流里写入这个临时vector
			tv.push_back(num);
		v.push_back(tv);  //将临时vector写入“二维数组”v
		tv.clear();     //清空临时vector
	}
}
void comElem(vector<int> v1, vector<int> v2) {
	vector<int>va;
	for (int a1 = 0, a2 = 0; a1<v1.size() && a2<v2.size();) {
		if (v1[a1]<v2[a2]) a1++;
		else if (v1[a1]>v2[a2]) a2++;
		else {
			va.push_back(v1[a1]);
			a1++; a2++;
		}
	}
	ans.push_back(va);  //两两相比后的结果存储在另一个二维数组ans里
}
void output() {
	for (auto &i : v[0])
		cout << i << " ";
}
void process() {
	do {  
		size_t len = v.size();  //获取v的长度，即二维数组里面有几个一维数组
		if (len % 2 == 0) {   //如果len为偶数，正好两两相比
			for (int i = 0; i<len / 2 ; i += 2)
				comElem(v[i], v[i + 1]);
		}
		else {
			for (int i = 0; i<len / 2 ; i += 2)
				comElem(v[i], v[i + 1]);
			comElem(v[len - 2], v[len - 1]);    //len为计数，将倒数第二个数组用两次，
		}
		v = ans;    //将ans完全拷贝给v，这时v的大小相比一开始少了一半
		ans.clear();  //ans清空，循环使用
	} while (v.size() != 1);  //只要v长度大于1，循环就没有结束
}
int main() {
	input();
	process();
	output();
	return 0;
}
