#ifndef MEDICALREPORT_H
#define MEDICALREPORT_H

#include<string>
using namespace std;

class MedicalReport
{
public:
	string medicalrid;
	string datetime;
	string medicalcondition;
	string testresult;
	string patientid;
	string doctorid;
	MedicalReport* next;

};
#endif // !MEDICALREPORT_H

