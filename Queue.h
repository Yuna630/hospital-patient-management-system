#ifndef QUEUE_H_
#define QUEUE_H_
#include "Node.h"
template <typename T>
class Queue { // FIFO先入れ先出し一番最初に入れたのが先に出される
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    ~Queue();
    Queue<T>() = default;
    // add_back()
    void enqueue(const T& data);
    void dequeue(); // remove_front()
    Node<T>* getHead() { return head; }
    void display(std::ostream& strm) const;
};

template <typename T>
Queue<T>::~Queue() { // デストラクタ
    while(head){
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& data) { // add_back
    Node<T>* newNode = new Node<T>(data);
    if(!head)
        head = tail = newNode;
    else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <typename T>
void Queue<T>::dequeue() { // remove_front
    if (head != nullptr) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}

template <typename T>
void Queue<T>::display(std::ostream& strm) const {
    Node<T>* curr = head;
    while(curr) {
        strm << curr->getData() << " ";
        curr = curr->getNext();
    }
    strm << std::endl;
}
#endif