#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;

int n, k;
bool visited[MAX+1];
int d[MAX+1];
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int now = q.front();
        if(now == k) {
            cout << d[k] << '\n';
            break;
        }
        q.pop();

        if(now-1>=0) {
            if(!visited[now-1]) {
                q.push(now-1);
                visited[now-1] = true;
                d[now-1] = d[now] + 1;
            }
        }
        if(now+1<MAX) {
            if(!visited[now+1]) {
                q.push(now+1);
                visited[now+1] = true;
                d[now+1] = d[now] + 1;
            }
        }
        if(now*2<MAX) {
            if(!visited[now*2]) {
                q.push(now*2);
                visited[now*2] = true;
                d[now*2] = d[now] + 1;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    visited[n] = true;
    q.push(n);

    bfs();

    return 0;
}