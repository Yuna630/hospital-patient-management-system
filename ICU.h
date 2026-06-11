#ifndef ICU_H_
#define ICU_H_
#include "Stack.h"
#include "SeverePatient.h"
#include <string>
/*
集中治療室の入室管理。内部で Stack<T> を使い、
最後に入った患者から（LIFO） 処理。
緊急の再処置・直近観察対象を優先するモデル。
*/

template <typename T>
class ICU {
private:
    std::string name; // ICUの名前
    Stack<T> patientStack;
public:
    ICU() : name("Unnamed ICU") {}
    ICU(const std::string& icuName) : name(icuName) {} // コンストラクタ
    void addPatient(const T& patient) {
        patientStack.push(patient); // ICUに新しい患者を追加。Stackの一番上に積む。
    }
    void processPatient() { // 最後に追加された患者を処理
        // peek() で一番上の患者を確認して表示し、pop() で取り除く
        if (!patientStack.isEmpty()) {
            std::cout << "Processing patient: " << patientStack.peek() << std::endl;
            patientStack.pop();
        } else {
            std::cout << "No patients to process.\n";
        }
    }
    void displayPatients(std::ostream& strm) const {
        patientStack.display(strm);  // Stack 側に display() が必要
    }
};
#endif