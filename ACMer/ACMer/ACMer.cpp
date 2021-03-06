// ACMer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

struct show {
	int startTime;
	int endTime;
};

show shows[101];

bool compare(show a, show b) {
	return a.endTime < b.endTime;
}


int main()
{
	int n;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			cin >> shows[i].startTime >> shows[i].endTime;
		}

		sort(shows, shows + n, compare);

		int currentTime=0, int num = 0;
		for (int i = 0; i < n; i++) {
			if (currentTime <= shows[i].startTime) {
				currentTime = shows[i].endTime;
				num++;
			}
		}

		cout << num << endl;

	}
    return 0;
}

