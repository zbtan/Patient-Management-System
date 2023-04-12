#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include<string>
using namespace std;

class Appointment
{
public:
	string appointmentid;
	string patientid;
	string doctorid;
	string datetime;
	string adminid;
	int duration;
	Appointment* next;

};
#endif // !APPOINTMENT_H
