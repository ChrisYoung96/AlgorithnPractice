// 1002.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int sum = 0,temp=0;
	char a[110];
	string b[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	cin >> a;
	for (int i = 0; a[i]!='\0';i++) {
		temp = a[i] - '0';
		sum = sum + temp;
	}
	if (sum / 1000 != 0) {
		cout << b[sum / 1000] << " ";
		sum = sum % 1000;
	}
	if (sum / 100 != 0) {
		cout<< b[sum / 100] << " ";
		sum = sum % 100;
	}
	if (sum / 100 == 0 && sum / 10 != 0) {
		cout << b[sum / 10] << " ";
		sum = sum % 10;
	}

	cout << b[sum];
	cout << endl;
    return 0;
}

