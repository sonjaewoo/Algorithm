#include <iostream>
using namespace std;

int N;
int operands[11];
int operators[4];
int MIN = 1000000001;
int MAX = -1000000001;

void dfs(int result, int idx) {
    if(idx == N) {
        if(result > MAX) MAX = result;
        if(result < MIN) MIN = result;
    }

    for(int i = 0; i < 4; i++) {
        if(operators[i] > 0) {
            operators[i]--;
            if(i==0) dfs(result+operands[idx], idx+1);
            else if(i==1) dfs(result-operands[idx], idx+1);
            else if(i==2) dfs(result*operands[idx], idx+1);
            else dfs(result/operands[idx], idx+1);
            operators[i]++;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> operands[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> operators[i];
    }
    dfs(operands[0], 1);

    cout << MAX << "\n" << MIN;

    return 0;
}