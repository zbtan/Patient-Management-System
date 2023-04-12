#ifndef MEDICATION_H
#define MEDICATION_H

#include<string>
using namespace std;

class Medication 
{
public:
	string medicationid;
	string name;
	string detail;
	string unit;
	int uPrice;
	string adminid;
	Medication* next;

};
#endif // !MEDICATION_H
