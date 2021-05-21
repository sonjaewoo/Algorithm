#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

int f, s, g, u, d;
bool visited[MAX];

int bfs() {
    queue<pair<int, int> > q;
    visited[s] = true;
    q.push(make_pair(s,0));

    while(!q.empty()) {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(pos==g) return cnt;
        if(pos+u <= f && !visited[pos+u]) {
            q.push(make_pair(pos+u,cnt+1));
            visited[pos+u] = true;
        }
        if(pos-d >= 1 && !visited[pos-d]) {
            q.push(make_pair(pos-d, cnt+1));
            visited[pos-d] = true;
        }
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;

    int ans = bfs();

    if(ans == -1) cout << "use the stairs" << '\n';
    else cout << ans;

    return 0;
}