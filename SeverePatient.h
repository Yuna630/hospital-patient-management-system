#ifndef SEVEREPATIRNT_H_
#define SEVEREPATIRNT_H_
#include "Patient.h"

class SeverePatient : public Patient { // SeverePatientはPatientを継承
private:
    int severity; // 重症度を表す追加の属性
public:
    SeverePatient() = default;
    SeverePatient(char* n, int i, int s) : Patient(n,i), severity(s){} // コンストラクタ(int severityで重症度を追加)
    void display(std::ostream& strm) const override {
        Patient::display(strm);
        strm << "Severity: " << severity << std::endl;
    }
    int getSeverity() { return severity; }
};
std::ostream& operator<<(std::ostream& strm, const SeverePatient& s) {
    s.display(strm);
    return strm;
}
#endif 