#ifndef NODE_H_
#define NODE_H_
#include <iostream>

template <class T> // どんなデータ型にも対応できるようにテンプレート化
class Node {
private:
    T data; // データ部分
    Node<T>* next = nullptr; // 次のノードへのポインタ
public:
    Node(T d) : data(d), next(nullptr) {} // コンストラクタ
    T getData() { return data;}
    Node* getNext() { return next; }
    void setData(T d) { data = d; } // データ設定用セッター
    void setNext(Node* n) { next = n; }
};
#endif