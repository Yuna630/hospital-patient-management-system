#ifndef ER_H_
#define ER_H_
#include <string>
#include "SeverePatient.h"
#include "Queue.h"

/*
救急外来の待機列を表す。内部で Queue<T>を使い
到着順（FIFO） に患者を処理。
*/
template <typename T>
class ER {
private:
    std::string name;
    Queue<T> patient; // Queue to manage patients 先に入った患者を先に（待機列）
public:
    ER() : name("Unnamed ER") {}
    ER(std::string n) : name(n) {}
    void addPatient(const T& p) { // enqueue 末尾に追加
        patient.enqueue(p);
    }
    void processPatient() { // dequeue 先頭から処理
        patient.dequeue();
    }
    void display(std::ostream& strm) const {
        patient.display(strm);
    }   
};
#endif