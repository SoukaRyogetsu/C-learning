//从（0,0）到（m,n),每次走一步，只能向上或者向右走，有多少种路径走到(m,n)，打印路径
#include <cstdio>
#include <vector>
using namespace std;
int cnt = 0;
vector<int>x,y;
void erase_end() {  //删除末尾元素
	x.erase(x.end() - 1);
	y.erase(y.end() - 1);
}
void add_end(int ax, int ay) {  //添加元素
	x.push_back(ax);
	y.push_back(ay);
}
void print(vector<int>x, vector<int>y) {  //打印路径
	int len = x.size();
	for (int i = 0; i < len; i++) {
		if (i != 0) printf("-->");
		printf("(%d,%d)", x[i], y[i]);
	}
	printf("\n");
}
void run(int sx, int sy, int dx, int dy) {
	add_end(sx, sy);
	if (sx > dx || sy > dy) return;   //越界！直接退出
	if (sx == dx && sy == dy) {   //走到位置
		cnt++;
		print(x, y);
		return;
	}
	run(sx, sy + 1, dx, dy);  //一股脑往上走
	erase_end();  //往上走不动了，把刚刚添加的无效点坐标删掉
	run(sx + 1, sy, dx, dy);  //往右走
	erase_end();
}
int main() {
	int sx = 0, sy = 0, dx, dy;
	scanf("%d%d", &dx, &dy);
	run(sx, sy, dx, dy);
	printf("共%d条路径\n", cnt);
	return 0;
}
