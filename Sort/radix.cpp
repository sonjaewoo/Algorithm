/*
기수 정렬은 자리수부터 비교하여 정렬해 가는 것
비교 연산을 하지 않으며 정렬 속도가 빠르지만 데이터 전체 크기에 기수 테이블의 크기만한 메모리 더 필요

'버킷'이라는 작지 않은 용량의 추가적인 메모리 공간이 필요한 것이 최대의 단점!

시간복잡도 = O(N)

1의 자리부터 배열, 10의 자리 배열 ..
*/

#include <iostream>
#include <queue>
#define size 8
using namespace std;

int data[] = {15,27,64,25,50,17,39,28};
queue<int> q[100];

int max_value() {
    int num = 0;
    for(int i = 0; i < 8; i++) {
        num = max(num, data[i]); 
    }
    return num;
}

void radixSort() {
    int radix = 1;  // 최대 자릿수
    while(1) {
        if(radix >= max_value()) break;
        radix *= 10; 
    }

    for(int i = 1; i < radix; i *= 10) { // i = 1, 10, 100, 1000 ...
        for(int j = 0; j < size; j++) {
            int k = 0;
            if(data[j] < i) k = 0;
            else k = (data[j] / i) % 10;
            q[k].push(data[j]);
        }
        int idx = 0;
        for(int j = 0; j < 10; j++) {
            while(!q[j].empty()) {
                data[idx] = q[j].front();
                q[j].pop();
                idx++;
            }
        }
    }
}

int main(void) {
    radixSort();

    for(int i = 0; i < size; i++) {
        cout << data[i] << ' ';
    }
    return 0;
}