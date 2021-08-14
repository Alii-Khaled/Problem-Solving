#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int data;
	struct Node* left, * right;
	Node(int x) {
		this->data = x;
		left = right = NULL;
	}
};
long long SumTree(Node* root) {
	if (root == NULL)	return 0;

	return root->data + SumTree(root->left) + SumTree(root->right);
}

void PrintGreaterSumTreeUtil(Node* root, long long& sum) {
	if (root == NULL) return;

	PrintGreaterSumTreeUtil(root->left, sum);
	sum -= root->data;
	cout << sum << " ";
	PrintGreaterSumTreeUtil(root->right, sum);
}

void PrintGreaterSumTree(Node* root) {
	long long sum = 0;
	sum = SumTree(root);
	PrintGreaterSumTreeUtil(root, sum);
	return;
}

int main()
{
	int n, e;
	cin >> n;
	vector<Node*> verts;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		struct Node* n = new Node(tmp);
		verts.push_back(n);
	}
	cin >> e;
	char edge;
	int p, c;
	for (int i = 0; i < e; i++) {
		cin >> edge;
		cin >> p >> c;
		if (edge == 'L') {
			verts[p]->left = verts[c];
		}
		else {
			verts[p]->right = verts[c];
		}
	}
	struct Node* root = verts[0];

	PrintGreaterSumTree(root);
	return 0;
}