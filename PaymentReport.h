#ifndef PAYMENTREPORT_H
#define PAYMENTREPORT_H

#include<string>
using namespace std;

class PaymentReport {
public:
	string paymentid;
	string datetime;
	double totalprice;
	double totalpayment;
	double totalchange;
	string patientid;
	string medicalinid;
	PaymentReport* next;
};
#endif // !PAYMENTREPORT_H
