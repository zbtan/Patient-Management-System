#ifndef MEDICATIONFUNCTION_H
#define MEDICATIONFUNCTION_H

#include"Medication.h"
class MedicationFunction
{
public:
	int addMedication(Medication* medication);
	int updateMedication(Medication* medication);
	int updateMedicationName(Medication* medication);
	int updateMedicationDetail(Medication* medication);
	int updateMedicationUnit(Medication* medication);
	int updateMedicationPrice(Medication* medication);
	int deleteMedication(Medication* medication);
	Medication* getMedication(string medicationid);
	Medication* getMedications();
	Medication* getMedicationID();
};
#endif // !MEDICATIONFUNCTION_H

