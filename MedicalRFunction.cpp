#include"DatabaseConnection.h"
#include"MedicalRFunction.h"

void transform(sql::ResultSet* rs, MedicalReport* medicalreport)
{
	medicalreport->medicalrid = rs->getString("MEDICALR_ID");
	medicalreport->datetime = rs->getString("DATE_TIME");
	medicalreport->medicalcondition = rs->getString("MEDICAL_CONDITION_DESCRIPTION");
	medicalreport->testresult = rs->getString("TEST_RESULT");
	medicalreport->patientid = rs->getString("PATIENT_ID");
	medicalreport->doctorid = rs->getString("DOCTOR_ID");
}

int MedicalRFunction::addMedicalReport(MedicalReport* medicalreport)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO medical_report (MEDICALR_ID, DATE_TIME, MEDICAL_CONDITION_DESCRIPTION, TEST_RESULT, PATIENT_ID, DOCTOR_ID) VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, medicalreport->medicalrid);
	ps->setString(2, medicalreport->datetime);
	ps->setString(3, medicalreport->medicalcondition);
	ps->setString(4, medicalreport->testresult);
	ps->setString(5, medicalreport->patientid);
	ps->setString(6, medicalreport->doctorid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicalRFunction::updateMedicalReport(MedicalReport* medicalreport)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medical_report SET DATE_TIME = ?, MEDICAL_CONDITION_DESCRIPTION = ?, TEST_RESULT = ?, PATIENT_ID = ? , DOCTOR_ID = ? WHERE MEDICALR_ID = ?");

	ps->setString(1, medicalreport->datetime);
	ps->setString(2, medicalreport->medicalcondition);
	ps->setString(3, medicalreport->testresult);
	ps->setString(4, medicalreport->patientid);
	ps->setString(5, medicalreport->doctorid);
	ps->setString(6, medicalreport->medicalrid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicalRFunction::updateMedicalReportCondition(MedicalReport* medicalreport) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medical_report SET MEDICAL_CONDITION_DESCRIPTION = ? WHERE MEDICALR_ID = ?");

	ps->setString(1, medicalreport->medicalcondition);
	ps->setString(2, medicalreport->medicalrid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicalRFunction::updateMedicalReportTest(MedicalReport* medicalreport) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medical_report SET TEST_RESULT = ? WHERE MEDICALR_ID = ?");

	ps->setString(1, medicalreport->testresult);
	ps->setString(2, medicalreport->medicalrid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicalRFunction::deleteMedicalReport(MedicalReport* medicalreport)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM medical_report WHERE MEDICALR_ID = ?");

	ps->setString(1, medicalreport->medicalrid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

MedicalReport* MedicalRFunction::getMedicalReport(string medicalrid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_report WHERE MEDICALR_ID = ?");

	ps->setString(1, medicalrid);

	sql::ResultSet* rs = ps->executeQuery();
	MedicalReport* medicalreport = NULL;

	if (rs->next())
	{
		medicalreport = new MedicalReport();
		transform(rs, medicalreport);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medicalreport;
}

MedicalReport* MedicalRFunction::getMedicalReports()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_report");
	sql::ResultSet* rs = ps->executeQuery();
	MedicalReport* medicalreport = NULL;
	MedicalReport* head = NULL;

	while (rs->next())
	{
		if (medicalreport == NULL)
		{
			medicalreport = new MedicalReport();
			head = medicalreport;
		}
		else
		{
			medicalreport->next = new MedicalReport();
			medicalreport = medicalreport->next;
		}

		transform(rs, medicalreport);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

MedicalReport* MedicalRFunction::getMedicalReportID()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_report ORDER BY MEDICALR_ID DESC LIMIT 1");
	sql::ResultSet* rs = ps->executeQuery();
	MedicalReport* medicalreport = NULL;

	if (rs->next())
	{
		medicalreport = new MedicalReport();
		medicalreport->medicalrid = rs->getString("MEDICALR_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medicalreport;
}