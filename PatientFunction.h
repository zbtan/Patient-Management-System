#include "Patient.h"

#ifndef PATIENTFUNCTION_H
#define PATIENTFUNCTION_H

class PatientFunction
{
public:
	int addPatient(Patient* patient);
	int updatePatient(Patient* patient);
	int updatePatientName(Patient* patient);
	int updatePatientGender(Patient* patient);
	int updatePatientBirth(Patient* patient);
	int updatePatientIC(Patient* patient);
	int updatePatientAddress(Patient* patient);
	int updatePatientCN(Patient* patient);
	int updatePatientECN(Patient* patient);
	int updatePatientEmail(Patient* patient);
	int deletePatient(Patient* patient);
	Patient* getPatient(string patientid);
	Patient* getPatientI(string icnumber);
	Patient* getPatients();
	Patient* getPatientID();

};

#endif