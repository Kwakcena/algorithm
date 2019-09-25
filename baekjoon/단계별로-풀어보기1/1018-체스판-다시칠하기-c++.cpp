#include <bits/stdc++.h>

#define MX_ROW 50
#define MX_COL 50
#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int n, m;
char Table[MX_ROW][MX_COL];
char color[2] = {'W', 'B'};

int check(int row, int col, char startColor) 
{
	char Temp[MX_ROW][MX_COL] = {0,};
	int index, i, j, cnt = 0;
	startColor == 'B' ? index = 1 : index = 0;

	for(i=row; i<row+8; i++) {
		for(j=col; j<col+8; j++) {
			Temp[i][j] = color[index];
			index = (++index % 2);
			if(Temp[i][j] != Table[i][j]) {
				//cout << "(" << i << " " << j << ")" << " ";
				//cout << "temp : " << Temp[i][j] << " Table : " << Table[i][j] << endl;
				cnt++;
			}
			//cout << Temp[i][j];
		}
		Temp[i][col+7] == 'B' ? index = 1 : index = 0;
		//cout << "temp[" << i << "][" << col+7 << "] = " << Temp[i][col+7] << endl;
		//cout << endl;
	}
	//cout << "cnt : " << cnt << endl;

	return cnt;

}

void solution()
{
	int result = 987987987;
	cin >> n >> m;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> Table[i][j];
		}
	}

	int row = n - 8, col = m - 8;
	for(int i=0; i<=row; i++) {
		for(int j=0; j<=col; j++) {
			result = MIN(result, check(i, j, 'B'));
			result = MIN(result, check(i, j, 'W'));
		}
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solution();
}
