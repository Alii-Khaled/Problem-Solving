#include <iostream>
#include<list>
#include<stack>
#include <vector>
using namespace std;
void FamilyTreeUtil(list<int> graph[], int i, stack<int>& stack_fam, vector<bool>& vis) {
	vis[i] = true;
	for (auto const& j : graph[i]) {
		if (!vis[j]) {
			FamilyTreeUtil(graph, j, stack_fam, vis);
		}
	}
	stack_fam.push(i);
	return;
}
stack<int> FamilyTree(list<int> graph[], int n) {
	vector<bool> vis(n);
	for (int i = 0; i < n; i++) {
		vis[i] = false;
	}
	stack<int> stack_family;
	for (int i = 0; i < n;i++) {
		if (!vis[i]) {
			FamilyTreeUtil(graph, i, stack_family, vis);
		}
	}
	return stack_family;
}
int main()
{
	int n;
	cin >> n;
	list<int> *graph = new list<int>[n];
	int p1, p2;
	for (int i = 0; i < n; i++) {
		cin >> p1 >> p2;
		if (~p1)	graph[p1].push_back(i);
		if (~p2)	graph[p2].push_back(i);
	}
	stack<int> out = FamilyTree(graph, n);
	while (!out.empty()) {
		cout << out.top()<< " ";
		out.pop();
	}
	/* Testing.
	for (int i = 0; i < n; i++) {
		while(!graph[i].empty()) {
			cout << graph[i].front();
			graph[i].pop_front();
			cout<< " ";
		}
		cout << endl;
	}
	*/
	return 0;
}