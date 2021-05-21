#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

bool check(int level) {
    for(int i = 0; i < level; i++) {
        if(col[i] == col[level] || abs(col[level]-col[i]) == level-i) return false;
    }
    return true;
}

void nqueen(int x) {
    if(x==N) total++; // queen 모두 배치 완료 시 ++
    else {
        for(int i = 0; i < N; i++) {
            col[x] = i; // x번째 열, i번째 행 배치
            if(check(x)) nqueen(x+1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    nqueen(0);
    cout << total;
    return 0;
}