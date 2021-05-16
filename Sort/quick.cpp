/*
평균 시간 복잡도 = O(NlogN), 일반적으로는 가장 빠름 
최악 시간 복잡도 = O(N^2)
-> 이미 정렬이 되어 있는 경우(분할 정복의 이점을 활용 못함, 오히려 삽입 정렬을 쓰는게 나음)

특정한 피벗 값을 기준으로 양쪽으로 나누는 정렬 알고리즘

*/

#include <iostream>
using namespace std;

int i, j, temp, num;
int a[] = {1,5,4,3,6,8,7,9,2,10};

void quickSort(int start, int end) {
    if(start >= end) return; //원소가 1개인 경우 그대로 두기

    i = start+1; //정렬 대상의 가장 왼쪽 지점
    j = end; //정렬 대상의 가장 오른쪽 지점
    int pivot = start; //정렬 기준점

    while(i <= j) { //교차되지 않을 때까지 반복
        while(i <= end && a[pivot] >= a[i]) i++;
        // 피봇 값보다 큰 값을 만날 때까지
        while(j > start && a[pivot] <= a[j]) j--;
        // 피봇 값보다 작은 값을 만날 때까지

        if(i > j) { // left와 right가 교차되는 상황
            temp = a[j];
            a[j] = a[pivot];
            a[pivot] = temp;
        }
        else { //엇갈리지 않을 경우
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    //a[j] = 정렬된 부분
    quickSort(start, j-1); // 정렬된 부분 기준으로 왼쪽 부분 quicksort
    quickSort(j+1, end); // 정렬된 부분 기준으로 오른쪽 부분 quicksort
}

int main(void) {

    num = sizeof(a) / sizeof(int); 

    quickSort(0, num-1);

    for(int i = 0; i < num; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}