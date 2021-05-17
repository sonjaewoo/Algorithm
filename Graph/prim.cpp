/*
[Prim algorithm]

- 무방향 그래프, MST 기반
- 집합 set에서 연결된 모든 edge 중 최소 가중치 간선을 선택
- Select the connected smallest one!!
- 시간 복잡도 : 평균 O(E*logV), 최악 O(V^2)
V = node, E = edge

*/

#include <iostream>
#define INF 987654321
#define NUM 7
using namespace std;

int weight[NUM][NUM] = {
    {0,28,INF,INF,INF,10,INF},
    {28,0,16,INF,INF,INF,14},
    {INF,16,0,12,INF,INF,INF},
    {INF,INF,12,0,22,INF,18},
    {INF,INF,INF,22,0,25,24},
    {10,INF,INF,INF,25,0,INF},
    {INF,14,INF,18,24,INF,0}
};

bool selected[NUM];
int dist[NUM];

int getMinVertex(int n) {
    int v, i;
    for(i = 0; i < n; i++) {
        if(!selected[i]) {
            v = i;
            break;
        }
    }
    for(i = 0; i < n; i++) {
        if(!selected[i] && dist[i] < dist[v]) v = i;
    }
    return v;
}

void prim(int start, int n) {

    for(int i = 0; i < n; i++) dist[i] = INF;

    dist[start] = 0;
    for(int i = 0; i < n; i++) {
        int node = getMinVertex(n);
        selected[node] = true;
        if(dist[node] == INF) return;
        cout << node << ' ';

        for(int j = 0; j < n; j++) {
            if(weight[node][j]!=INF) {
                if(!selected[j] && weight[node][j] < dist[j])
                    dist[j] = weight[node][j];
            }
        }
    }
}

int main(void) {
    prim(0, NUM);
    return 0;
}