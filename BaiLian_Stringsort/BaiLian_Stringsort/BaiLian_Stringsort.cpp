// BaiLian_Stringsort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>

using namespace std;

struct item {
	int num=0;
	char str[60];
};

bool compare(item a, item b) {
	return a.num < b.num;
}

int main()
{
	int n;
	cin >> n;
	item a[51];
	for (int i = 0; i < n; i++) {
		cin >> a[i].str;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; a[i].str[j] != '\0'; j++) {
			if (a[i].str[j] > a[i].str[j + 1]) {
				a[i].num += 1;
			}
		}
	}
	sort(a, a + n, compare);

	for (int i = 0; i < n; i++) {
		cout << a[i].str<<endl;
	}

    return 0;
}

