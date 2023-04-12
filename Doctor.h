#ifndef DOCTOR_H
#define DOCTOR_H

#include<string>
using namespace std;

class Doctor
{
public:
	string doctorid;
	string name;
	string gender;
	string contactnumber;
	string email;
	string expertisefield;
	string adminid;
	Doctor* next;
	
};
#endif // !DOCTOR_H
