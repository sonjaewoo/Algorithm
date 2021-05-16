/*
버블 정렬
시간 복잡도 = O(N^2)
*/
#include <iostream>
using namespace std;

int i, j, temp, num;
int a[] = {1,5,4,3,6,8,7,9,2,10};

void bubbleSort() {

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num-1-i; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(void) {

    num = sizeof(a) / sizeof(int); 

    bubbleSort();

    for(int i = 0; i < num; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}