#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int node, edge, start;
vector<int> v[10];
bool visited[10];

void dfs(int start) {
    visited[start] = true;
    cout << start << ' ';
    
    for(int i = 0; i < v[start].size(); i++) {
        int x = v[start][i];
        if(!visited[x]) {
            visited[x] = true;
            dfs(x);
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

    dfs(start);


    return 0;
}