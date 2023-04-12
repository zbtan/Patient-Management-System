#ifndef MEDICALRFUNCTION_H
#define MEDICALRFUNCTION_H

#include"MedicalReport.h"

class MedicalRFunction
{
public:
	int addMedicalReport(MedicalReport* medicalreport);
	int updateMedicalReport(MedicalReport* medicalreport);
	int updateMedicalReportCondition(MedicalReport* medicalreport);
	int updateMedicalReportTest(MedicalReport* medicalreport);
	int deleteMedicalReport(MedicalReport* medicalreport);
	MedicalReport* getMedicalReport(string medicalrid);
	MedicalReport* getMedicalReports();
	MedicalReport* getMedicalReportID();

};
#endif // !MEDICALRFUNCTION_H
