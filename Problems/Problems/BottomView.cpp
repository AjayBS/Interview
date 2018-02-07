#include<stdio.h>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
struct Node
{
	int data;
	int hd;
	Node *left, *right;

	Node(int key)
	{
		data = key;
		left = right = NULL;
	}
};


void BottomView(Node *root)
{
	root->hd = 0;
	map<int, int> m;

	queue<Node *> q;

	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		int hd = temp->hd;

		m[hd] = temp->data;

		if (temp->left != NULL)
		{
			q.push(temp->left);
			temp->left->hd =  temp->hd - 1;
		}

		if (temp->right != NULL)
		{
			q.push(temp->right);
			temp->right->hd = temp->hd + 1;
		}
	}

	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->second << " ";
	}

}

// Driver Code
int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n";
	BottomView(root);
	return 0;
}