// bitree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

struct Node {
	Node *lchild;
	Node *rchild;
	char data;
}Tree[50];

int loc;

Node *create() {
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

char str1[30], str2[30];

void postOrder(Node *T) {
	if (T->lchild != NULL) {
		postOrder(T->lchild);
	}
	if (T->rchild != NULL) {
		postOrder(T->rchild);
	}
	cout << T->data;
}


Node *build(int s1, int e1, int s2, int e2) {
	Node *ret = create();
	ret->data = str1[s1];
	int rootidx;
	for (int i = s2; i <= e2; i++) {
		if (str2[i] == str1[s1]) {
			rootidx = i;
			break;
		}
	}
	if (rootidx != s2) {
		ret->lchild = build(s1 + 1, s1 + (rootidx - s2) + 1, s2, rootidx - 1);
	}
	if (rootidx != e2) {
		ret->rchild = build(s1 + (rootidx - s2) + 1, e1, rootidx + 1, e2);
	}
	return ret;
}

int main() {
	while (cin >> str1) {
		cin >> str2;
		loc = 0;
		int l1 = strlen(str1);
		int l2 = strlen(str2);
		Node *T = build(0, l1 - 1, 0, l2 - 1);
		postOrder(T);
		cout << endl;
	}
	return 0;
}


