#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
	int data;
	struct Node* left, * right;
	Node(int x) {
		this->data = x;
		left = right = NULL;
	}
};
void PrintAvgLevelsUtil(Node* root, int height, vector<double>& sum, vector<int>& count) {
	if (root == NULL) return;

	sum[height] += root->data;
	count[height] += 1;
	PrintAvgLevelsUtil(root->left, height+1, sum, count);
	PrintAvgLevelsUtil(root->right, height+1, sum, count);
}
void PrintAvgLevels(Node* root, int n) {
	if (root == NULL) return;
	vector<double> sum(n, 0);
	vector<int> count(n, 0);
	
	PrintAvgLevelsUtil(root, 0, sum, count);
	for (int i = 0; i < n; i++) {
		if (count[i] > 0)
			cout << sum[i] / count[i] << " ";
		else
			break;
	}
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

	PrintAvgLevels(root, n);
	return 0;
}