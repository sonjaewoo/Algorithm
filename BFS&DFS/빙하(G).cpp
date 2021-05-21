#include <iostream>
#include <queue>
#include <cstring>
#define MAX 301

using namespace std;

int n, m;
bool visited[MAX][MAX];
int map[MAX][MAX];
int c_map[MAX][MAX];
queue<int> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int a, int b) {
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    visited[a][b] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!visited[nx][ny] && map[nx][ny] != 0) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int melt(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(map[nx][ny] == 0) cnt++;
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int year = 0;
    while(1) {
        int land_cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(c_map, 0, sizeof(c_map));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] != 0 && !visited[i][j]) {
                    land_cnt++;
                    bfs(i, j);
                }
            }
        }
        if(land_cnt >= 2) {
            cout << year << '\n';
            break;
        } 
        if(land_cnt == 0) {
            cout << 0 << '\n';
            break;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] != 0) {
                    c_map[i][j] = map[i][j] - melt(i, j);
                    if(c_map[i][j] < 0) c_map[i][j] = 0;
                }
            }
        }

         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                map[i][j] = c_map[i][j];
            }
        }
        year++;       
    }
    return 0;
}