// 1006.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int main()
{
	int n, numb = 0, nums = 0, numg = 0, i ,j;
	char b = 'B', s = 'S';
	char result[27];
	cin >> n;
	numb = n / 100;
	nums = (n % 100) / 10;
	numg = n % 10;
	for (i = 0,j=0; j < numb; j++,i++) {
		result[i] = b;
	}
	for (j=0; j < nums; j++,i++) {
		result[i] = s;
	}
	for (j = 1; j <= numg; j++, i++) {
		result[i] ='0'+ j;
	}
	result[i] = '\0';
	cout << result;
    return 0;
}

