// biaodashi.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stack>
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> t;



int main()
{
	int n;
	while (cin >> n) {
		while (t.empty() == false) {
			t.pop();
		}
		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			t.push(x);
		}
		int ans = 0;
		while (t.size() > 1) {
			int a = t.top();
			t.pop();
			int b = t.top();
			t.pop();
			ans += a + b;
			t.push(a + b);
		}
		cout << ans;
	}
}

