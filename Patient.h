#ifndef PATIENT_H_
#define PATIENT_H_
#include <iostream>
#include <cstring>
// Base
class Patient { //患者の基本情報（名前とID）を持つBaseクラス　（SeverePatientがderived class）
protected:
    char name[20];
    int id = 0;
public:
    Patient() = default;
    virtual ~Patient() = default; //ポインタ経由で親クラスを削除したときに、子クラスのデストラクタも正しく呼ばれるようにするため
    Patient(char* inputName, int inputId); // コンストラクタ
    Patient( const Patient& other); // コピーコンストラクタ
    Patient& operator=(const Patient& other); // コピー代入演算子
    char* getName() { return name;}
    int getId() { return id;}
    virtual void display(std::ostream& strm) const {
        strm << "Name: " << name << ", ID: " << id << std::endl;
    }
};
/*
std::ostream& operator<<(std::ostream& strm, Patient& p) {
    p.display(strm);
    return strm;
}
*/

#endif