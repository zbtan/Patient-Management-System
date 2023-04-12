#ifndef APPOINTMENTFUNCTION_H
#define APPOINTMENTFUNCTION_H

#include"Appointment.h"

class AppointmentFunction
{
public:
	int addAppointment(Appointment* appointment);
	int updateAppointment(Appointment* appointment);
	int updateAppointmentDate(Appointment* appointment);
	int updateAppointmentPatient(Appointment* appointment);
	int updateAppointmentDoctor(Appointment* appointment);
	int deleteAppointment(Appointment* appointment);
	Appointment* getAppointmentA(string appointmentid);
	Appointment* getAppointmentP(string patientid);
	Appointment* getAppointments();
	Appointment* getAppointmentsDoc(string doctorid);
	Appointment* getAppointmentID();
};
#endif // !APPOINTMENTFUNCTION_H
