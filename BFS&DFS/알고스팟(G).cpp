#include <iostream>
#include <string>
#include <queue>
#define INF 987654321

using namespace std;

int M, N;
int map[101][101];
int d[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs() {
    d[0][0] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            if(map[nx][ny] == 1) {
                if(d[nx][ny] > d[x][y] + 1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
            else if(map[nx][ny] == 0) {
                if(d[nx][ny] > d[x][y]) {
                    d[nx][ny] = d[x][y];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        string st;
        cin >> st;
        for(int j = 0; j < st.length(); j++) {
            map[i][j] = st[j] - '0';
            d[i][j] = INF;
        }
    }

    bfs();

    cout << d[M-1][N-1];

    return 0;
}