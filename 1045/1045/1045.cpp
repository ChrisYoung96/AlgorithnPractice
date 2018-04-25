// 1045.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N,  max = 0, small = 1000001;
	int num=0;
	cin >> N;
	vector<int>a(N,0),result,big(N,0);
	
	for(int i=0;i<N;i++)
	{
		cin >> a[i];
		big[i] = max;
		if(a[i]>max)
		{
			max = a[i];
		}
	}

	for(int i=N-1;i>=0;i--)
	{
		if(a[i]>big[i]&&a[i]<small)
		{
			result.push_back(a[i]);
		}
		if(a[i]<small)
		{
			small = a[i];
		}
	}
	num = result.size();
	cout << num << endl;

	if(num-1>=0)
	{
		cout << result[num - 1] ;
	}
	for(int i=num-2;i>=0;i--)
	{
		cout << " " << result[i] ;
	}

    return 0;
}

