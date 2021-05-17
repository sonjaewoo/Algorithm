/*
플로이드 와샬
- 가중치가 음이거나 양이고, 모든 정점에서 모든 정점으로의 최단 경로를 구할 때 사용
- '거쳐가는 정점'을 기준으로 알고리즘 수행
- 2차원을 비용을 반복적으로 갱신
- 시간 복잡도 = O(N^3)
*/

#include <iostream>
#define INF 987654321
using namespace std;

int number = 4;

//자료 배열 초기화
int a[4][4] = {
    {0,5,INF,8},
    {7,0,9,INF},
    {2,INF,0,4},
    {INF,INF,3,0}
};

void floydWarshall() {
    //결과 그래프 초기화
    int d[number][number];

    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++) {
            d[i][j] = a[i][j];
        }
    }

    //k = 거쳐가는 노드
    for(int k = 0; k < number; k++) {
        //i = 출발 노드
        for(int i = 0; i < number; i++) {
            //j = 도착 노드
            for(int j = 0; j < number; j++) {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    //결과 출력
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++) {
            cout << d[i][j] << ' '; 
        }
        cout << '\n';
    }
}

int main(void) {

    floydWarshall();

    return 0;
}
