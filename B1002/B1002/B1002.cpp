// B1002.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


struct T {
	int num = 1;
	string phone="";
};

string change(string phone) {
	char temp[8] = {'\0'};
	int k = 0;
	for (int i = 0; i<phone.size(); i++) {
		if (phone[i] == 'A' || phone[i] == 'B' || phone[i] == 'C') {
			temp[k++] = '2';
		}
		else if (phone[i] == 'D' || phone[i] == 'E' || phone[i] == 'F') {
			temp[k++] = '3';
		}
		else if (phone[i] == 'G' || phone[i] == 'H' || phone[i] == 'I') {
			temp[k++] = '4';
		}else if (phone[i] == 'J' || phone[i] == 'K' || phone[i] == 'L') {
			temp[k++] = '5';
		}
		else if (phone[i] == 'M' || phone[i] == 'N' || phone[i] == 'O') {
			temp[k++] = '6';
		}
		else if (phone[i] == 'P' || phone[i] == 'R' || phone[i] == 'S') {
			temp[k++] = '7';
		}
		else if (phone[i] == 'T' || phone[i] == 'U' || phone[i] == 'V') {
			temp[k++] = '8';
		}
		else if (phone[i] == 'W' || phone[i] == 'X' || phone[i] == 'Y') {
			temp[k++] = '9';
		}
		else if(phone[i]!='-') {
			temp[k++] = phone[i];
		}
	}
	string result(temp);
	result.insert(3, "-");
	return result;
}

bool compare(T a, T b) {
	return a.phone< b.phone;
}

int main()
{
	int n,count=0;
	cin >> n;
	string phone;
	T a[10000] ;
	for (int i = 0; i < n; i++) {
		cin >> phone;
		string temp = change(phone);
		for (int j = 0; j < n; j++) {
			if (a[j].phone.compare(temp) == 0) {
				a[j].num += 1;
				break;
			}
			else if(a[j].phone.compare("")==0) {
				a[j].phone = temp;
				count++;
				break;
			}
		}
	}
	

	if (count == n) {
		cout << "No duplicates." << endl;
	}
	else {
		sort(a, a + count, compare);
		for (int i = 0; i < count; i++) {
			if (a[i].num >= 2) {
				cout << a[i].phone << " " << a[i].num << endl;
			}
			
		}
	}
    return 0;
}

