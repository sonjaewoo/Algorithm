#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int node, edge, start;
vector<int> v[10];
bool visited[10];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int x = q.front();
        cout << x << ' ';
        q.pop();

        for(int i = 0; i < v[x].size(); i++) {
            int y = v[x][i];
            if(!visited[y]) {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

int main(void) {

    node = 4;
    edge = 5;
    start = 1;

    for(int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(start);


    return 0;
}