// 1014.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{
	
	string first, second, third, fourth;
	string s[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	string day;
	int h=0, m=0;
	int i, count = 1;
	char first_letter, second_letter;

	cin >> first >> second >> third >> fourth;

	for (i = 0; i < first.length(); i++) {

			if (count == 1&&(first[i] >= 'A'&&first[i] <= 'G') && first[i] == second[i]) {
					first_letter = first[i];
					count++;
			}
			else if (first[i] == second[i] && count == 2 && ((first[i] >= 'A'&&first[i] <= 'N') || (first[i] >= '0'&&first[i] <= '9'))) {
				second_letter = first[i];
				break;
			}		
	}

	day = s[first_letter - 'A'];

	if (second_letter >= '0'&&second_letter <= '9') {
		h = second_letter - '0';
	}
	else {
		h = second_letter - 'A'+10;
	}

	for (i = 0; i < third.length()&&m==0; i++) {
		
			if (((third[i] >= 'A'&&third[i] <= 'Z')|| (third[i] >= 'a'&&third[i] <= 'z'))&& third[i] == fourth[i]) {
				m = i;
				break;
			}
		
	}
	if (h < 10&&m<10) {
		cout << day << " " <<"0"<< h << ":" << "0" << m << endl;
	}
	else if(h>10&&m<10) {
		cout << day << " " << h << ":" << "0" << m << endl;
	}
	else if (h < 10 && m>10)
	{
		cout << day << " " << "0" << h << ":" << m << endl;
	}
	else {
		cout << day << " " << h << ":" << m << endl;
	}
	
    return 0;
}



