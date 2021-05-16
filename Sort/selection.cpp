/*
선택정렬
시간복잡도 = O(N^2)
*/

#include <iostream>
using namespace std;

int a[] = {1,5,4,3,6,8,7,9,2,10};
int i, j, temp, idx, num;

void selectionSort() {
    for(i = 0; i < num; i++) {
        int min = 987654321;
        for(j = i; j < num; j++) {
            if(a[j] < min) {
                min = a[j];
                idx = j;
            }
        }
        temp = a[i]; //swap
        a[i] = a[idx];
        a[idx] = temp;
    }
}

int main(void) {

    num = sizeof(a) / sizeof(int);

    selectionSort();

    for(int i = 0; i < num; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}