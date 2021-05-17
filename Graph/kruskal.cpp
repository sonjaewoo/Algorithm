/*
[크루스칼 알고리즘]

- 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘
- 최소 비용 신장 트리를 만들기 위한 대표적인 알고리즘
- 비용을 오름차순 크기로 하나씩 선택하 되, 사이클 형성을 방지해야 함.
- Always select the minimum cost edge without forming a cycle!!
- 시간 복잡도 = min heap을 사용할 경우 O(ElogV), 아닐 경우 O(N^2)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//부모 노드를 가져옴
int getParent(int parent[], int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

//부모 노드를 병합
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    //더 숫자가 작은 부모로 병합
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

//같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return 1;
    else return 0;
}

//간선 정보를 담는 클래스 선언
class Edge {
public :
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {  //생성자 함수
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator <(Edge &edge) { //거리가 더 짧은 것을 출력하도록 
        return this->distance < edge.distance; 
    }
};

int main(void) {
    int n = 7;
    int m = 11;

    vector<Edge> v; // 간선 정보
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));

    sort(v.begin(), v.end()); // distance를 기준으로 오름차순 정렬

    //각 정점이 포함된 그래프가 어디인지 저장
    int parent[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        //사이클이 발생하지 않는 경우 그래프에 포함
        if(!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)) {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
        }
    }
    cout << sum;

    return 0;
}