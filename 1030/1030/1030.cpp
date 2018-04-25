// 1030.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n, p,i;
	cin >> n >> p;
	vector<long long int> a(n);
	for( i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int max = 0,len=0;
	for(i=0;i<n;i++)
	{
		for(int j=i+len;j<n;j++)
		{
			if (a[j] <= a[i] * p)
			{
				len = j - i + 1;
				if (max<len)
				{
					max = len;
				}
			}else
			{
				break;
			}
			
		}
		
	}
	cout << max;


    return 0;
}

