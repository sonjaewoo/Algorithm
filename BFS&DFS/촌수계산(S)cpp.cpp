#include <iostream>
#include <vector>

using namespace std;

int n, a, b, m, x, y;
int d[101] ={0};
vector<int> v[101];

void dfs(int x) {

    for(int i = 0; i < v[x].size(); i++) {
        int y = v[x][i];
        if(d[y] == 0) {
            d[y] = d[x] + 1;
            dfs(y); 
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> a >> b >> m;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(a);
    int ans = d[b];

    cout << (ans != 0 ? ans : -1) << '\n';

    return 0;
}