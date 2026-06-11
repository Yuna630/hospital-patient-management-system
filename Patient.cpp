#include "Patient.h"

Patient::Patient(char* inputName, int inputId) : id(inputId){
    if (strlen(inputName) < 20) {
        strncpy(name, inputName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }
}

// 新しいオブジェクトを作るときに、既存のオブジェクトを使って初期化する
Patient::Patient( const Patient& other) : id(other.id) {
    if (strlen(other.name) < 20) {
        strncpy(name, other.name, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }
}

// すでに存在するオブジェクトに対して、別のオブジェクトの内容を代入する
Patient& Patient::operator=(const Patient& other) {
    if(this != &other) {
        if (strlen(other.name) < 20) {
            strncpy(name, other.name, sizeof(name) - 1);
            name[sizeof(name) - 1] = '\0';
        }
        id = other.id;
    }
    return *this;
}
