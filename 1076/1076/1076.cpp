// 1076.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct list {
	char a[4];
};

int change(char m) {
	char n = m;
	switch (n) {
	case 'A':
		return 1;
		break;
	case 'B':
		return 2;
		break;
	case 'C':
		return 3;
		break;
	case 'D':
		return 4;
		break;
	default:return 0;
	}
}



int main()
{
	
	int n;
	int code[100] = { 0 };
	cin >> n;
	list b[100][4];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> b[i][j].a;
			if (b[i][j].a[2] == 'T') {
				code[i] = change(b[i][j].a[0]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << code[i];
	}
    return 0;
}

