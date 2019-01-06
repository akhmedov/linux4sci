#include <iostream>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_NODES 100100
#define INF 100100

using namespace std;

struct Edge {
	int to;
	Edge* next;
};

int NODES, EDGES, REQUS;
Edge *first[MAX_NODES], *last[MAX_NODES];

int buffer[MAX_NODES];
int radius[MAX_NODES], diameter[MAX_NODES], tree[MAX_NODES];

void insert (int from, int to)
{
	Edge* prev = last[from];
	Edge* next = new Edge();
	next->to = to;

	if (prev) prev->next = next;
	else first[from] = next;

	last[from] = next;
}

int dfs (int node)
{
	for (int i = 0; i < NODES; i++) 
		buffer[i] = INF;

	buffer[node] = 0;
	int top = 0, stack[NODES];
	stack[top++] = node;
	int id = node;

	while (top) {
		
		int cur = stack[--top];
		if (buffer[id] < buffer[cur]) id = cur;

		Edge *e = first[cur];

		while (e) {
			int to = e->to;
			int w = buffer[cur] + 1;
			if (buffer[to] > w) {
				buffer[to] = w;
				stack[top++] = to;
			}
			e = e->next;
		}
	}

	return id;
}

int main ()
{
	cout.precision(10);
	freopen("forest_input.txt", "r", stdin);
	cin >> NODES >> EDGES >> REQUS;

	for (int i = 0; i < EDGES; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		insert(a,b);
		insert(b,a);
	}

	int tree_id = 1;
	for (int i = 0; i < NODES; i++) {
		
		int node = dfs(i);
		radius[i] = buffer[node];
		diameter[i] = buffer[dfs(node)];
		
		if (!tree[i]) {
			for (int j = 0; j < NODES; j++)
				if (buffer[j] < INF) tree[j] = tree_id;
			tree_id++;
		}
	}

	while (REQUS--) {

		int a, b;
		cin >> a >> b;
		a--; b--;

		if (tree[a] == tree[b]) {
			cout << -1 << endl;
			continue;
		}

		int old = MAX(diameter[a],diameter[b]);
		double sum = 0, terms = 0;

		for (int i = 0; i < NODES; i++) {
			if (tree[i] != tree[a]) continue;
			for (int j = 0; j < NODES; j++) {
				if (tree[j] != tree[b]) continue;
				sum += MAX(old,radius[i]+radius[j]+1);
				terms++;
			}
		}

		cout << fixed << sum/terms << endl;
	}

	return 0;
}
