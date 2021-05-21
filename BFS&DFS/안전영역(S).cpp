#include <iostream>
#include <cstring>
using namespace std;

int n, min_n = 101, max_n = 0, cnt = 0;
int map[101][101];
bool visited[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void DFS(int x, int y, int h) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(!visited[nx][ny] && map[nx][ny] > h) {
            visited[nx][ny] = true;
            DFS(nx, ny, h);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int result = 1;

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            min_n = min(min_n, map[i][j]);
            max_n = max(max_n, map[i][j]);
        }
    }

    for(int h = min_n; h < max_n; h++) {
        int cnt = 0;
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] > h && !visited[i][j]) {
                    visited[i][j] = true;
                    cnt++;
                    DFS(i, j, h);
                }
            }
        }
        result = max(result, cnt);
    }

    cout << result;

    return 0;
}