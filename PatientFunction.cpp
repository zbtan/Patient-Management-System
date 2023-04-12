#include"DatabaseConnection.h"
#include"PatientFunction.h"

void transform(sql::ResultSet* rs, Patient* patient)
{
	patient->patientid = rs->getString("PATIENT_ID");
	patient->name = rs->getString("NAME");
	patient->gender = rs->getString("GENDER");
	patient->birth = rs->getString("DATE_OF_BIRTH");
	patient->icnumber = rs->getString("IC_NUMBER");
	patient->address = rs->getString("ADDRESS");
	patient->contactnumber = rs->getString("CONTACT_NUMBER");
	patient->econtactnumber = rs->getString("EMERGENCY_CONTACT_NUMBER");
	patient->email = rs->getString("EMAIL");
	patient->adminid = rs->getString("ADMIN_ID");
}

int PatientFunction::addPatient(Patient* patient)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO patient (PATIENT_ID, NAME, GENDER, DATE_OF_BIRTH, IC_NUMBER, ADDRESS, CONTACT_NUMBER, EMERGENCY_CONTACT_NUMBER, EMAIL, ADMIN_ID) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, patient->patientid);
	ps->setString(2, patient->name);
	ps->setString(3, patient->gender);
	ps->setString(4, patient->birth);
	ps->setString(5, patient->icnumber);
	ps->setString(6, patient->address);
	ps->setString(7, patient->contactnumber);
	ps->setString(8, patient->econtactnumber);
	ps->setString(9, patient->email);
	ps->setString(10, patient->adminid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatient(Patient* patient)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET NAME = ?, GENDER = ?, DATE_OF_BIRTH = ?, IC_NUMBER = ?, ADDRESS = ?, CONTACT_NUMBER = ?, EMERGENCY_CONTACT_NUMBER = ?, EMAIL = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->name);
	ps->setString(2, patient->gender);
	ps->setString(3, patient->birth);
	ps->setString(4, patient->icnumber);
	ps->setString(5, patient->address);
	ps->setString(6, patient->contactnumber);
	ps->setString(7, patient->econtactnumber);
	ps->setString(8, patient->email);
	ps->setString(9, patient->adminid);
	ps->setString(10, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientName(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET NAME = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->name);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientGender(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET GENDER = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->gender);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientBirth(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET DATE_OF_BIRTH = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->birth);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientIC(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET IC_NUMBER = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->icnumber);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientAddress(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET ADDRESS = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->address);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientCN(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET CONTACT_NUMBER = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->contactnumber);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientECN(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET EMERGENCY_CONTACT_NUMBER = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->econtactnumber);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::updatePatientEmail(Patient* patient) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE patient SET EMAIL = ?, ADMIN_ID = ? WHERE PATIENT_ID = ?");

	ps->setString(1, patient->email);
	ps->setString(2, patient->adminid);
	ps->setString(3, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PatientFunction::deletePatient(Patient* patient)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM patient WHERE PATIENT_ID = ?");

	ps->setString(1, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

Patient* PatientFunction::getPatient(string patientid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM patient WHERE PATIENT_ID = ?");

	ps->setString(1, patientid);

	sql::ResultSet* rs = ps->executeQuery();
	Patient* patient = NULL;

	if (rs->next())
	{
		patient = new Patient();
		transform(rs, patient);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return patient;
}

Patient* PatientFunction::getPatientI(string icnumber)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM patient WHERE IC_NUMBER = ?");

	ps->setString(1, icnumber);

	sql::ResultSet* rs = ps->executeQuery();
	Patient* patient = NULL;

	if (rs->next())
	{
		patient = new Patient();
		transform(rs, patient);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return patient;
}

Patient* PatientFunction::getPatients()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM patient");
	sql::ResultSet* rs = ps->executeQuery();
	Patient* patient = NULL;
	Patient* head = NULL;

	while (rs->next())
	{
		if (patient == NULL)
		{
			patient = new Patient();
			head = patient;
		}
		else
		{
			patient->next = new Patient();
			patient = patient->next;
		}

		transform(rs, patient);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

Patient* PatientFunction::getPatientID()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM patient ORDER BY PATIENT_ID DESC LIMIT 1");
	sql::ResultSet* rs = ps->executeQuery();
	Patient* patient = NULL;

	if (rs->next())
	{
		patient = new Patient();
		patient->patientid = rs->getString("PATIENT_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return patient;
}
