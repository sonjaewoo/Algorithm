#include <iostream>
using namespace std;

int N, M;
bool checked[10];
int a[10];

void func(int idx, int m) {
    if(idx == m) {
        for(int i = 0; i < m; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(checked[i]) continue;
        checked[i] = true;
        a[idx] = i;
        func(idx+1, m);
        checked[i] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    func(0, M);

    return 0;
}