// 1009.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	char str[80];
	int i = 0,len=0;
	int start = 0,end=0;
	cin.getline(str, 80);
	for (int k = 0; str[k] != '\0'; k++) {
		len++;
	}
	if (str[len - 1] == ' ') {
		end = len - 2;
	}
	else {
		end = len - 1;
	}
	
	for (i = len; i >=0; i--) {
		if (str[i] == ' ') {
			start = i+1;
			for (int j = start; j <= end; j++) {
				cout << str[j];
			}
			cout << " ";
			end = i - 1;
		}
		
		
	}
	for (i = 0; i <= end; i++) {
		cout << str[i];
	}
	cout << endl;
    return 0;
}

