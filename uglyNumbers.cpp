//丑数是除了2，3，5之外不能被整除的数
//本程序使用队列和set来存储
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int maxn = 20;
const int coeff[3] = { 2,3,5 };

int main() {
	priority_queue<LL, vector<LL>, greater<LL> >pq;//优先队列 
	set<LL> s;//集合 
	LL a;
	pq.push(1);//队列插入1
	s.insert(1);//集合set不重复、按照顺序
	for (int i = 1;; i++) {
		LL x = pq.top();//弹出队列的队首元素
		cout << " the point x " << x << endl;
		pq.pop();
		if (i == maxn) {
			cout << "The maxn ugly number is " << x << ".\n";
			break;
		}
		for (int j = 0; j < 3; j++) {
			LL x2 = x * coeff[j];
			cout << " the x2 " << x2<< "the count is"<< s.count(x2) << endl;
			if (!s.count(x2)) {//如果丑数重复，不push,
				s.insert(x2);
				cout << " the x2_1 " << x2 << endl;
				pq.push(x2);
				cout << " the x2_2 " << x2 << endl;
			}
		}
	}
	system("pause");
	return 0;
}
