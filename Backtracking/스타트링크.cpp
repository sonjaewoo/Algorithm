#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
bool team[21];
int score[21][21];
int MIN = 987654321;

void func(int idx, int cnt) {

    vector<int> start;
    vector<int> link;

    int start_score = 0;
    int link_score = 0;
    if(cnt == (N/2)) {
        for(int i = 0; i < N; i++) {
            if(team[i] == true) start.push_back(i);
            else link.push_back(i);
        }
        for(int i = 0; i < (N/2); i++) {
            for(int j = 0; j < (N/2); j++) {
                start_score += score[start[i]][start[j]];
                link_score += score[link[i]][link[j]];
            }
        }
        if(abs(start_score-link_score) < MIN) 
            MIN = abs(start_score-link_score);
        return;
    }
    for(int i = idx; i < N; i++) {
        if(team[i]) continue;
        else {
            team[i] = true;
            func(i, cnt+1);
            team[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> score[i][j];
        }
    }
    func(0,0);
    cout << MIN;
    return 0;
}