#ifndef MEDICALINVOICE_H
#define MEDICALINVOICE_H

#include<string>
using namespace std;

class MedicalInvoice {
public:
	string medicalinid;
	double totalprice;
	string patientid;
	string medicalrid;
	int status;
	MedicalInvoice* next;

};
#endif // !MEDICALINVOICE_H

