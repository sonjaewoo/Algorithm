#include <iostream>

using namespace std;

int number = 15;

// 하나의 노드 정보
typedef struct node *treePointer; // node를 포인터 형식으로 사용
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

void preorder(treePointer ptr) {
    if(ptr) {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void inorder(treePointer ptr) {
    if(ptr) {
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr) {
    if(ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data;
    }
}

int main(void) {
    node nodes[number + 1]; //배열

    for(int i = 1; i <= number; i++) { // data에 값 입력, 연결부분은 아직 NULL
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    for(int i = 1; i <= number; i++) { // 
        if(i%2 == 0)
            nodes[i/2].leftChild = &nodes[i]; // 자기 부모의 왼쪽 자식 노드로
        else
            nodes[i/2].rightChild = &nodes[i]; // 자기 부모의 오른쪽 자식 노드로
    }

    inorder(&nodes[1]);
    return 0;
}
