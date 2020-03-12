#include "RBTree.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	RB_Tree<int, int> tree;
	vector<int> v;
	int i = 0;
	for (i = 0; i < 20; ++i)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	stringstream sstr;
	for (i = 0; i < v.size(); ++i)
	{
		tree.Insert(v[i], i);
		cout << "insert:" << v[i] << endl;   //添加结点
	}
	for (i = 0; i < v.size(); ++i)
	{
		cout << "Delete:" << v[i] << endl;
		tree.Delete(v[i]);             //删除结点
		tree.InOrderTraverse();
	}
	cout << endl;
	tree.InOrderTraverse();
	return 0;
}