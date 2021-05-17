#include <iostream>
#include <algorithm>
using namespace std;

int num, target;
int a[] = {1,5,4,3,6,8,7,9,2,10};

int binarySearch(int size, int target) {
    int start = 0;
    int end = size - 1;

    if(start <= end) {
        int middle = (start + end) / 2;
        if(a[middle] == target) return middle;
        else if(a[middle] > target) end = middle - 1;
        else start = middle + 1;
    } 
    return -1;
}

int main(void) {

    num = sizeof(a) / sizeof(int); 

    target = 7;

    sort(a, a + num);

    cout << binarySearch(num, target);

    return 0;
}