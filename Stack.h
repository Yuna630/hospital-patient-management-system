#ifndef STACK_H_
#define STACK_H_
#include "Node.h"
template <typename T>
class Stack { // LIFO後入れ先出し一番最後に入れたのが先に出される
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    Stack<T>() = default;
    ~Stack();

    // add_front()
    void push(const T& data);

    // remove_front()
    void pop();
    Node<T>* getHead() { return head; }
    void display(std::ostream& strm) const;
    T peek() const;    
    bool isEmpty() { return head == nullptr; }
};

template <typename T>
Stack<T>::~Stack() {
    while(head){
        pop(); // headを更新していくのでpopでOK<<先頭から削除
    }
}

template <typename T>
void Stack<T>::push(const T& data) { // add_front
    Node<T>* newNode = new Node<T>(data);
    if(!head)
        head = tail = newNode; 
    else {
        newNode->setNext(head);
        head = newNode;
    }
}

template <typename T>
void Stack<T>::pop() { // remove_front
    Node<T>* temp = head;
    head = temp->getNext();
    delete temp;
}

template <typename T>
T Stack<T>::peek() const { // 先頭のデータを返す
    if (head) {
        return head->getData();
    }
    throw std::runtime_error("Stack is empty"); // スタックが空の場合のエラーハンドリング
}

template <typename T>
void Stack<T>::display(std::ostream& strm) const{
    Node<T>* curr = head;
    while(curr) {
        strm << curr->getData() << " ";
        curr = curr->getNext();
    }
    strm << std::endl;
}

#endif