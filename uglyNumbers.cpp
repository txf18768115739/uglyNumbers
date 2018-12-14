//丑数是除了2，3，5之外不能被整除的数
//本程序使用队列和set来存储
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;

const int coeff[3] = { 2,3,5 };

int main() {
	priority_queue<LL, vector<LL>, greater<LL> >pq;//优先队列 
	set<LL> s;//集合 
	pq.push(1);//队列插入1
	s.insert(1);//集合set不重复、按照顺序
	for (int i = 1;; i++) {
		LL x = pq.top();//弹出队列的队首元素
		pq.pop();
		if (i == 1500) {
			cout << "The 1500'th ugly number is " << x << ".\n";
			break;
		}
		for (int j = 0; j < 3; j++) {
			LL x2 = x * coeff[j];
			if (!s.count(x2)) {
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	system("pause");
	return 0;
}
