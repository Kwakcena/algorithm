#include <bits/stdc++.h>
using namespace std;

int N, M;
int R_x, R_y, B_x, B_y, O_x, O_y;
int dy[] = {-1, +1, 0, 0}, dx[] = {0, 0, -1, +1};
int dist[10][10];

vector<string> myMap;

int range_check(pair<int, int> red, pair<int, int> ble)
{
	if((red.first < M && red.first >=0 && red.second < N && red.second >= 0)
			&& (ble.first < M && ble.first >= 0 && ble.second < N && ble.second >=0 ))
		return 1;
	else return 0;
}

void testPrint()
{
	for(int i=0; i<N; i++) cout << myMap[i] << endl;
	cout << endl;
}

void testPrint2()
{
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int bfs()
{
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int> > red_q, blue_q;

	red_q.push(make_pair(R_y, R_x));
	dist[R_y][R_x] = 0;

	blue_q.push(make_pair(B_y, B_x));

	while(!red_q.empty())
	{
		pair<int, int> red_c = red_q.front(), ble_c = blue_q.front();	
		red_q.pop(); blue_q.pop();

		for(int i=0; i<4; i++) {
			pair<int, int> red_next, blue_next;

			red_next.first = red_c.first + dy[i];
			red_next.second = red_c.second + dx[i];

			blue_next.first = ble_c.first + dy[i];
			blue_next.second = ble_c.second + dx[i];

			if(range_check(red_next, blue_next)) {
				if(dist[red_next.first][red_next.second] == -1) {

					if(myMap[red_next.first][red_next.second] == '.') {
						dist[red_next.first][red_next.second] = dist[red_c.first][red_c.second] + 1;
						red_q.push(red_next);
					}
					else if(myMap[red_next.first][red_next.second] == 'O') {
						return dist[red_c.first][red_c.second] + 1;
					}

					if(myMap[blue_next.first][blue_next.second] == '.') {
						blue_q.push(blue_next);
					}
					else blue_q.push(ble_c);
				}
			}
			//cout << i << endl;
			//testPrint();
			//testPrint2();
			
		}
	}
	return -1;
}

void solution()
{
	cin >> N >> M;

	for(int i=0; i<N; i++) {
		string temp;
		cin >> temp;

		int r = temp.find('R');
		int b = temp.find('B');
		int o = temp.find('O');

		if(r != -1) { R_y = i; R_x = r; }
		if(b != -1) { B_y = i; B_x = b; }
		if(o != -1) { O_y = i; O_x = o; }

		myMap.push_back(temp);
	}

	cout << bfs();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
}
