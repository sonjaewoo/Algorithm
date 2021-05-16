 /*
삽입정렬
Best case : 이미 오름차순으로 정렬되어 있는 배열, 전부다 else break;에 걸려서 O(N)을 만족함.
Worst case : 역순으로 정렬되어 있는 배열 
*/

#include <iostream>

using namespace std;

int a[] = {9,7,8,4,6,5,1,3,2};
int size, data, i,j;

void insertionsort() {
    for(i = 1; i < size; i++) {
        data = a[i];
        for(j = i-1; j >= 0; j--) {
            if(a[j] > data) a[j+1] = a[j];
            else break;
        }
        a[j+1] = data;
    }
}

void insertionsort_n() {
    for(i = 0; i < size-1; i++) {
        j = i; //정렬할 원소
        while(a[j] > a[j+1] && j >= 0) {
            swap(a[j], a[j+1]);
            j--;
        }
    }
}

int main(void) {
    size = sizeof(a) / sizeof(int);

    insertionsort_n();
    for(int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}