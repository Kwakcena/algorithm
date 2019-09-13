#include <bits/stdc++.h>
#define MX_LEN 101
using namespace std;

int n, m, s, e;
int dist[MX_LEN];
vector<int> graph[MX_LEN];

void bfs()
{
	queue<int> pos_q;
	memset(dist, -1, sizeof(dist));
	pos_q.push(s);
	dist[s] = 0;

	while(!pos_q.empty())
	{
		int curt_pos = pos_q.front();
		pos_q.pop();
		
		for(int i=0; i<graph[curt_pos].size(); i++) {
			int next_pos = graph[curt_pos][i];

			if(dist[next_pos] == -1) {
				dist[next_pos] = dist[curt_pos] + 1;	
				pos_q.push(next_pos);
			}
		}
	}
}

void solution()
{
	cin >> n;
	cin >> s >> e;
	cin >> m;

	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();
	cout << dist[e] << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solution();

	return 0;
}
