/*
시간 복잡도 = O(NlogN)
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int node, edge;
vector<pair<int, int> > v[10];
int d[10]; //distance

void dijkstra(int start) {
    d[start] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start, 0));

    while(!pq.empty()) {
        int currentnode = pq.top().first;
        int currentdistance = -pq.top().second; // 우선순위 큐를 역 이용하는 방법
        pq.pop();

        for(int i = 0; i < v[currentnode].size(); i++) {
            int nextnode = v[currentnode][i].first;
            int nextdistance = v[currentnode][i].second;
            //nextnode = currentnode의 인접한 node
            //nextdistance = currentnode에서 nextnode까지 간선의 비용

            if(currentdistance + nextdistance < d[nextnode]) {
                //d[nextnode]보다 d[currentnode] + nextdistance가 더 클 경우
                d[nextnode] = currentdistance + nextdistance;
                pq.push(make_pair(nextnode, -d[nextnode]));
            }
        }
    }
}

int main(void) {

    node = 5;
    edge = 8;

    for(int i = 1; i <= node; i++) {
        d[i] = INF;
    }

    for(int i = 0; i < edge; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        v[a].push_back(make_pair(b, c));
    }
/*
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3 */

    int start, end;
    cin >> start >> end; //1 5

    dijkstra(start);

    cout << d[end];

    return 0;
}