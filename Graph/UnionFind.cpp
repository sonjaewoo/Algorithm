/*
Union-Find (합집합 찾기)
- 여러 개의 노드가 존재할 때 두 개의 노드를 선택해서, 현재 이 두 노드가 서로 같은 그래프에 속하는지 판별
*/

#include <iostream>

using namespace std;

//부모 노드를 찾는 함수
int getParent(int parent[], int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]); //재귀적으로 부모를 찾음
}

//두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a; // 더 작은 값으로 부모 노드 값을 통일
    else parent[a] = b;
}

//같은 부모를 가지는지 확인
bool findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return true;
    else return false;
}

int main(void) {

    int parent[11];
    for(int i = 1; i <= 10; i++) {
        parent[i] = i;
    }

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    cout << "Does 1 and 5 connected? : " << findParent(parent, 1, 5) << '\n';

    return 0;
}