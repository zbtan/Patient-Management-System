#ifndef INVOICEFUNCTION_H
#define INVOICEFUNCTION_H

#include"MedicalInvoice.h"

class InvoiceFunction {
public:
	int addInvoice(MedicalInvoice* medicalinvoice);
	int updateInvoice(MedicalInvoice* medicalinvoice);
	int updateInvoicePrice(MedicalInvoice* medicalinvoice);
	int deleteInvoice(MedicalInvoice* medicalinvoice);
	MedicalInvoice* getInvoice(string medicalinid);
	MedicalInvoice* getInvoices();
	MedicalInvoice* getInvoiceID();
	MedicalInvoice* getInvoiceRID(string medicalrid);
	MedicalInvoice* getPrice(string medicalinid);
	MedicalInvoice* getOpenInvoice();
	MedicalInvoice* getCloseInvoice();
};
#endif // !INVOICEFUNCTION_H

