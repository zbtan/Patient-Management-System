#include"DatabaseConnection.h"
#include"AppointmentFunction.h"

void transform(sql::ResultSet* rs, Appointment* appointment)
{
	appointment->appointmentid = rs->getString("APPOINTMENT_ID");
	appointment->datetime = rs->getString("DATE_TIME");
	appointment->patientid = rs->getString("PATIENT_ID");
	appointment->doctorid = rs->getString("DOCTOR_ID");
	appointment->adminid = rs->getString("ADMIN_ID");
}

int AppointmentFunction::addAppointment(Appointment* appointment)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO appointment_list (APPOINTMENT_ID, DATE_TIME, PATIENT_ID, DOCTOR_ID, ADMIN_ID) VALUES (?, ?, ?, ?, ?)");

	ps->setString(1, appointment->appointmentid);
	ps->setString(2, appointment->datetime);
	ps->setString(3, appointment->patientid);
	ps->setString(4, appointment->doctorid);
	ps->setString(5, appointment->adminid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int AppointmentFunction::updateAppointment(Appointment* appointment)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE appointment_list SET DATE_TIME = ?, PATIENT_ID = ?, DOCTOR_ID = ?, ADMIN_ID = ? WHERE APPOINTMENT_ID = ?");

	ps->setString(1, appointment->datetime);
	ps->setString(2, appointment->patientid);
	ps->setString(3, appointment->doctorid);
	ps->setString(4, appointment->adminid);
	ps->setString(5, appointment->appointmentid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int AppointmentFunction::updateAppointmentDate(Appointment* appointment)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE appointment_list SET DATE_TIME = ?, ADMIN_ID = ? WHERE APPOINTMENT_ID = ?");

	ps->setString(1, appointment->datetime);
	ps->setString(2, appointment->adminid);
	ps->setString(3, appointment->appointmentid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int AppointmentFunction::updateAppointmentPatient(Appointment* appointment)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE appointment_list SET PATIENT_ID = ?, ADMIN_ID = ? WHERE APPOINTMENT_ID = ?");

	ps->setString(1, appointment->patientid);
	ps->setString(2, appointment->adminid);
	ps->setString(3, appointment->appointmentid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int AppointmentFunction::updateAppointmentDoctor(Appointment* appointment)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE appointment_list SET DOCTOR_ID = ?, ADMIN_ID = ? WHERE APPOINTMENT_ID = ?");

	ps->setString(1, appointment->doctorid);
	ps->setString(2, appointment->adminid);
	ps->setString(3, appointment->appointmentid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int AppointmentFunction::deleteAppointment(Appointment* appointment)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM appointment_list WHERE APPOINTMENT_ID = ?");

	ps->setString(1, appointment->appointmentid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

Appointment* AppointmentFunction::getAppointmentA(string appointmentid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM appointment_list WHERE APPOINTMENT_ID = ?");

	ps->setString(1, appointmentid);

	sql::ResultSet* rs = ps->executeQuery();
	Appointment* appointment = NULL;

	if (rs->next())
	{
		appointment = new Appointment();
		transform(rs, appointment);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return appointment;
}

Appointment* AppointmentFunction::getAppointmentP(string patientid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM appointment_list WHERE PATIENT_ID = ?");

	ps->setString(1, patientid);

	sql::ResultSet* rs = ps->executeQuery();
	Appointment* appointment = NULL;

	if (rs->next())
	{
		appointment = new Appointment();
		transform(rs, appointment);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return appointment;
}

Appointment* AppointmentFunction::getAppointments()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM appointment_list");
	sql::ResultSet* rs = ps->executeQuery();
	Appointment* appointment = NULL;
	Appointment* head = NULL;

	while (rs->next())
	{
		if (appointment == NULL)
		{
			appointment = new Appointment();
			head = appointment;
		}
		else
		{
			appointment->next = new Appointment();
			appointment = appointment->next;
		}

		transform(rs, appointment);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

Appointment* AppointmentFunction::getAppointmentsDoc(string doctorid) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM appointment_list WHERE DOCTOR_ID = ? ORDER BY DATE_TIME ASC");

	ps->setString(1, doctorid);

	sql::ResultSet* rs = ps->executeQuery();
	Appointment* appointment = NULL;
	Appointment* head = NULL;

	while (rs->next())
	{
		if (appointment == NULL)
		{
			appointment = new Appointment();
			head = appointment;
		}
		else
		{
			appointment->next = new Appointment();
			appointment = appointment->next;
		}

		transform(rs, appointment);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

Appointment* AppointmentFunction::getAppointmentID()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM appointment_list ORDER BY APPOINTMENT_ID DESC LIMIT 1");
	sql::ResultSet* rs = ps->executeQuery();
	Appointment* appointment = NULL;
	
	if (rs->next())
	{
		appointment = new Appointment();
		appointment->appointmentid = rs->getString("APPOINTMENT_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return appointment;
}