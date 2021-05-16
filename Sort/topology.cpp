/*
위상 정렬 (여러 가지 조건이 결합된 그래프 상에서의 경로를 찾기위한 알고리즘)
- 순서가 정해져있는 작업을 차례로 수행해야 할 때 
- DAG (Directed Acyclic Graph)에만 적용 가능
- 진입 차수 = 해당 노드로 들어오는 간선의 수 (조건의 수)
- 시간 복잡도 = O(V + E) 
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX]; //진입 차수
vector<int> a[MAX];

void topologySort() {
    int result[MAX];
    queue<int> q;

    //진입 차수가 0인 노드를 큐에 삽입
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) q.push(i);
    }
    
    //위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문해야 함
    for(int i = 1; i <= n; i++) {
        //n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것
        if(q.empty()) {
            cout << "Cycle" << '\n';
            return;
        }
        int x = q.front(); //큐에서 꺼낸 순서가 위상 정렬의 순서
        q.pop();
        result[i] = x;
        for(int i = 0; i < a[x].size(); i++) {
            int y = a[x][i]; //연결되어 있는 모든 간선을 제거한다.

            if(--inDegree[y] == 0) { //제거했을 때 진입차수가 0이라면 큐에 삽입
                q.push(y);
            }  
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
}

int main(void) {
    n = 7;
    a[1].push_back(2);
    inDegree[2]++;

    a[1].push_back(5);
    inDegree[5]++;

    a[2].push_back(3);
    inDegree[3]++;

    a[3].push_back(4);
    inDegree[4]++;

    a[4].push_back(6);
    inDegree[6]++;

    a[5].push_back(6);
    inDegree[6]++;

    a[6].push_back(7);
    inDegree[7]++;
    
    topologySort();
    return 0;
}
