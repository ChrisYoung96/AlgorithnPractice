// 1035.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
 
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int i, j;
	for (i = 0; b[i] <= b[i + 1] && i < n - 1; i++);
	for (j = i + 1; j < n&&a[j] == b[j]; j++);
	if (j == n) {
		cout << "Insertion sort" << endl;
		sort(a.begin(),a.begin()+ i + 2);
	}
	else {
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag) {
			flag = 0;
			for (i = 0; i < n; i++) {
				if (a[i] != b[i]) {
					flag = 1;
				}
			}
			k = k * 2;
			for (i = 0; i < n / k; i++) {
				sort(a.begin() + i * k, a.begin() + (i + 1)*k);
			}
			sort(a.begin() + n / k * k, a.end());
		}

	}
	
	for (int i = 0; i < n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1];

    return 0;
}

