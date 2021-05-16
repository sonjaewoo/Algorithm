/*
시간 복잡도
= Heapify + N번의 DownHeap(순서 조건을 만족하게 만드는 과정)
= O(N) + O(NlogN) = O(NlogN)

완전 이진 트리를 기반으로 함, heapify는 사실 n/2부터 인덱스 0까지 해도 됨.  

- 최대 힙을 만드는 과정에서 최악의 경우 O(트리의 높이) 만큼 내려올 수 있음 
- Heapify : 아래 자식이 없다면 pass. 그래서 n/2부터 하는 듯. Look downwards! 아래 부분만 heapify
*/

#include <iostream>

using namespace std;

int number = 9;
int heap[] = {7,6,5,8,3,4,9,1,2};

void heapify(int i) { // 최대 힙을 구성하는 과정, 한번 heapify = O(logN)
    int c = i;
    do {
        int root = (c-1) / 2;
        if(heap[root] < heap[c]) swap(heap[root], heap[c]);
    
        c = root;
    } while(c != 0); // c가 트리의 루트 위치까지 올라감
}

void heapsort(int i) {
    swap(heap[0], heap[i]); // 가장 큰 값을 맨 뒤로 

    int root = 0;
    int c = 1;
    do {
        c = 2*root + 1;
        if(c < i-1 && heap[c] < heap[c+1]) c++; // 자식 중에 더 큰 값 찾기
        if(c < i && heap[root] < heap[c]) swap(heap[root], heap[c]);
        root = c; // 밑으로 내려감
    } while(c < i);
}

int main(void) {
    
    for(int i = 1; i < number; i++) { 
        heapify(i);
    }
/*
일반적으로는 O(NlogN)이라고 한다.
하지만, 실제로는 노드의 절반만 heapify 진행해도 되니 (1/2 * N) * logN = O(N)이다.
*/ 

    for(int i = number-1; i >= 0; i--) {
        heapsort(i);
    }
// Heapify를 n번만큼 수행 = O(NlogN)

    for(int i = 0; i < number; i++) {
        cout << heap[i] << ' ';
    }
    return 0;
}
