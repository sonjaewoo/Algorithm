/*
시간복잡도 항상 보장 = O(NlogN)
높이 = logN, 너비 = N

정렬이 되어 있는 나눠진 배열을 합치면서 다시 정렬
*/

#include <iostream>
using namespace std;

int a[] = {7,6,5,8,3,2,9,1,4};
int number;
int sorted[10];

void merge(int m, int middle, int n) {
    int i = m;
    int j = middle+1;
    int k = m;

    while(i <= middle && j <= n) {
        if(a[i] < a[j]) {
            sorted[k] = a[i];
            i++;
        }
        else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    if(i > middle) {
        for(int t = j; t <= n; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    else {
        for(int t = i; t <= middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    for(int t = m; t <= n; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int m, int n) {
    if(m < n) { //더 나눌 수 있을 때 까지 (한개가 될 때까지)
        int middle = (m+n) / 2;

        //항상 반으로 나눠서 각각 정렬한다.
        mergeSort(m, middle);
        mergeSort(middle+1, n);

        //새로운 배열에다가 정렬된 두 배열을 순서에 맞게 병합한다.
        merge(m, middle, n);
    }
}

int main(void) {

    number = sizeof(a) / sizeof(int);

    mergeSort(0, number-1);

    for(int i = 0; i < number; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}