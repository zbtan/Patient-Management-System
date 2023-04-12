#ifndef INVOICEDETAILFUNCTION_H
#define INVOICEDETAILFUNCTION_H

#include"InvoiceDetail.h"


class InvoiceDetailFunction {
public:
	int addInvoiceDetail(InvoiceDetail* invoicedetail);
	int updateInvoiceDetail(InvoiceDetail* invoicedetail);
	int updateInvoiceDetailMedicine(InvoiceDetail* invoicedetail);
	int deleteInvoiceDetail(InvoiceDetail* invoicedetail);
	InvoiceDetail* getInvoiceDetail(string medicalindeid);
	InvoiceDetail* getInvoiceDetails();
	InvoiceDetail* getInvoiceDetailID();
	InvoiceDetail* getInvoiceDetailMI(string medicalinid);

};
#endif // !INVOICEDETAILFUNCTION_H

