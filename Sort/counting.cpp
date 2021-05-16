/*
'범위 조건'이 있는 경우에 한해서 굉장히 빠름 = O(N)

크기를 기준으로 갯수만 세주면 되기 때문에 위치를 바꿀 필요가 없음

모든 데이터에 한 번씩만 접근하면 된다는 점에서 효율적임!
*/

#include <iostream>
using namespace std;

int array[] = {
        1,3,2,4,3,2,5,3,1,2,
        3,4,4,3,5,1,2,3,5,2,
        3,1,4,3,5,1,2,1,1,1
        };

void countingSort() {
    
    int count[5] = {0};
    for(int i = 0; i < 30; i++) {
        count[array[i]]++;
    }

    for(int i = 1; i <= 5; i++) { // N
        if(count[i] != 0){
            for(int j = 0; j < count[i]; j++) { // N
                cout << i << ' ';
            }
        }
    }
}

int main(void) {

    countingSort();

    return 0;
}