#include <iostream>
#include <vector>

using namespace std;
struct Node {
	int data;
	struct Node* left, *right;
	Node(int x) {
		this->data = x;
		left = right = NULL;
	}
};

void PrintRightView(struct Node* node, int level, int & height)
{
	if (node == NULL)	return;

	if (level > height) {
		cout << node->data << " ";
		height = level;
	}

	// printing the most right first, then keep the maximum height to print the inner lefts and rights. 
	PrintRightView(node->right, level+1, height);
	PrintRightView(node->left, level+1, height);
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
	int height = 0;
	PrintRightView(root, 1, height);
	return 0;
}
