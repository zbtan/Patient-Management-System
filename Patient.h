#ifndef PATIENT_H
#define PATIENT_H

#include<string>
using namespace std;

class Patient
{
public:
	string patientid;
	string name;
	string gender;
	string birth;
	string icnumber;
	string address;
	string contactnumber;
	string econtactnumber;
	string email;
	string adminid;
	Patient* next;
};

#endif