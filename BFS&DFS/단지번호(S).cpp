#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, cnt = 0;
string s;
int map[26][26];
bool visited[26][26];
vector<int> v;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        cnt++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(!visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                map[nx][ny] = map[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && map[i][j] == 1) {
                bfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << v.size() << '\n';

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    return 0;
}