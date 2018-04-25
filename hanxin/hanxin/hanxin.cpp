// hanxin.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma disable warning 4996;


int hanxin() {
	int  a, b, c;
	printf("Please input a,b,c:\n");
	cin >> a >> b >> c;
	int result = 0;
	result = a*70 + b*21 + c*15;
	while (result > 105) {
		result -= 105;
	}
	if (result>= 10 && result <= 100) {
		printf("Total Number is %d \n", result);
	}
	else {
		printf("No Answer\n");
	}
	return 0;
}

int subsequence() {
	long long  n=0, m=0,kase=1;
	do {
		double result = 0.0;
		cin >> n >> m;
		if (n*m > 0&&n<=m) {
			for (int i = n; i <= m; i++) {
				result += (double)1 / (i*i);
			}
			printf("Case %d :%.5f \n", kase,result);
			kase++;
		}
	}while(n != 0 && m != 0);
	return 0;
}

int main()
{
	subsequence();
    return 0;
}


