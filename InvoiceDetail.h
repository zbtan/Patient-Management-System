#ifndef INVOICEDETAIL_H
#define INVOICEDETAIL_H

#include<string>
using namespace std;

class InvoiceDetail {
public:
	string medicalindeid;
	int quantityrequired;
	string medicalinid;
	string medicationid;
	InvoiceDetail* next;

};
#endif // !INVOICEDETAIL_H
