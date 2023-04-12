#include"Doctor.h"

#ifndef DOCTORFUNCTION_H
#define DOCTORFUNCTION_H


class DoctorFunction
{
public:
	Doctor* getDoctorI(string doctorid);
	Doctor* getDoctorN(string name);
	Doctor* getDoctors();
	bool loginDoc(string id, string password);

};
#endif // !DOCTORFUNCTION_H
