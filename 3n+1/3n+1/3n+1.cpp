// 3n+1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, step = 0, i = 0;
	cin >> n;
	if (n != 0 && n <= 1000){
		while (n != 1) {
			if (n % 2 == 0) {
				n = n / 2;
				i++;
			}
			else if (n % 2 == 1) {
				n = (3 * n + 1) / 2;
				i++;
			}
		}
	}
	
	cout << i;
	cout << endl;
    return 0;
}

