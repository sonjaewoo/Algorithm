#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool visited[101][101] = {0, };
int map[101][101] = {0, };
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!visited[nx][ny] && map[nx][ny] == 1) {
                map[nx][ny] = map[x][y] + 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    string s;

    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    bfs(0, 0);

    cout << map[n-1][m-1];

    return 0;
}