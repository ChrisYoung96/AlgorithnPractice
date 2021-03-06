// BigNumCaculate.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#define MAX_LEN 1000
using namespace std;

/*
大整数运算的结构体
*/
struct Number {
	int num[MAX_LEN] = { 0 };  //存储大整数的数组
	int len;//实际整数位数
};

/*
将输入的字符串逆序存放到数组中，方便运算
*/
Number * char2int(char *s) {
	int len = strlen(s); //获取数字个数
	Number *a = new Number();
	for (int i = len - 1,j = 0; i >= 0; i--, j++)  //逆序存放
	{
		a->num[j] = s[i] - '0';
	}
	a->len = len;
	return a;
}

/*
大数加法
基本思路：
模拟竖式运算，将两个大整数逐位相加，若和>9则进位
result->number[]既用于存放结果，也用于临时存放进位
逐位相加的方法为：result->num[i] += a->num[i] + b->num[i];
*/
Number * bigplus(Number *a, Number *b) {
	int maxlen;//和的最大位数
	Number *result = new Number();//存放结果
	maxlen = a->len > b->len ? a->len : b->len;
	for (int i = 0; i < maxlen ; i++) {  //逐位相加
		result->num[i] += a->num[i] + b->num[i];
		if (result->num[i] > 9) {  //如果和超过10，当前位的数字为和除10的余数
			result->num[i] = result->num [i]% 10;
			result->num[i + 1] = 1; //向前进位
		}
	}
	result->len = maxlen; 
	return result;
}

/*
大整数乘法：
基本思路：
模仿竖式乘法，将b中的每一位数都与a逐位相乘，求得阶段结果，并按竖式乘法相加
每一位的计算方法为：result->num[k] += a->num[j] * b->num[i];
*/
Number *bigmultipile(Number *a, Number *b) {
	Number *result = new Number();
	for (int i = 0,k=0; i < b->len; i++,k++) {
		for (int j = 0; j < a->len; j++) {
			result->num[k] += a->num[j] * b->num[i];
			if (result->num[k] > 9) {  //如果该位的结果大于10，进位
				result->num[k + 1] += result->num[k] / 10; //获得进位
				result->num[k] = result->num[k] % 10; //计算当前位的结果
			}
			k++;
		}
		k = i;
	}
	result->len = a->len+b->len-1;  //两数相乘，结果的长度最长为两数长度之和，由于数组从0开始，所以数组中长度比最长长度少1
	return result;
}


/*
大整数减法
基本思路：
模仿竖式运算，逐位做差
存放结果的result->num[]既存放结果，又存放临时借位
每一位数字的计算方法为：result->num[i] += a->num[i] - b->num[i];
*/
Number *bigminus(Number *a, Number *b) {
	int maxlen;
	Number *result = new Number(),*temp;
	if (a->len < b->len) {
		temp = b;
		b = a;
		a = temp;
	}
	maxlen = a->len > b->len ? a->len : b->len;
	for (int i = 0; i < maxlen; i++) {
		result->num[i] += a->num[i] - b->num[i];
		if (result->num[i] <0) {  //如果同位做差小于0，向前借位
			result->num[i] = result->num[i] + 10;
			result->num[i + 1] = -1;
		}
	}
	result->len = maxlen-1;
	return result;
}


/*
逆序输出结果
*/
void printans(Number *t) {
	int len = t->num[t->len] == 0 ? t->len - 1 : t->len;
	for (int i = len; i >= 0; i--) {
			cout << t->num[i];
	}
	cout << endl;
}

int main() {
	char str1[MAX_LEN], str2[MAX_LEN];
	Number *a, *b, *result;
	while (cin >> str1) {
		cin >> str2;
		a = char2int(str1);
		b = char2int(str2);
		result = bigminus(a, b);
		printans(result);
	}
	

}
