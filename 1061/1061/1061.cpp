// 1061.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>qscore(m), qanswer(m), sanswer(m),result(n,0);
	for(int i=0;i<m;i++)
	{
		cin >> qscore[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >> qanswer[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> sanswer[j];
			if(sanswer[j]==qanswer[j])
			{
				result[i] = result[i] + qscore[j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << result[i] << endl;
	}


    return 0;
}

