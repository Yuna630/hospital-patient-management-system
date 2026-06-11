#include <iostream>
#include "ICU.h"
#include "ER.h"
#include "SeverePatient.h"

int main() {
    ICU<SeverePatient> icu("Critical ICU");
    ER<SeverePatient> er("Emergency Room");

    SeverePatient p1((char*)"Alice", 101, 8);
    SeverePatient p2((char*)"Bob", 102, 5);
    SeverePatient p3((char*)"Cathy", 103, 9);
    SeverePatient p4((char*)"David", 104, 6);

    icu.addPatient(p1);
    icu.addPatient(p2);
    icu.addPatient(p3);
    er.addPatient(p2);
    er.addPatient(p3);
    er.addPatient(p4);

    // Display patients in ICU
    std::cout << "\n--- ICU Patients ---\n";
    icu.displayPatients(std::cout);

    // Display patients in ER
    std::cout << "\n--- ER Patients ---\n";
    er.display(std::cout);

    // Process one patient from each
    std::cout << "\n--- Processing one ICU Patient ---\n";
    icu.processPatient();

    std::cout << "\n--- Processing one ER Patient ---\n";
    er.processPatient();

    // Display again after processing
    std::cout << "\n--- ICU Patients After Processing ---\n";
    icu.displayPatients(std::cout);

    std::cout << "\n--- ER Patients After Processing ---\n";
    er.display(std::cout);

    return 0;
}