// 1050.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct MN
{
	int m = 0;
	int n = 0;
	int c = 100000;
};

struct B
{
	int value = 10001;
	bool hasvalude = false;
};

bool compare(MN a1, MN a2)
{
	return a1.c < a2.c;
}

bool compare1(const int& a,const int& b)
{
	return a > b;
}

int main()
{
	int N, n, m, k = 0,x=0,y=0,i=0;

	B arc[100][100];
	MN a[100];
	cin >> N;
	vector<int> num;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end() , compare1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i*j == N && i >= j)
			{
				a[k].m = i;
				a[k].n = j;
				a[k].c = i - j;
				k++;
			}

		}
	}


	sort(a, a + 100, compare);
	m = a[0].m;
	n = a[0].n;

	while ( i < N-1)
	{
		while(y+1<n&&!arc[x][y+1].hasvalude)
		{
			arc[x][y].value = num[i++];
			arc[x][y].hasvalude = true;
			y++;
			
		}
		while(x+1<m&&!arc[x+1][y].hasvalude)
		{
			arc[x][y].value = num[i++];
			arc[x][y].hasvalude =true;
			x++;
		
		}
		while(y-1>=0&& !arc[x][y-1].hasvalude)
		{
			arc[x][y].value = num[i++];
			arc[x][y].hasvalude = true;
			y--;
			
		}
		while(x-1>=0&& !arc[x-1][y].hasvalude)
		{
			arc[x][y].value = num[i++];
			arc[x][y].hasvalude = true;
			x--;
			
		}
	}

	arc[x][y].value = num[N - 1];
	arc[x][y].hasvalude = true;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			cout << arc[i][j].value << " ";
		}
		cout << arc[i][n - 1].value << endl;
	}



    return 0;
}

