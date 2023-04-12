#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<iomanip>
#include<cstdio>
#include<conio.h>
#include<Windows.h>
#pragma warning(disable : 4996)

using namespace std;

#include"DatabaseConnection.h"
#include"PatientFunction.h"
#include"DoctorFunction.h"
#include"AdminFunction.h"
#include"AppointmentFunction.h"
#include"MedicalRFunction.h"
#include"MedicationFunction.h"
#include"InvoiceFunction.h"
#include"InvoiceDetailFunction.h"
#include"PaymentFunction.h"
#include"StatisticReport.h"

void AddPatient(string administrator);
void UpdatePatient(string administrator, int choose);
void DeletePatient();
void ReviewPatientByID();
void ReviewPatientByIC();
void ReviewAllPatient();

void ReviewDoctorByID();
void ReviewDoctorByName();
void ReviewAllDoctor();

void ReviewAdministratorByID();
void ReviewAllAdministrator();

void AddAppointment(string administrator);
void UpdateAppointment(string administrator, int choose);
void DeleteAppointment();
void ReviewAppointmentByID();
void ReviewDoctorAppointment(string doctor);
void ReviewAllAppointment();

void AddMedicalReport(string doctor);
void UpdateMedicalReport(string doctor, int choose);
void DeleteMedicalReport();
void ReviewMedicalReportByID();
void ReviewAllMedicalReport();

void AddMedication(string administrator);
void UpdateMedication(string administrator, int choose);
void DeleteMedication();
void ReviewMedicationByID();
void ReviewAllMedication();

void AddMedicalInvoice(string administrator);
void UpdateMedicalInvoice(int choose);
void DeleteMedicalInvoice();
void ReviewOpenInvoice();
void ReviewCloseInvoice();
void ReviewMedicalInvoiceByReportID();
void ReviewMedicalInvoiceByID();
void ReviewAllMedicalInvoice();

void AddInvoiceDetail();
void UpdateInvoiceDetail(int choose);
void DeleteInvoiceDetail();
void ReviewInvoiceDetailByID();
void ReviewAllInvoiceDetail();

void AddPayment();
void UpdatePayment();
void DeletePayment();
void ReviewPaymentByID();
void ReviewAllPayment();

void ReviewGenderStat();
void ReviewMedicineStat();
void ReviewProfitStat(int choose);

const int monthDays[12] = { 31, 59, 90, 120, 151, 181, 212, 243,
273, 304, 334, 365 };
int countLeapYearDays(string date1) {
	int years = stoi(date1.substr(0, 4));
	if (stoi(date1.substr(5, 2)) <= 2)
		years--;
	return ((years / 4) - (years / 100) + (years / 400));
}
int countNoOfDays(string date) {
	long int dayCount1 = (stoi(date.substr(0, 4)) * 365);
	dayCount1 += monthDays[stoi(date.substr(5, 2))];
	dayCount1 += stoi(date.substr(8, 2));
	dayCount1 += countLeapYearDays(date);
	return dayCount1;
}

int main()
{
	char selection;
	string test;
	int choice, num, choose;

	do {
		system("CLS");
		cout << setw(70) << right << "**********PATIENT MANAGEMENT SYSTEM**********" << endl << endl;
		cout << setw(53) << right << "A. ROLE PATIENT" << endl;
		cout << setw(52) << right << "B. ROLE DOCTOR" << endl;
		cout << setw(59) << right << "C. ROLE ADMINISTRATOR" << endl << endl;
		cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
		cout << setw(70) << right << "*********************************************" << endl;
		cout << endl;
		cout << setw(56) << right << "Choose Your Role: ";
		cin >> test;
		cin.ignore();
		test[0] = toupper(test[0]);
		while (test != "A" && test != "B" && test != "C" && test != "0") {
			cout << setw(64) << right << "Invalid value. Please enter again." << endl;
			cout << setw(56) << right << "Choose Your Role: ";
			cin >> test;
			cin.ignore();
			test[0] = toupper(test[0]);
		}

		selection = test[0];

		switch (selection) {
		case 'A':
			do {
				system("CLS");
				cout << setw(70) << right << "*************** ROLE PATIENT ****************" << endl << endl;
				cout << setw(57) << right << "1. REVIEW PATIENT INFO" << endl;
				cout << setw(61) << right << "2. REVIEW APPOINTMENT INFO" << endl;
				cout << setw(60) << right << "3. REVIEW ALL DOCTOR INFO" << endl;
				cout << setw(59) << right << "4. REVIEW MEDICAL REPORT" << endl;
				cout << setw(60) << right << "5. REVIEW MEDICAL INVOICE" << endl;
				cout << setw(53) << right << "6. REVIEW MEDICINE" << endl;
				cout << setw(59) << right << "7. REVIEW PAYMENT REPORT" << endl << endl;
				cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
				cout << setw(70) << right << "*********************************************" << endl;
				cout << endl;
				cout << setw(56) << right << "Choose Your Menu: ";
				cin >> test;
				cin.ignore();
				while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "6" && test != "7" && test != "0") {
					cout << setw(64) << right << "Invalid value. Please enter again." << endl;
					cout << setw(56) << right << "Choose Your Menu: ";
					cin >> test;
					cin.ignore();
				}
				choice = stoi(test);

				switch (choice) {
				case 1:
					do {
						system("CLS");
						ReviewPatientByIC();
						cout << "\nDo you want to continue review patient info? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
						while (test != "Y" && test != "N") {
							cout << "You entered an invalid character. Please enter again. " << endl;
							cout << "Do you want to continue review patient info? (Y/N) ";
							cin >> test;
							test[0] = toupper(test[0]);
						}
						selection = test[0];

					} while (selection == 'Y');
					break;
				case 2:
					do {
						system("CLS");
						ReviewAppointmentByID();
						cout << "\nDo you want to continue review appointment info? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
						while (test != "Y" && test != "N") {
							cout << "You entered an invalid character. Please enter again. " << endl;
							cout << "Do you want to continue review appointment info? (Y/N) ";
							cin >> test;
							test[0] = toupper(test[0]);
						}
						selection = test[0];

					} while (selection == 'Y');
					break;
				case 3:
					do {
						system("CLS");
						ReviewAllDoctor();
						cout << "\nDo you want to continue review all doctor info? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
						while (test != "Y" && test != "N") {
							cout << "You entered an invalid character. Please enter again. " << endl;
							cout << "Do you want to continue review all doctor info? (Y/N) ";
							cin >> test;
							test[0] = toupper(test[0]);
						}
						selection = test[0];

					} while (selection == 'Y');
					break;
				case 4:
					do {
						system("CLS");
						ReviewMedicalReportByID();
						cout << "\nDo you want to continue review medical report info? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
						while (test != "Y" && test != "N") {
							cout << "You entered an invalid character. Please enter again. " << endl;
							cout << "Do you want to continue review medical report info? (Y/N) ";
							cin >> test;
							test[0] = toupper(test[0]);
						}
						selection = test[0];

					} while (selection == 'Y');
					break;
				case 6:
					do {
						system("CLS");
						ReviewMedicationByID();
						cout << "\nDo you want to continue review medication info? (Y/N)  ";
						cin >> test;
						cin.ignore();
						test[0] = toupper(test[0]);
						cout << endl;
						while (test != "Y" && test != "N")
						{
							cout << "You entered an invalid character. Please enter again." << endl;
							cout << "Do you want to continue review medication info? (Y/N)  ";
							cin >> test;
							cin.ignore();
							test[0] = toupper(test[0]);
							cout << endl;
						}
						selection = test[0];

					} while (selection == 'Y');
					break;
				case 5:
					do {
						system("CLS");
						ReviewMedicalInvoiceByReportID();
						cout << "\nDo you want to continue review medical invoice? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
						while (test != "Y" && test != "N") {
							cout << "You entered an invalid character. Please enter again. " << endl;
							cout << "Do you want to continue review medical invoice? (Y/N) ";
							cin >> test;
							test[0] = toupper(test[0]);
						}
						selection = test[0];

					} while (selection == 'Y');
					break;
				case 7:
					do {
						system("CLS");
						ReviewPaymentByID();
						cout << "\nDo you want to continue review payment report? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
						while (test != "Y" && test != "N") {
							cout << "You entered an invalid character. Please enter again. " << endl;
							cout << "Do you want to continue review payment report? (Y/N) ";
							cin >> test;
							test[0] = toupper(test[0]);
						}
						selection = test[0];

					} while (selection == 'Y');
					break;
				}
			} while (choice != 0);
			break;
		case 'B':
			do {
				system("CLS");
				char password[100];
				string doctor;

				cout << setw(70) << right << "*************** ROLE DOCTOR *****************" << endl << endl;
				cout << setw(64) << right << "Please enter your ID and PASSWORD." << endl << endl;
				cout << setw(41) << right << "Doctor ID: ";
				cin >> doctor;
				cout << setw(40) << right << "Password: ";
				int index = 0;
				while (1)
				{
					char ch;
					ch = _getch();
					if (ch == 8)
					{
						if (index != 0)
						{
							cout << char(8) << " " << char(8);
							index--;
						}
					}
					else if (ch == '\r')
					{
						password[index] = '\0';
						cout << endl;
						break;
					}
					else
					{
						cout << "*";
						password[index++] = ch;
					}
				}

				DoctorFunction doctorFunction;
				bool login = doctorFunction.loginDoc(doctor, password);

				
				if (login == true) {
					do {
							system("CLS");
							cout << setw(70) << right << "*************** ROLE DOCTOR *****************" << endl << endl;
							cout << setw(52) << right << "1. APPOINTMENT" << endl;
							cout << setw(53) << right << "2. PATIENT INFO" << endl;
							cout << setw(55) << right << "3. MEDICAL REPORT" << endl;
							cout << setw(54) << right << "4. MEDICINE LIST" << endl;
							cout << setw(57) << right << "5. STATISTIC REPORT" << endl << endl;
							cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
							cout << setw(70) << right << "*********************************************" << endl;
							cout << endl;
							cout << setw(56) << right << "Choose Your Menu: ";
							cin >> test;
							cin.ignore();
							while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "0") {
								cout << setw(64) << right << "Invalid value. Please enter again." << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
							}
							choice = stoi(test);

							switch (choice) {
							case 1:
								do {
									system("CLS");
									cout << setw(70) << right << "*************** ROLE DOCTOR *****************" << endl << endl;
									cout << setw(62) << right << "1. REVIEW APPOINTMENT BY ID" << endl;
									cout << setw(56) << right << "2. REVIEW APPOINTMENT" << endl << endl;
									cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
									cout << setw(70) << right << "*********************************************" << endl;
									cout << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
									while (test != "1" && test != "2" && test != "0") {
										cout << setw(64) << right << "Invalid value. Please enter again." << endl;
										cout << setw(56) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
									}
									num = stoi(test);

									switch (num) {
									case 1:
										do {
											system("CLS");
											ReviewAppointmentByID();
											cout << "\nDo you want to continue review appointment? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review appointment? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									case 2:
										do {
											system("CLS");
											ReviewDoctorAppointment(doctor);
											cout << "\nDo you want to continue review appointment? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review appointment? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									}
								} while (num != 0);
								break;
							case 2:
								do {
									system("CLS");
									cout << setw(70) << right << "*************** ROLE DOCTOR *****************" << endl << endl;
									cout << setw(62) << right << "1. REVIEW PATIENT INFO BY ID" << endl;
									cout << setw(60) << right << "2. REVIEW ALL PATIENT INFO" << endl << endl;
									cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
									cout << setw(70) << right << "*********************************************" << endl;
									cout << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
									while (test != "1" && test != "2" && test != "0") {
										cout << setw(64) << right << "Invalid value. Please enter again." << endl;
										cout << setw(56) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
									}
									num = stoi(test);

									switch (num)
									{
									case 1:
										do {
											system("CLS");
											ReviewPatientByID();
											cout << "\nDo you want to continue review patient info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review patient info? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									case 2:
										do {
											system("CLS");
											ReviewAllPatient();
											cout << "\nDo you want to continue review all patient info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review all patient info? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									}
								} while (num != 0);
								break;
							case 3:
								do {
									system("CLS");
									cout << setw(70) << right << "*************** ROLE DOCTOR *****************" << endl << endl;
									cout << setw(57) << right << "1. ADD MEDICAL REPORT" << endl;
									cout << setw(60) << right << "2. UPDATE MEDICAL REPORT" << endl;
									cout << setw(60) << right << "3. DELETE MEDICAL REPORT" << endl;
									cout << setw(66) << right << "4. REVIEW MEDICAL REPORT BY ID" << endl;
									cout << setw(64) << right << "5. REVIEW ALL MEDICAL REPORT" << endl << endl;
									cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
									cout << setw(70) << right << "*********************************************" << endl;
									cout << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
									while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "0") {
										cout << setw(64) << right << "Invalid value. Please enter again." << endl;
										cout << setw(56) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
									}
									num = stoi(test);

									switch (num) {
									case 1:
										do {
											system("CLS");
											AddMedicalReport(doctor);
											cout << "\nDo you want to continue add medical report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue add medical report? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									case 2:
										do {
											system("CLS");
											cout << setw(75) << right << "*************** UPDATE MEDICAL REPORT ****************" << endl << endl;
											cout << setw(52) << right << "1. UPDATE ALL INFO" << endl;
											cout << setw(61) << right << "2. UPDATE MEDICAL CONDITION" << endl;
											cout << setw(55) << right << "3. UPDATE TEST RESULT" << endl << endl;
											cout << setw(59) << right << "(Enter 0 to exit system)" << endl;
											cout << setw(75) << right << "******************************************************" << endl;
											cout << endl;
											cout << setw(57) << right << "Choose Your Menu: ";
											cin >> test;
											cin.ignore();
											while (test != "1" && test != "2" && test != "3" && test != "0") {
												cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
												cout << setw(56) << right << "Choose Your Menu: ";
												cin >> test;
												cin.ignore();
											}
											choose = stoi(test);
											UpdateMedicalReport(doctor, choose);

										} while (choose != 0);
										break;
									case 3:
										do {
											system("CLS");
											DeleteMedicalReport();
											cout << "\nDo you want to continue delete medical report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue delete medical report? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									case 4:
										do {
											system("CLS");
											ReviewMedicalReportByID();
											cout << "\nDo you want to continue review medical report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review medical report? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									case 5:
										do {
											system("CLS");
											ReviewAllMedicalReport();
											cout << "\nDo you want to continue review all medical report? (Y/N) ";
											cin >> test;
											cin.ignore();
											test[0] = toupper(test[0]);
											cout << endl;
											while (test != "Y" && test != "N")
											{
												cout << "You entered an invalid character. Please enter again." << endl;
												cout << "Do you want to continue review all medical report? (Y/N) ";
												cin >> test;
												cin.ignore();
												test[0] = toupper(test[0]);
												cout << endl;
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									}
								} while (num != 0);
								break;
							case 4:
								do {
									system("CLS");
									cout << setw(70) << right << "*************** ROLE DOCTOR *****************" << endl << endl;
									cout << setw(59) << right << "1. REVIEW MEDICINE LIST" << endl << endl;
									cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
									cout << setw(70) << right << "*********************************************" << endl;
									cout << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
									while (test != "1" && test != "0") {
										cout << setw(64) << right << "Invalid value. Please enter again." << endl;
										cout << setw(56) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
									}
									num = stoi(test);

									switch (num) {
									case 1:
										do {
											system("CLS");
											ReviewAllMedication();
											cout << "\nDo you want to continue review all medicine? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review all medicine? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									}
								} while (num != 0);
								break;
							case 5:
								do {
									system("CLS");
									cout << setw(70) << right << "*************** ROLE DOCTOR *****************" << endl << endl;
									cout << setw(65) << right << "1. REVIEW PATIENT STATISTIC REPORT" << endl;
									cout << setw(66) << right << "2. REVIEW MEDICINE STATISTIC REPORT" << endl;
									cout << setw(64) << right << "3. REVIEW PROFIT STATISTIC REPORT" << endl << endl;
									cout << setw(60) << right << "(Enter 0 to exit system)" << endl;
									cout << setw(70) << right << "*********************************************" << endl;
									cout << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
									while (test != "1" && test != "2" && test != "3" && test != "0") {
										cout << setw(64) << right << "Invalid value. Please enter again." << endl;
										cout << setw(56) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
									}
									num = stoi(test);

									switch (num) {
									case 1:
										do {
											system("CLS");
											ReviewGenderStat();
											cout << "\nDo you want to continue review this statistic report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review this statistic report? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									case 2:
										do {
											system("CLS");
											ReviewMedicineStat();
											cout << "\nDo you want to continue review this statistic report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
											while (test != "Y" && test != "N") {
												cout << "You entered an invalid character. Please enter again. " << endl;
												cout << "Do you want to continue review this statistic report? (Y/N) ";
												cin >> test;
												test[0] = toupper(test[0]);
											}
											selection = test[0];

										} while (selection == 'Y');
										break;
									case 3:
										do {
											system("CLS");
											cout << setw(75) << right << "*************** PROFIT STATISTIC REPORT ****************" << endl << endl;
											cout << setw(48) << right << "1. YEAR" << endl;
											cout << setw(49) << right << "2. MONTH" << endl << endl;
											cout << setw(59) << right << "(Enter 0 to exit system)" << endl;
											cout << setw(75) << right << "******************************************************" << endl;
											cout << endl;
											cout << setw(55) << right << "Choose Your Menu: ";
											cin >> choose;
											cin.ignore();
											while (choose != 1 && choose != 2 && choose != 3 && choose != 0) {
												cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
												cout << setw(56) << right << "Choose Your Menu: ";
												cin >> choose;
												cin.ignore();
											}
											ReviewProfitStat(choose);
											
										} while (choose != 0);
										break;
									}
								} while (num != 0);
								break;

							}
					} while (choice != 0);
				}
				else
				{
					cout << endl << endl;
					cout << setw(60) << right << "Your ID or Password incorrect." << endl << endl;
					cout << setw(61) << right << "Do you want enter again? (Y/N) ";
					cin >> test;
					test[0] = toupper(test[0]);

					while (test != "Y" && test != "N") {
						cout << endl;
						cout << setw(78) << right << "You entered an invalid character. Please enter again. " << endl;
						cout << setw(82) << right << "Your ID or Password incorrect. Do you want enter again? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
					}

					selection = test[0];
					if (selection == 'Y') {
						system("PAUSE");
						system("CLS");
						choice = 1;
					}
					else if (selection == 'N') {
						break;
					}
				}
			} while (choice != 0);
			break;
		case 'C':
			do {
				system("CLS");

				char password[100];
				string administrator;

				cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
				cout << setw(62) << right << "Please enter your ID and PASSWORD." << endl << endl;
				cout << setw(38) << right << "Admin ID: ";
				cin >> administrator;
				cout << setw(38) << right << "Password: ";
				int index = 0;
				while (1)
				{
					char ch;
					ch = _getch();
					if (ch == 8)
					{
						if (index != 0)
						{
							cout << char(8) << " " << char(8);
							index--;
						}
					}
					else if (ch == '\r')
					{
						password[index] = '\0';
						cout << endl;
						break;
					}
					else
					{
						cout << "*";
						password[index++] = ch;
					}
				}

				AdminFunction adminFunction;
				bool login = adminFunction.LoginAdmin(administrator, password);

				if (login == true)
				{
					do {
						system("CLS");
						cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
						cout << setw(52) << right << "1. PATIENT INFO" << endl;
						cout << setw(51) << right << "2. DOCTOR INFO" << endl;
						cout << setw(58) << right << "3. ADMINISTRATOR INFO" << endl;
						cout << setw(51) << right << "4. APPOINTMENT" << endl;
						cout << setw(48) << right << "5. MEDICINE" << endl;
						cout << setw(55) << right << "6. MEDICAL INVOICE" << endl;
						cout << setw(62) << right << "7. MEDICAL INVOICE DETAIL" << endl;
						cout << setw(54) << right << "8. PAYMENT REPORT" << endl << endl;
						cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
						cout << setw(75) << right << "***************************************************" << endl;
						cout << endl;
						cout << setw(56) << right << "Choose Your Menu: ";
						cin >> test;
						cin.ignore();
						while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "6" && test != "7" && test != "8" && test != "0") {
							cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
							cout << setw(56) << right << "Choose Your Menu: ";
							cin >> test;
							cin.ignore();
						}
						choice = stoi(test);

						switch (choice) {
						case 1:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(54) << right << "1. ADD PATIENT INFO" << endl;
								cout << setw(57) << right << "2. UPDATE PATIENT INFO" << endl;
								cout << setw(57) << right << "3. DELETE PATIENT INFO" << endl;
								cout << setw(63) << right << "4. REVIEW PATIENT INFO BY ID" << endl;
								cout << setw(63) << right << "5. REVIEW PATIENT INFO BY IC" << endl;
								cout << setw(61) << right << "6. REVIEW ALL PATIENT INFO" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "6" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										AddPatient(administrator);
										cout << "\nDo you want to continue add patient info? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add patient info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 2:
									do {
										system("CLS");
										cout << setw(75) << right << "*************** UPDATE PATIENT INFO ****************" << endl << endl;
										cout << setw(54) << right << "1. UPDATE ALL INFO" << endl;
										cout << setw(50) << right << "2. UPDATE NAME" << endl;
										cout << setw(52) << right << "3. UPDATE GENDER" << endl;
										cout << setw(51) << right << "4. UPDATE BIRTH" << endl;
										cout << setw(55) << right << "5. UPDATE IC NUMBER" << endl;
										cout << setw(53) << right << "6. UPDATE ADDRESS" << endl;
										cout << setw(60) << right << "7. UPDATE CONTACT NUMBER" << endl;
										cout << setw(70) << right << "8. UPDATE EMERGENCY CONTACT NUMBER" << endl;
										cout << setw(51) << right << "9. UPDATE EMAIL" << endl << endl;
										cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
										cout << setw(75) << right << "***************************************************" << endl;
										cout << endl;
										cout << setw(56) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
										while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "6" && test != "7" && test != "8" && test != "9" && test != "0") {
											cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
											cout << setw(56) << right << "Choose Your Menu: ";
											cin >> test;
											cin.ignore();
										}
										choose = stoi(test);

										UpdatePatient(administrator, choose);
									} while (choose != 0);
									break;
								case 3:
									do {
										system("CLS");
										DeletePatient();
										cout << "\nDo you want to continue delete patient info? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue delete patient info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 4:
									do {
										system("CLS");
										ReviewPatientByID();
										cout << "\nDo you want to continue review patient info? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review patient info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 5:
									do {
										system("CLS");
										ReviewPatientByIC();
										cout << "\nDo you want to continue review patient info? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review patient info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 6:
									do {
										system("CLS");
										ReviewAllPatient();
										cout << "\nDo you want to continue review all patient info? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all patient info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								}
							} while (num != 0);
							break;
						case 2:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(60) << right << "1. REVIEW ALL DOCTOR INFO" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										ReviewAllDoctor();
										cout << "\nDo you want to continue review all doctor info? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all doctor info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
								}
							} while (num != 0);
							break;
						case 3:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(67) << right << "1. REVIEW ALL ADMINISTRATOR INFO" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										ReviewAllAdministrator();
										cout << "\nDo you want to continue review all administrator info? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all administrator info? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								}
							} while (num != 0);
							break;
						case 4:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(54) << right << "1. ADD APPOINTMENT" << endl;
								cout << setw(57) << right << "2. UPDATE APPOINTMENT" << endl;
								cout << setw(57) << right << "3. DELETE APPOINTMENT" << endl;
								cout << setw(63) << right << "4. REVIEW APPOINTMENT BY ID" << endl;
								cout << setw(61) << right << "5. REVIEW ALL APPOINTMENT" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										AddAppointment(administrator);
										cout << "\nDo you want to continue add appointment? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add appointment? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 2:
									do {
										system("CLS");
										cout << setw(75) << right << "*************** UPDATE APPOINTMENT ****************" << endl << endl;
										cout << setw(54) << right << "1. UPDATE ALL INFO" << endl;
										cout << setw(59) << right << "2. UPDATE DATE AND TIME" << endl;
										cout << setw(56) << right << "3. UPDATE PATIENT ID" << endl;
										cout << setw(55) << right << "4. UPDATE DOCTOR ID" << endl << endl;
										cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
										cout << setw(75) << right << "***************************************************" << endl;
										cout << endl;
										cout << setw(56) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
										while (test != "1" && test != "2" && test != "3" && test != "4" && test != "0") {
											cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
											cout << setw(56) << right << "Choose Your Menu: ";
											cin >> test;
											cin.ignore();
										}
										choose = stoi(test);
										UpdateAppointment(administrator, choose);
										
									} while (choose != 0);
									break;
								case 3:
									do {
										system("CLS");
										DeleteAppointment();
										cout << "\nDo you want to continue delete appointment? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue delete appointment? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 4:
									do {
										system("CLS");
										ReviewAppointmentByID();
										cout << "\nDo you want to continue review appointment? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review appointment? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 5:
									do {
										system("CLS");
										ReviewAllAppointment();
										cout << "\nDo you want to continue review all appointment? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all appointment? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								}
							} while (num != 0);
							break;
						case 5:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(51) << right << "1. ADD MEDICINE" << endl;
								cout << setw(54) << right << "2. UPDATE MEDICINE" << endl;
								cout << setw(54) << right << "3. DELETE MEDICINE" << endl;
								cout << setw(60) << right << "4. REVIEW MEDICINE BY ID" << endl;
								cout << setw(58) << right << "5. REVIEW ALL MEDICINE" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										AddMedication(administrator);
										cout << "\nDo you want to continue add medicine? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add medicine? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 2:
									do {
										system("CLS");
										cout << setw(75) << right << "*************** UPDATE MEDICINE ****************" << endl << endl;
										cout << setw(54) << right << "1. UPDATE ALL INFO" << endl;
										cout << setw(50) << right << "2. UPDATE NAME" << endl;
										cout << setw(52) << right << "3. UPDATE DETAIL" << endl;
										cout << setw(50) << right << "4. UPDATE UNIT" << endl;
										cout << setw(56) << right << "5. UPDATE UNIT PRICE" << endl << endl;
										cout << setw(63) << right << "(Enter 0 to exit system)" << endl;
										cout << setw(75) << right << "************************************************" << endl;
										cout << endl;
										cout << setw(58) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
										while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "0") {
											cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
											cout << setw(56) << right << "Choose Your Menu: ";
											cin >> test;
											cin.ignore();
										}
										choose = stoi(test);
										UpdateMedication(administrator, choose);

									} while (choose != 0);
									break;
								case 3:
									do {
										system("CLS");
										DeleteMedication();
										cout << "\nDo you want to continue delete medicine? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue delete medicine? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 4:
									do {
										system("CLS");
										ReviewMedicationByID();
										cout << "\nDo you want to continue review medicine? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review medicine? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 5:
									do {
										system("CLS");
										ReviewAllMedication();
										cout << "\nDo you want to continue review all medicine? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all medicine? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								}
							} while (num != 0);
							break;
						case 6:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(54) << right << "1. ADD MEDICAL INVOICE" << endl;
								cout << setw(57) << right << "2. UPDATE MEDICAL INVOICE" << endl;
								cout << setw(57) << right << "3. DELETE MEDICAL INVOICE" << endl;
								cout << setw(63) << right << "4. REVIEW MEDICAL INVOICE BY ID" << endl;
								cout << setw(74) << right << "5. REVIEW MEDICAL INVOICE WITH STATUS OPEN" << endl;
								cout << setw(75) << right << "6. REVIEW MEDICAL INVOICE WITH STATUS CLOSE" << endl;
								cout << setw(61) << right << "7. REVIEW ALL MEDICAL INVOICE" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "6" && test != "7" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										AddMedicalInvoice(administrator);
										cout << "\nDo you want to continue add medical invoice? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add medical invoice? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 2:
									do {
										system("CLS");
										cout << setw(75) << right << "*************** UPDATE MEDICAL INVOICE ****************" << endl << endl;
										cout << setw(54) << right << "1. UPDATE ALL INFO" << endl;
										cout << setw(51) << right << "2. UPDATE PRICE" << endl << endl;
										cout << setw(59) << right << "(Enter 0 to exit system)" << endl;
										cout << setw(75) << right << "*******************************************************" << endl;
										cout << endl;
										cout << setw(55) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
										while (test != "1" && test != "2" && test != "0") {
											cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
											cout << setw(56) << right << "Choose Your Menu: ";
											cin >> test;
											cin.ignore();
										}
										choose = stoi(test);
										UpdateMedicalInvoice(choose);

									} while (choose != 0);
									break;
								case 3:
									do {
										system("CLS");
										DeleteMedicalInvoice();
										cout << "\nDo you want to continue delete medical invoice? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue delete medical invoice? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 4:
									do {
										system("CLS");
										ReviewMedicalInvoiceByID();
										cout << "\nDo you want to continue review medical invoice? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review medical invoice? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 5:
									do {
										system("CLS");
										ReviewOpenInvoice();
										cout << "\nDo you want to continue review medical invoice with status open? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review medical invoice with status open? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									cout << "\nDoes customer want to make a payment? (Y/N) ";
									cin >> test;
									test[0] = toupper(test[0]);
									while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to make a payment? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
									}
									selection = test[0];
									while (selection == 'Y') {
										AddPayment();
										cout << "\nDo you want to continue add payment report? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add payment report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];
									}
									break;
								case 6:
									do {
										system("CLS");
										ReviewCloseInvoice();
										cout << "\nDo you want to continue review medical invoice with status close? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review medical invoice with status close? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 7:
									do {
										system("CLS");
										ReviewAllMedicalInvoice();
										cout << "\nDo you want to continue review all medical invoice? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all medical invoice? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									cout << "\nDoes customer want to make a payment? (Y/N) ";
									cin >> test;
									test[0] = toupper(test[0]);
									while (test != "Y" && test != "N") {
										cout << "You entered an invalid character. Please enter again. " << endl;
										cout << "Do you want to make a payment? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
									}
									selection = test[0];
									while (selection == 'Y') {
										AddPayment();
										cout << "\nDo you want to continue add payment report? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add payment report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];
									}
									break;
									}
								} while (num != 0);
								break;
						case 7:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(61) << right << "1. ADD MEDICAL INVOICE DETAIL" << endl;
								cout << setw(64) << right << "2. UPDATE MEDICAL INVOICE DETAIL" << endl;
								cout << setw(64) << right << "3. DELETE MEDICAL INVOICE DETAIL" << endl;
								cout << setw(70) << right << "4. REVIEW MEDICAL INVOICE DETAIL BY ID" << endl;
								cout << setw(68) << right << "5. REVIEW ALL MEDICAL INVOICE DETAIL" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										AddInvoiceDetail();
										cout << "\nDo you want to continue add medical invoice detail? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add medical invoice detail? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 2:
									do {
										system("CLS");
										cout << setw(75) << right << "*************** UPDATE MEDICAL INVOICE DETAIL ****************" << endl << endl;
										cout << setw(46) << right << "1. UPDATE ALL INFO" << endl;
										cout << setw(59) << right << "2. UPDATE MEDICINE AND QUANTITY" << endl << endl;
										cout << setw(54) << right << "(Enter 0 to exit system)" << endl;
										cout << setw(75) << right << "**************************************************************" << endl;
										cout << endl;
										cout << setw(50) << right << "Choose Your Menu: ";
										cin >> test;
										cin.ignore();
										while (test != "1" && test != "2" && test != "0") {
											cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
											cout << setw(56) << right << "Choose Your Menu: ";
											cin >> test;
											cin.ignore();
										}
										choose = stoi(test);
										UpdateInvoiceDetail(choose);

									} while (selection == 'Y');
									break;
								case 3:
									do {
										system("CLS");
										DeleteInvoiceDetail();
										cout << "\nDo you want to continue delete invoice detail? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue delete invoice detail? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 4:
									do {
										system("CLS");
										ReviewInvoiceDetailByID();
										cout << "\nDo you want to continue review medical invoice detail? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review medical invoice detail? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 5:
									do {
										system("CLS");
										ReviewAllInvoiceDetail();
										cout << "\nDo you want to continue review all medical invoice detail? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all medical invoice detail? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								}
							} while (num != 0);
							break;
						case 8:
							do {
								system("CLS");
								cout << setw(75) << right << "*************** ROLE ADMINISTRATOR ****************" << endl << endl;
								cout << setw(54) << right << "1. ADD PAYMENT REPORT" << endl;
								cout << setw(57) << right << "2. UPDATE PAYMENT REPORT" << endl;
								cout << setw(57) << right << "3. DELETE PAYMENT REPORT" << endl;
								cout << setw(63) << right << "4. REVIEW PAYMENT REPORT BY ID" << endl;
								cout << setw(61) << right << "5. REVIEW ALL PAYMENT REPORT" << endl << endl;
								cout << setw(61) << right << "(Enter 0 to exit system)" << endl;
								cout << setw(75) << right << "***************************************************" << endl;
								cout << endl;
								cout << setw(56) << right << "Choose Your Menu: ";
								cin >> test;
								cin.ignore();
								while (test != "1" && test != "2" && test != "3" && test != "4" && test != "5" && test != "0") {
									cout << setw(64) << right << "The number is out of range. Please enter correct number." << endl;
									cout << setw(56) << right << "Choose Your Menu: ";
									cin >> test;
									cin.ignore();
								}
								num = stoi(test);

								switch (num) {
								case 1:
									do {
										system("CLS");
										AddPayment();
										cout << "\nDo you want to continue add payment report? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue add payment report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 2:
									do {
										system("CLS");
										UpdatePayment();
										cout << "\nDo you want to continue update payment report? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue update payment report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 3:
									do {
										system("CLS");
										DeletePayment();
										cout << "\nDo you want to continue delete payment report? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue delete payment report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 4:
									do {
										system("CLS");
										ReviewPaymentByID();
										cout << "\nDo you want to continue review payment report? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review payment report? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);
										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								case 5:
									do {
										system("CLS");
										ReviewAllPayment();
										cout << "\nDo you want to continue review all medical invoice detail? (Y/N) ";
										cin >> test;
										test[0] = toupper(test[0]);
										while (test != "Y" && test != "N") {
											cout << "You entered an invalid character. Please enter again. " << endl;
											cout << "Do you want to continue review all medical invoice detail? (Y/N) ";
											cin >> test;
											test[0] = toupper(test[0]);

										}
										selection = test[0];

									} while (selection == 'Y');
									break;
								}
							} while (num != 0);
							break;
						}
					} while (choice != 0);
				}

				else if (login == false)
				{
					cout << endl << endl;
					cout << setw(60) << right << "Your ID or Password incorrect." << endl << endl;
					cout << setw(61) << right << "Do you want enter again? (Y/N) ";
					cin >> test;
					test[0] = toupper(test[0]);
					while (test != "Y" && test != "N") {
						cout << endl;
						cout << setw(78) << right << "You entered an invalid character. Please enter again. " << endl;
						cout << setw(82) << right << "Your ID or Password incorrect. Do you want enter again? (Y/N) ";
						cin >> test;
						test[0] = toupper(test[0]);
					}
					selection = test[0];
					if (selection == 'Y') {
						system("PAUSE");
						system("CLS");
						choice = 1;
					}
					else if (selection == 'N') {
						break;
					}
				}

			} while (choice != 0);
			break;
		}
	} while (selection != '0');

}

void AddPatient(string administrator) {
	try {
		system("CLS");
		Patient* patient = new Patient();
		PatientFunction patientFunction;

		string a, b, c, d, e;
		Patient* patientid = patientFunction.getPatientID();
		if (patientid != NULL)
		{
			a = patientid->patientid;
			c = a.substr(1, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "P000" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "P00" + d;
			}
			else if (b >= 100 && b <= 999)
			{
				d = to_string(b);
				e = "P0" + d;
			}
			else
			{
				d = to_string(b);
				e = "P" + d;
			}
			patient->patientid = e;
		}
		else
			patient->patientid = "P0001";

		cout << "************ Add Patient Info *************" << endl;

		cout << "Name: ";
		getline(cin >> ws, patient->name);

		cout << "Gender: ";
		cin >> patient->gender;

		cout << "Date of Birth: ";
		cin >> patient->birth;

		cout << "IC Number: ";
		cin >> patient->icnumber;

		while (patient->icnumber.length() != 12)
		{
			cout << "Your IC number is invalid. Please enter again." << endl;
			cout << "IC Number: ";
			cin >> patient->icnumber;
		}

		cout << "Address: ";
		getline(cin >> ws, patient->address);

		cout << "Contact Number: ";
		cin >> patient->contactnumber;

		while (patient->contactnumber.length() != 10 && patient->contactnumber.length() != 11)
		{
			cout << "Your contact number is invalid. Please enter again." << endl;
			cout << "Contact Number: ";
			cin >> patient->contactnumber;
		}

		cout << "Emergency Contact Number: ";
		cin >> patient->econtactnumber;

		while (patient->econtactnumber.length() != 10 && patient->econtactnumber.length() != 11)
		{
			cout << "Your contact number is invalid. Please enter again." << endl;
			cout << "Contact Number: ";
			cin >> patient->econtactnumber;
		}

		cout << "Email: ";
		cin >> patient->email;

		while (patient->email.find("@") == patient->email.npos)
		{
			cout << "Your email is invalid. Please enter correctly." << endl;
			cout << "Email: ";
			cin >> patient->email;
		}

		patient->adminid = administrator;

		int status = patientFunction.addPatient(patient);

		if (status != 0) {
			cout << "\nSuccessfully added a new patient" << endl;

			cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
			string pid = patient->patientid;
			Patient* patients = patientFunction.getPatient(pid);

			if (patients != NULL)
			{
				cout << "Patient ID: " << patients->patientid << endl
					<< "Name: " << patients->name << endl
					<< "Gender: " << patients->gender << endl
					<< "Date of Birth: " << patients->birth << endl
					<< "IC Number: " << patients->icnumber << endl
					<< "Address: " << patients->address << endl
					<< "Contact Number: " << patients->contactnumber << endl
					<< "Emergency Contact Number: " << patients->econtactnumber << endl
					<< "Email: " << patients->email << endl
					<< "Create by Admin " << patients->adminid << endl;
			}
		}
		else
			cout << "\nUnable to add a new patient" << endl;
	}
	catch (...) {
		cout << "\nUnable to add a new patient" << endl;
	}
	return;
}

void UpdatePatient(string administrator, int choose) {
	char selection;
	string test;
	if (choose == 1) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Name: ";
				getline(cin >> ws, patient->name);

				cout << "Gender: ";
				cin >> patient->gender;

				cout << "Date of Birth: ";
				cin >> patient->birth;

				cout << "IC Number: ";
				cin >> patient->icnumber;

				while (patient->icnumber.length() != 12)
				{
					cout << "Your IC number is invalid. Please enter again." << endl;
					cout << "IC Number: ";
					cin >> patient->icnumber;
				}

				cout << "Address: ";
				getline(cin >> ws, patient->address);

				cout << "Contact Number: ";
				cin >> patient->contactnumber;

				while (patient->contactnumber.length() != 10 && patient->contactnumber.length() != 11)
				{
					cout << "Your contact number is invalid. Please enter again." << endl;
					cout << "Contact Number: ";
					cin >> patient->contactnumber;
				}

				cout << "Emergency Contact Number: ";
				cin >> patient->econtactnumber;

				while (patient->econtactnumber.length() != 10 && patient->econtactnumber.length() != 11)
				{
					cout << "Your contact number is invalid. Please enter again." << endl;
					cout << "Contact Number: ";
					cin >> patient->econtactnumber;
				}

				cout << "Email: ";
				cin >> patient->email;

				while (patient->email.find("@") == patient->email.npos)
				{
					cout << "Your email is invalid. Please enter correctly." << endl;
					cout << "Email: ";
					cin >> patient->email;
				}

				patient->adminid = administrator;


				PatientFunction patientFunction;
				int status = patientFunction.updatePatient(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}

				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}

			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 2) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Name: ";
				getline(cin >> ws, patient->name);

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientName(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}
			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 3) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Gender: ";
				cin >> patient->gender;

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientGender(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}

			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 4) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Date of Birth: ";
				cin >> patient->birth;

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientBirth(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}
			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 5) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "IC Number: ";
				cin >> patient->icnumber;

				while (patient->icnumber.length() != 12)
				{
					cout << "Your IC number is invalid. Please enter again." << endl;
					cout << "IC Number: ";
					cin >> patient->icnumber;
				}

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientIC(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}

			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 6) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Address: ";
				getline(cin >> ws, patient->address);

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientAddress(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}

			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 7) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Contact Number: ";
				cin >> patient->contactnumber;

				while (patient->contactnumber.length() != 10 && patient->contactnumber.length() != 11)
				{
					cout << "Your contact number is invalid. Please enter again." << endl;
					cout << "Contact Number: ";
					cin >> patient->contactnumber;
				}

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientCN(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}

			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 8) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Emergency Contact Number: ";
				cin >> patient->econtactnumber;

				while (patient->econtactnumber.length() != 10 && patient->econtactnumber.length() != 11)
				{
					cout << "Your contact number is invalid. Please enter again." << endl;
					cout << "Contact Number: ";
					cin >> patient->econtactnumber;
				}

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientECN(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the patient!" << endl;
			}

			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 9) {
		do {
			try {
				system("CLS");
				Patient* patient = new Patient();

				cout << "************ Update Patient Info *************" << endl;
				cout << "Patient ID: ";
				cin >> patient->patientid;

				cout << "Email: ";
				cin >> patient->email;

				while (patient->email.find("@") == patient->email.npos)
				{
					cout << "Your email is invalid. Please enter correctly." << endl;
					cout << "Email: ";
					cin >> patient->email;
				}

				patient->adminid = administrator;

				PatientFunction patientFunction;
				int status = patientFunction.updatePatientEmail(patient);

				if (status != 0) {
					cout << "\nSuccessfully updated the patient." << endl;

					cout << "\n********** Patient Information For " << patient->patientid << " **********" << endl;
					string pid = patient->patientid;
					Patient* patients = patientFunction.getPatient(pid);

					if (patients != NULL)
					{
						cout << "Patient ID: " << patients->patientid << endl
							<< "Name: " << patients->name << endl
							<< "Gender: " << patients->gender << endl
							<< "Date of Birth: " << patients->birth << endl
							<< "IC Number: " << patients->icnumber << endl
							<< "Address: " << patients->address << endl
							<< "Contact Number: " << patients->contactnumber << endl
							<< "Emergency Contact Number: " << patients->econtactnumber << endl
							<< "Email: " << patients->email << endl
							<< "Create by Admin " << patients->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the patient!" << endl;
			}
			catch(...){
				cout << "\nUnable to update the patient!" << endl;
			}
			cout << "\nDo you want to continue update patient info? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update patient info? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
}

void DeletePatient() {
	try {
		system("CLS");

		Patient* patient = new Patient();
		cout << "********** Delete Patient Info **********" << endl;
		cout << "Patient ID: ";
		cin >> patient->patientid;

		PatientFunction patientFunction;
		int status = patientFunction.deletePatient(patient);
		if (status != 0)
			cout << "\nSuccessfully deleted the patient." << endl;
		else
			cout << "\nUnable to delete the patient!" << endl;
	}
	catch (...) {
		cout << "\nUnable to delete the patient!" << endl;
	}
	return;
}

void ReviewPatientByID() {
	system("CLS");
	string patientid;
	PatientFunction patientFunction;

	cout << "********** Review Patient Info By ID **********" << endl;
	cout << "Patient ID: ";
	cin >> patientid;

	Patient* patient = patientFunction.getPatient(patientid);

	if (patient != NULL)
	{
		cout << "Name: " << patient->name << endl
			<< "Gender: " << patient->gender << endl
			<< "Date of Birth: " << patient->birth << endl
			<< "IC Number: " << patient->icnumber << endl
			<< "Address: " << patient->address << endl
			<< "Contact Number: " << patient->contactnumber << endl
			<< "Emergency Contact Number: " << patient->econtactnumber << endl
			<< "Email: " << patient->email << endl
			<< "Created by Admin " << patient->adminid << endl;
	}
	else
		cout << "Patient not found." << endl;
	return;
}

void ReviewPatientByIC() {
	system("CLS");
	string icnumber;
	PatientFunction patientFunction;

	cout << "********** Review Patient Info By IC **********" << endl;
	cout << "Patient IC: ";
	cin >> icnumber;

	Patient* patient = patientFunction.getPatientI(icnumber);

	if (patient != NULL)
	{
		cout << "Patient ID: " << patient->patientid << endl
			<< "Name: " << patient->name << endl
			<< "Gender: " << patient->gender << endl
			<< "Date of Birth: " << patient->birth << endl
			<< "Address: " << patient->address << endl
			<< "Contact Number: " << patient->contactnumber << endl
			<< "Emergency Contact Number: " << patient->econtactnumber << endl
			<< "Email: " << patient->email << endl
			<< "Created by Admin " << patient->adminid << endl;
	}
	else
		cout << "Patient not found." << endl;
	return;
}

void ReviewAllPatient() {
	system("CLS");
	PatientFunction patientFunction;
	Patient* patients = patientFunction.getPatients();

	cout << "********** Review All Patient Info **********" << endl;
	if (patients != NULL)
	{
		Patient* patient = patients;
		do
		{
			cout << "Patient ID: " << patient->patientid << endl
				<< "Name: " << patient->name << endl
				<< "Gender: " << patient->gender << endl
				<< "Date of Birth: " << patient->birth << endl
				<< "IC Number: " << patient->icnumber << endl
				<< "Address: " << patient->address << endl
				<< "Contact Number: " << patient->contactnumber << endl
				<< "Emergency Contact Number: " << patient->econtactnumber << endl
				<< "Email: " << patient->email << endl
				<< "Created by Admin " << patient->adminid << endl
				<< endl;

			patient = patient->next;

		} while (patient != NULL);
	}
	else
		cout << "The patient list is empty." << endl;
	return;
}

void ReviewDoctorByID() {
	system("CLS");
	string doctorid;
	DoctorFunction doctorFunction;

	cout << "********** Review Doctor Info By ID **********" << endl;
	cout << "Doctor ID: ";
	cin >> doctorid;

	Doctor* doctor = doctorFunction.getDoctorI(doctorid);

	if (doctor != NULL)
	{
		cout << "Doctor ID: " << doctor->doctorid << endl
			<< "Name: " << doctor->name << endl
			<< "Gender: " << doctor->gender << endl
			<< "Contact Number: " << doctor->contactnumber << endl
			<< "Email: " << doctor->email << endl
			<< "Expertise Field: " << doctor->expertisefield << endl
			<< "Created by Admin " << doctor->adminid << endl;
	}
	else
		cout << "Doctor not found." << endl;
	return;
}

void ReviewDoctorByName() {
	system("CLS");
	string name;
	DoctorFunction doctorFunction;

	cout << "********** Review Doctor Info By Name **********" << endl;
	cout << "Doctor Name: ";
	cin >> name;

	Doctor* doctor = doctorFunction.getDoctorN(name);

	if (doctor != NULL)
	{
		cout << "Doctor ID: " << doctor->doctorid << endl
			<< "Name: " << doctor->name << endl
			<< "Gender: " << doctor->gender << endl
			<< "Contact Number: " << doctor->contactnumber << endl
			<< "Email: " << doctor->email << endl
			<< "Expertise Field: " << doctor->expertisefield << endl
			<< "Created by Admin " << doctor->adminid << endl;
	}
	else
		cout << "Doctor not found." << endl;
	return;
}

void ReviewAllDoctor() {
	system("CLS");
	DoctorFunction doctorFunction;
	Doctor* doctors = doctorFunction.getDoctors();

	cout << "********** Review All Doctor Info **********" << endl;
	if (doctors != NULL)
	{
		Doctor* doctor = doctors;
		do
		{
			cout << "Doctor ID: " << doctor->doctorid << endl
				<< "Name: " << doctor->name << endl
				<< "Gender: " << doctor->gender << endl
				<< "Contact Number: " << doctor->contactnumber << endl
				<< "Email: " << doctor->email << endl
				<< "Expertise Field: " << doctor->expertisefield << endl
				<< "Created by Admin " << doctor->adminid << endl
				<< endl;

			doctor = doctor->next;

		} while (doctor != NULL);
	}
	else
		cout << "The doctor list is empty." << endl;
	return;
}

void ReviewAdministratorByID() {
	system("CLS");
	string adminid;
	AdminFunction adminFunction;

	cout << "********** Review Administrator Info By ID **********" << endl;
	cout << "Administrator ID: ";
	cin >> adminid;

	Administrator* admin = adminFunction.getAdmin(adminid);

	if (admin != NULL)
	{
		cout << "Name: " << admin->name << endl
			<< "Gender: " << admin->gender << endl
			<< "Contact Number: " << admin->contactnumber << endl
			<< "Email: " << admin->email << endl;
	}
	else
		cout << "Administrator not found." << endl;
	return;
}

void ReviewAllAdministrator() {
	system("CLS");
	AdminFunction adminFunction;
	Administrator* admins = adminFunction.getAdmins();

	cout << "********** Review All Administrator Info **********" << endl;
	if (admins != NULL)
	{
		Administrator* admin = admins;
		do
		{
			cout << "Administrator ID: " << admin->adminid << endl
				<< "Name: " << admin->name << endl
				<< "Gender: " << admin->gender << endl
				<< "Contact Number: " << admin->contactnumber << endl
				<< "Email: " << admin->email << endl
				<< endl;

			admin = admin->next;

		} while (admin != NULL);
	}
	else
		cout << "The administrator list is empty." << endl;
	return;
}

void AddAppointment(string administrator) {
	try {
		system("CLS");

		cout << "********** Add Appointment **********" << endl;
		time_t rawtime;
		tm* timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

		string dt = buffer;
		string dtime;

		Appointment* appointment = new Appointment();
		AppointmentFunction appointmentFunction;

		string a, b, c, d, e;
		Appointment* appointmentid = appointmentFunction.getAppointmentID();
		if (appointmentid != NULL)
		{
			a = appointmentid->appointmentid;
			c = a.substr(2, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "AP00" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "AP0" + d;
			}
			else
			{
				d = to_string(b);
				e = "AP" + d;
			}
			appointment->appointmentid = e;
		}
		else
			appointment->appointmentid = "AP001";

		cout << "Patient ID: ";
		cin >> appointment->patientid;

		cout << "Doctor ID: ";
		cin >> appointment->doctorid;

		cout << "Date Time: ";
		getline(cin >> ws, dtime);

		appointment->datetime = dtime;

		appointment->adminid = administrator;

		int status = appointmentFunction.addAppointment(appointment);

		if (status != 0) {
			cout << "\nSuccessfully added a new appointment" << endl;

			cout << "\n********** Appointment Detail For " << appointment->appointmentid << " **********" << endl;
			string aid = appointment->appointmentid;
			Appointment* appointments = appointmentFunction.getAppointmentA(aid);

			if (appointments != NULL)
			{
				cout << "Appointment ID: " << appointments->appointmentid << endl
					<< "Patient ID: " << appointments->patientid << endl
					<< "Doctor ID: " << appointments->doctorid << endl
					<< "Date Time: " << appointments->datetime << endl
					<< "Create by Admin " << appointments->adminid << endl;

				int days;
				if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
					days = 0;
				}
				else
					days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
				cout << "The number of days between two dates is " << days << endl;

			}
		}
		else
			cout << "\nUnable to add a new appointment" << endl;
	}
	catch (...) {
		cout << "\nUnable to add a new appointment. You enter some information wrongly." << endl;
	}

	return;
}

void UpdateAppointment(string administrator, int choose) {

	char selection;
	string test;
	if (choose == 1) {
		do {
			try {
				system("CLS");
				cout << "********** Update Appointment **********" << endl;
				time_t rawtime;
				tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);

				strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

				string dt = buffer;

				string dtime;

				Appointment* appointment = new Appointment();

				cout << "Appointment ID: ";
				cin >> appointment->appointmentid;

				cout << "Patient ID: ";
				cin >> appointment->patientid;

				cout << "Doctor ID: ";
				cin >> appointment->doctorid;

				cout << "Date Time: ";
				getline(cin >> ws, dtime);

				appointment->datetime = dtime;

				appointment->adminid = administrator;

				AppointmentFunction appointmentFunction;
				int status = appointmentFunction.updateAppointment(appointment);

				if (status != 0) {
					cout << "\nSuccessfully updated the appointment." << endl;

					cout << "\n********** Appointment Detail For " << appointment->appointmentid << " **********" << endl;
					string aid = appointment->appointmentid;
					Appointment* appointments = appointmentFunction.getAppointmentA(aid);

					if (appointments != NULL)
					{
						cout << "Appointment ID: " << appointments->appointmentid << endl
							<< "Patient ID: " << appointments->patientid << endl
							<< "Doctor ID: " << appointments->doctorid << endl
							<< "Date Time: " << appointments->datetime << endl
							<< "Create by Admin " << appointments->adminid << endl;

						int days;
						if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
							days = 0;
						}
						else
							days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
						cout << "The number of days between two dates is " << days << endl;
					}
				}
				else
					cout << "\nUnable to update the appointment!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the appointment!" << endl;
			}

			cout << "\nDo you want to continue update appointment? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update appointment? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 2) {
		do {
			try {
				system("CLS");
				cout << "********** Update Appointment **********" << endl;
				time_t rawtime;
				tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);

				strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

				string dt = buffer;

				string dtime;

				Appointment* appointment = new Appointment();

				cout << "Appointment ID: ";
				cin >> appointment->appointmentid;

				cout << "Date Time: ";
				getline(cin >> ws, dtime);

				appointment->datetime = dtime;

				appointment->adminid = administrator;

				AppointmentFunction appointmentFunction;
				int status = appointmentFunction.updateAppointmentDate(appointment);

				if (status != 0) {
					cout << "\nSuccessfully updated the appointment." << endl;

					cout << "\n********** Appointment Detail For " << appointment->appointmentid << " **********" << endl;
					string aid = appointment->appointmentid;
					Appointment* appointments = appointmentFunction.getAppointmentA(aid);

					if (appointments != NULL)
					{
						cout << "Appointment ID: " << appointments->appointmentid << endl
							<< "Patient ID: " << appointments->patientid << endl
							<< "Doctor ID: " << appointments->doctorid << endl
							<< "Date Time: " << appointments->datetime << endl
							<< "Create by Admin " << appointments->adminid << endl;

						int days;
						if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
							days = 0;
						}
						else
							days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
						cout << "The number of days between two dates is " << days << endl;
					}
				}
				else
					cout << "\nUnable to update the appointment!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the appointment!" << endl;
			}

			cout << "\nDo you want to continue update appointment? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update appointment? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 3) {
		do {
			try {
				system("CLS");

				cout << "********** Update Appointment **********" << endl;
				time_t rawtime;
				tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);

				strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

				string dt = buffer;

				string dtime;

				Appointment* appointment = new Appointment();

				cout << "Appointment ID: ";
				cin >> appointment->appointmentid;

				cout << "Patient ID: ";
				cin >> appointment->patientid;

				appointment->adminid = administrator;

				AppointmentFunction appointmentFunction;
				int status = appointmentFunction.updateAppointmentPatient(appointment);

				if (status != 0) {
					cout << "\nSuccessfully updated the appointment." << endl;

					cout << "\n********** Appointment Detail For " << appointment->appointmentid << " **********" << endl;
					string aid = appointment->appointmentid;
					Appointment* appointments = appointmentFunction.getAppointmentA(aid);

					if (appointments != NULL)
					{
						cout << "Appointment ID: " << appointments->appointmentid << endl
							<< "Patient ID: " << appointments->patientid << endl
							<< "Doctor ID: " << appointments->doctorid << endl
							<< "Date Time: " << appointments->datetime << endl
							<< "Create by Admin " << appointments->adminid << endl;

						int days;
						if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
							days = 0;
						}
						else
							days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
						cout << "The number of days between two dates is " << days << endl;
					}
				}
				else
					cout << "\nUnable to update the appointment!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the appointment!" << endl;
			}

			cout << "\nDo you want to continue update appointment? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update appointment? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 4) {
		do {
			try {
				system("CLS");

				cout << "********** Update Appointment **********" << endl;
				time_t rawtime;
				tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);

				strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

				string dt = buffer;

				string dtime;

				Appointment* appointment = new Appointment();


				cout << "Appointment ID: ";
				cin >> appointment->appointmentid;

				cout << "Doctor ID: ";
				cin >> appointment->doctorid;

				appointment->adminid = administrator;

				AppointmentFunction appointmentFunction;
				int status = appointmentFunction.updateAppointmentDoctor(appointment);

				if (status != 0) {
					cout << "\nSuccessfully updated the appointment." << endl;

					cout << "\n********** Appointment Detail For " << appointment->appointmentid << " **********" << endl;
					string aid = appointment->appointmentid;
					Appointment* appointments = appointmentFunction.getAppointmentA(aid);

					if (appointments != NULL)
					{
						cout << "Appointment ID: " << appointments->appointmentid << endl
							<< "Patient ID: " << appointments->patientid << endl
							<< "Doctor ID: " << appointments->doctorid << endl
							<< "Date Time: " << appointments->datetime << endl
							<< "Create by Admin " << appointments->adminid << endl;

						int days;
						if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
							days = 0;
						}
						else
							days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
						cout << "The number of days between two dates is " << days << endl;
					}
				}
				else
					cout << "\nUnable to update the appointment!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the appointment!" << endl;
			}

			cout << "\nDo you want to continue update appointment? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update appointment? (Y/N) ";
				cin >> test;
				selection = test[0];
			}
			selection = test[0];

		} while (selection == 'Y');
	}
}

void DeleteAppointment() {
	try {
		system("CLS");

		cout << "********** Delete Appointment **********" << endl;
		Appointment* appointment = new Appointment();

		cout << "Appointment ID: ";
		cin >> appointment->appointmentid;

		AppointmentFunction appointmentFunction;
		int status = appointmentFunction.deleteAppointment(appointment);
		if (status != 0)
			cout << "\nSuccessfully deleted the appointment." << endl;
		else
			cout << "\nUnable to delete the appointment!" << endl;
	}
	catch (...) {
		cout << "\nUnable to delete the appointment!" << endl;
	}
	return;
}

void ReviewAppointmentByID() {
	system("CLS");
	time_t rawtime;
	tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

	string dt = buffer;
	string appointmentid;
	AppointmentFunction appointmentFunction;

	cout << "********** Review Appointment By ID **********" << endl;
	cout << "Appointment ID: ";
	cin >> appointmentid;

	Appointment* appointment = appointmentFunction.getAppointmentA(appointmentid);

	if (appointment != NULL)
	{
		cout << "Patient ID: " << appointment->patientid << endl
			<< "Doctor ID: " << appointment->doctorid << endl
			<< "Date Time: " << appointment->datetime << endl
			<< "Created by Admin " << appointment->adminid << endl;

		int days;
		if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
			days = 0;
		}
		else
			days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
		cout << "The number of days between two dates is " << days << endl;
	}
	else
		cout << "Appointment not found." << endl;
	return;
}

void ReviewAllAppointment() {
	system("CLS");
	time_t rawtime;
	tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

	string dt = buffer;
	AppointmentFunction appointmentFunction;
	Appointment* appointments = appointmentFunction.getAppointments();

	cout << "********** Review All Appointment **********" << endl;
	if (appointments != NULL)
	{
		Appointment* appointment = appointments;
		do
		{
			cout << "Appointment ID: " << appointment->appointmentid << endl
				<< "Patient ID: " << appointment->patientid << endl
				<< "Doctor ID: " << appointment->doctorid << endl
				<< "Date Time: " << appointment->datetime << endl
				<< "Created by Admin " << appointment->adminid << endl;

			int days;
			if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
				days = 0;
			}
			else
				days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
			cout << "The number of days between two dates is " << days << endl << endl;
			appointment = appointment->next;

		} while (appointment != NULL);
	}
	else
		cout << "The appointment list is empty." << endl;
	return;
}

void ReviewDoctorAppointment(string doctor) {
	system("CLS");
	time_t rawtime;
	tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

	string dt = buffer;
	AppointmentFunction appointmentFunction;
	Appointment* appointments = appointmentFunction.getAppointmentsDoc(doctor);

	cout << "********** Review All Appointment **********" << endl;
	if (appointments != NULL)
	{
		Appointment* appointment = appointments;
		do
		{
			cout << "Appointment ID: " << appointment->appointmentid << endl
				<< "Patient ID: " << appointment->patientid << endl
				<< "Doctor ID: " << appointment->doctorid << endl
				<< "Date Time: " << appointment->datetime << endl
				<< "Created by Admin " << appointment->adminid << endl;

			int days;
			if ((stoi(dt.substr(0, 4)) > stoi(appointment->datetime.substr(0, 4))) || ((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) > stoi(appointment->datetime.substr(5, 2)))) || (((stoi(dt.substr(0, 4)) == stoi(appointment->datetime.substr(0, 4))) && (stoi(dt.substr(5, 2)) == stoi(appointment->datetime.substr(5, 2)))) && (stoi(dt.substr(8, 2)) > stoi(appointment->datetime.substr(8, 2))))) {
				days = 0;
			}
			else
				days = abs(countNoOfDays(dt) - countNoOfDays(appointment->datetime));
			cout << "The number of days between two dates is " << days << endl << endl;
			appointment = appointment->next;

		} while (appointment != NULL);
	}
	else
		cout << "The appointment list is empty." << endl;
	return;
}

void AddMedicalReport(string doctor) {
	try {
		system("CLS");

		cout << "********** Add Medical Report **********" << endl;
		int quantity, tprice = 0, nmedicine, up;
		string mid;

		time_t rawtime;
		tm* timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

		string dt = buffer;

		MedicalReport* medicalreport = new MedicalReport();
		MedicalRFunction medicalRFunction;

		string a, b, c, d, e;
		MedicalReport* medicalreportid = medicalRFunction.getMedicalReportID();
		if (medicalreportid != NULL)
		{
			a = medicalreportid->medicalrid;
			c = a.substr(2, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "MR00" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "MR0" + d;
			}
			else
			{
				d = to_string(b);
				e = "MR" + d;
			}
			medicalreport->medicalrid = e;
		}
		else
			medicalreport->medicalrid = "MR001";

		cout << "Patient ID: ";
		cin >> medicalreport->patientid;

		medicalreport->doctorid = doctor;

		medicalreport->datetime = dt;

		cout << "Medical Condition Description: ";
		getline(cin >> ws, medicalreport->medicalcondition);

		cout << "Test Result: ";
		getline(cin >> ws, medicalreport->testresult);

		int status = medicalRFunction.addMedicalReport(medicalreport);

		MedicalInvoice* medicalinvoice = new MedicalInvoice();
		InvoiceFunction invoiceFunction;

		MedicalInvoice* medicalinvoiceid = invoiceFunction.getInvoiceID();
		if (medicalinvoiceid != NULL)
		{
			a = medicalinvoiceid->medicalinid;
			c = a.substr(2, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "MI00" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "MI0" + d;
			}
			else
			{
				d = to_string(b);
				e = "MI" + d;
			}
			medicalinvoice->medicalinid = e;
		}
		else
			medicalinvoice->medicalinid = "MI001";

		medicalinvoice->totalprice = 0;

		medicalinvoice->patientid = medicalreport->patientid;

		medicalinvoice->medicalrid = medicalreport->medicalrid;

		invoiceFunction.addInvoice(medicalinvoice);

		cout << "Number of type of medicine: ";
		cin >> nmedicine;

		for (int i = 0; i < nmedicine; i++)
		{
			cout << "Medicine ID: ";
			cin >> mid;

			cout << "Quantity: ";
			cin >> quantity;

			MedicationFunction medicationFunction;
			Medication* medication = medicationFunction.getMedication(mid);
			up = medication->uPrice;

			InvoiceDetail* invoicedetail = new InvoiceDetail();
			InvoiceDetailFunction invoiceDetailFunction;

			InvoiceDetail* invoicedetailid = invoiceDetailFunction.getInvoiceDetailID();
			if (invoicedetailid != NULL)
			{
				a = invoicedetailid->medicalindeid;
				c = a.substr(2, 4);
				d, e;
				int b = stoi(c) + 1;
				if (b >= 0 && b <= 9)
				{
					d = to_string(b);
					e = "ID00" + d;
				}
				else if (b >= 10 && b <= 99)
				{
					d = to_string(b);
					e = "ID0" + d;
				}
				else
				{
					d = to_string(b);
					e = "ID" + d;
				}
				invoicedetail->medicalindeid = e;
			}
			else
				invoicedetail->medicalindeid = "ID001";

			invoicedetail->quantityrequired = quantity;

			invoicedetail->medicalinid = medicalinvoice->medicalinid;

			invoicedetail->medicationid = mid;

			invoiceDetailFunction.addInvoiceDetail(invoicedetail);

			tprice = tprice + (quantity * up);
		}

		MedicalInvoice* medicalinvoiceU = new MedicalInvoice();
		medicalinvoiceU->medicalinid = medicalinvoice->medicalinid;
		medicalinvoiceU->totalprice = tprice;
		medicalinvoiceU->patientid = medicalreport->patientid;
		medicalinvoiceU->medicalrid = medicalreport->medicalrid;
		invoiceFunction.updateInvoice(medicalinvoiceU);

		if (status != 0) {
			cout << "\nSuccessfully added a new medical report" << endl;

			cout << "\n********** Medical Report For " << medicalreport->medicalrid << " **********" << endl;

			string mrid = medicalreport->medicalrid;
			MedicalReport* medicalreports = medicalRFunction.getMedicalReport(mrid);

			if (medicalreports != NULL)
			{
				cout << "Medical Report ID: " << medicalreports->medicalrid << endl
					<< "Patient ID: " << medicalreports->patientid << endl
					<< "Doctor ID: " << medicalreports->doctorid << endl
					<< "Date Time: " << medicalreports->datetime << endl
					<< "Medical Condition Description: " << medicalreports->medicalcondition << endl
					<< "Test Result: " << medicalreports->testresult << endl;
			}
		}
		else
			cout << "\nUnable to add a new medical report" << endl;
	}
	catch (...) {
		cout << "\nUnable to add a new medical report" << endl;
	}
	return;
}

void UpdateMedicalReport(string doctor, int choose) {
	char selection;
	string test;
	if (choose == 1) {
		do {
			try {
				system("CLS");

				cout << "********** Update Medical Report **********" << endl;
				time_t rawtime;
				tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);

				strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

				string dt = buffer;

				MedicalReport* medicalreport = new MedicalReport();

				cout << "Medical Report ID: ";
				cin >> medicalreport->medicalrid;

				cout << "Patient ID: ";
				cin >> medicalreport->patientid;

				medicalreport->doctorid = doctor;

				medicalreport->datetime = dt;

				cout << "Medical Condition Description: ";
				getline(cin >> ws, medicalreport->medicalcondition);

				cout << "Test Result: ";
				getline(cin >> ws, medicalreport->testresult);

				MedicalRFunction medicalRFunction;
				int status = medicalRFunction.updateMedicalReport(medicalreport);

				if (status != 0) {
					cout << "\nSuccessfully updated the medical report." << endl;

					cout << "\n********** Medical Report For " << medicalreport->medicalrid << " **********" << endl;
					string mid = medicalreport->medicalrid;
					MedicalReport* medicalreports = medicalRFunction.getMedicalReport(mid);

					if (medicalreports != NULL)
					{
						cout << "Medical Report ID: " << medicalreports->medicalrid << endl
							<< "Patient ID: " << medicalreports->patientid << endl
							<< "Doctor ID: " << medicalreports->doctorid << endl
							<< "Date Time: " << medicalreports->datetime << endl
							<< "Medical Condition Description: " << medicalreports->medicalcondition << endl
							<< "Test Result: " << medicalreports->testresult << endl;
					}
				}
				else
					cout << "\nUnable to update the medical report!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medical report!" << endl;
			}

			cout << "\nDo you want to continue update medical report? (Y/N) ";
			cin >> test;
			cin.ignore();
			test[0] = toupper(test[0]);
			cout << endl;
			while (test != "Y" && test != "N")
			{
				cout << "You entered an invalid character. Please enter again." << endl;
				cout << "Do you want to continue update medical report? (Y/N) ";
				cin >> test;
				cin.ignore();
				test[0] = toupper(test[0]);
				cout << endl;
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 2) {
		do {
			try {
				system("CLS");

				cout << "********** Update Medical Report **********" << endl;

				MedicalReport* medicalreport = new MedicalReport();

				cout << "Medical Report ID: ";
				cin >> medicalreport->medicalrid;

				cout << "Medical Condition Description: ";
				getline(cin >> ws, medicalreport->medicalcondition);

				MedicalRFunction medicalRFunction;
				int status = medicalRFunction.updateMedicalReportCondition(medicalreport);

				if (status != 0) {
					cout << "\nSuccessfully updated the medical report." << endl;

					cout << "\n********** Medical Report For " << medicalreport->medicalrid << " **********" << endl;
					string mid = medicalreport->medicalrid;
					MedicalReport* medicalreports = medicalRFunction.getMedicalReport(mid);

					if (medicalreports != NULL)
					{
						cout << "Medical Report ID: " << medicalreports->medicalrid << endl
							<< "Patient ID: " << medicalreports->patientid << endl
							<< "Doctor ID: " << medicalreports->doctorid << endl
							<< "Date Time: " << medicalreports->datetime << endl
							<< "Medical Condition Description: " << medicalreports->medicalcondition << endl
							<< "Test Result: " << medicalreports->testresult << endl;
					}
				}
				else
					cout << "\nUnable to update the medical report!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medical report!" << endl;
			}

			cout << "\nDo you want to continue update medical report? (Y/N) ";
			cin >> test;
			cin.ignore();
			test[0] = toupper(test[0]);
			cout << endl;
			while (test != "Y" && test != "N")
			{
				cout << "You entered an invalid character. Please enter again." << endl;
				cout << "Do you want to continue update medical report? (Y/N) ";
				cin >> test;
				cin.ignore();
				test[0] = toupper(test[0]);
				cout << endl;
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 3) {
		do {
			try {
				system("CLS");

				cout << "********** Update Medical Report **********" << endl;

				MedicalReport* medicalreport = new MedicalReport();

				cout << "Medical Report ID: ";
				cin >> medicalreport->medicalrid;

				cout << "Test Result: ";
				getline(cin >> ws, medicalreport->testresult);

				MedicalRFunction medicalRFunction;
				int status = medicalRFunction.updateMedicalReportTest(medicalreport);

				if (status != 0) {
					cout << "\nSuccessfully updated the medical report." << endl;

					cout << "\n********** Medical Report For " << medicalreport->medicalrid << " **********" << endl;
					string mid = medicalreport->medicalrid;
					MedicalReport* medicalreports = medicalRFunction.getMedicalReport(mid);

					if (medicalreports != NULL)
					{
						cout << "Medical Report ID: " << medicalreports->medicalrid << endl
							<< "Patient ID: " << medicalreports->patientid << endl
							<< "Doctor ID: " << medicalreports->doctorid << endl
							<< "Date Time: " << medicalreports->datetime << endl
							<< "Medical Condition Description: " << medicalreports->medicalcondition << endl
							<< "Test Result: " << medicalreports->testresult << endl;
					}
				}
				else
					cout << "\nUnable to update the medical report!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medical report!" << endl;
			}

			cout << "\nDo you want to continue update medical report? (Y/N) ";
			cin >> test;
			cin.ignore();
			test[0] = toupper(test[0]);
			cout << endl;
			while (test != "Y" && test != "N")
			{
				cout << "You entered an invalid character. Please enter again." << endl;
				cout << "Do you want to continue update medical report? (Y/N) ";
				cin >> test;
				cin.ignore();
				test[0] = toupper(test[0]);
				cout << endl;
			}
			selection = test[0];

		} while (selection == 'Y');
	}
}

void DeleteMedicalReport() {
	try {
		system("CLS");

		cout << "********** Delete Medical Report **********" << endl;
		MedicalReport* medicalreport = new MedicalReport();

		cout << "Medical Report ID: ";
		cin >> medicalreport->medicalrid;

		MedicalRFunction medicalRFunction;
		int status = medicalRFunction.deleteMedicalReport(medicalreport);
		if (status != 0)
			cout << "\nSuccessfully deleted the medical report." << endl;
		else
			cout << "\nUnable to delete the medical report!" << endl;
	}
	catch(...){
		cout << "\nUnable to delete the medical report!" << endl;
	}
	return;
}

void ReviewMedicalReportByID() {
	system("CLS");
	string medicalrid;
	MedicalRFunction medicalRFunction;

	cout << "********** Review Medical Report By ID **********" << endl;
	cout << "Medical Report ID: ";
	cin >> medicalrid;

	MedicalReport* medicalreport = medicalRFunction.getMedicalReport(medicalrid);

	if (medicalreport != NULL)
	{
		cout << "Patient ID: " << medicalreport->patientid << endl
			<< "Doctor ID: " << medicalreport->doctorid << endl
			<< "Date Time: " << medicalreport->datetime << endl
			<< "Medical Condition Description: " << medicalreport->medicalcondition << endl
			<< "Test Result: " << medicalreport->testresult << endl;
	}
	else
		cout << "Medical Report not found." << endl;
	return;
}

void ReviewAllMedicalReport() {
	system("CLS");
	MedicalRFunction medicalRFunction;
	MedicalReport* medicalreports = medicalRFunction.getMedicalReports();

	cout << "********** Review All Medical Report **********" << endl;
	if (medicalreports != NULL)
	{
		MedicalReport* medicalreport = medicalreports;
		do
		{
			cout << "Medical Report ID: " << medicalreport->medicalrid << endl
				<< "Patient ID: " << medicalreport->patientid << endl
				<< "Doctor ID: " << medicalreport->doctorid << endl
				<< "Date Time: " << medicalreport->datetime << endl
				<< "Medical Condition Description: " << medicalreport->medicalcondition << endl
				<< "Test Result: " << medicalreport->testresult << endl
				<< endl;

			medicalreport = medicalreport->next;

		} while (medicalreport != NULL);
	}
	else
		cout << "The medical report list is empty." << endl;
	return;
}

void AddMedicalInvoice(string administrator) {
	try {
		system("CLS");
		MedicalInvoice* medicalinvoice = new MedicalInvoice();
		InvoiceFunction invoiceFunction;

		cout << "********** Add Medical Invoice **********" << endl;
		string a, b, c, d, e;
		MedicalInvoice* medicalinvoiceid = invoiceFunction.getInvoiceID();
		if (medicalinvoiceid != NULL)
		{
			a = medicalinvoiceid->medicalinid;
			c = a.substr(2, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "MI00" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "MI0" + d;
			}
			else
			{
				d = to_string(b);
				e = "MI" + d;
			}
			medicalinvoice->medicalinid = e;
		}
		else
			medicalinvoice->medicalinid = "MR001";

		cout << "Medical Report ID: ";
		cin >> medicalinvoice->medicalrid;

		cout << "Patient ID: ";
		cin >> medicalinvoice->patientid;

		cout << "Total Price (RM): ";
		cin >> medicalinvoice->totalprice;

		medicalinvoice->status = 0;

		int status = invoiceFunction.addInvoice(medicalinvoice);

		if (status != 0) {
			cout << "\nSuccessfully added a new medical invoice." << endl;

			cout << "\n********** Review Medical Invoice For " << medicalinvoice->medicalinid << " **********" << endl;
			string mid = medicalinvoice->medicalinid;
			MedicalInvoice* medicalinvoices = invoiceFunction.getInvoice(mid);

			if (medicalinvoices != NULL)
			{
				cout << "Medical Invoice ID: " << medicalinvoices->medicalinid << endl
					<< "Total Price (RM): " << medicalinvoices->totalprice << endl
					<< "Patient ID: " << medicalinvoices->patientid << endl
					<< "Medical Report ID: " << medicalinvoices->medicalrid << endl
					<< "Medical Invoice Status: " << medicalinvoices->status << endl << endl;
			}
		}
		else
			cout << "\nUnable to add a new medical invoice!" << endl;
	}
	catch (...) {
		cout << "\nUnable to add a new medical invoice!" << endl;
	}
	return;
}

void UpdateMedicalInvoice(int choose) {
	char selection;
	string test;
	if (choose == 1) {
		do {
			try {
				system("CLS");
				MedicalInvoice* medicalinvoice = new MedicalInvoice();

				cout << "********** Update Medical Invoice **********" << endl;
				cout << "Medical Invoice ID: ";
				cin >> medicalinvoice->medicalinid;

				cout << "Medical Report ID: ";
				cin >> medicalinvoice->medicalrid;

				cout << "Patient ID: ";
				cin >> medicalinvoice->patientid;

				cout << "Total Price (RM): ";
				cin >> medicalinvoice->totalprice;

				medicalinvoice->status = 0;

				while (medicalinvoice->status != 0 && medicalinvoice->status != 1)
				{
					cout << "The value is only 0 or 1. Please enter again." << endl;
					cout << "Medical Invoice Status: ";
					cin >> medicalinvoice->status;
				}

				InvoiceFunction invoiceFunction;
				int status = invoiceFunction.updateInvoice(medicalinvoice);

				if (status != 0) {
					cout << "\nSuccessfully updated the medical invoice." << endl;

					cout << "\n********** Review Medical Invoice For " << medicalinvoice->medicalinid << " **********" << endl;
					string mid = medicalinvoice->medicalinid;
					MedicalInvoice* medicalinvoices = invoiceFunction.getInvoice(mid);

					if (medicalinvoices != NULL)
					{
						cout << "Medical Invoice ID: " << medicalinvoices->medicalinid << endl
							<< "Total Price (RM): " << medicalinvoices->totalprice << endl
							<< "Patient ID: " << medicalinvoices->patientid << endl
							<< "Medical Report ID: " << medicalinvoices->medicalrid << endl
							<< "Medical Invoice Status: " << medicalinvoices->status << endl << endl;
					}
				}
				else
					cout << "\nUnable to update the medical invoice!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medical invoice!" << endl;
			}

			cout << "\nDo you want to continue update medical invoice? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medical invoice? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 2) {
		do {
			try {
				system("CLS");
				MedicalInvoice* medicalinvoice = new MedicalInvoice();

				cout << "********** Update Medical Invoice **********" << endl;
				cout << "Medical Invoice ID: ";
				cin >> medicalinvoice->medicalinid;

				cout << "Total Price (RM): ";
				cin >> medicalinvoice->totalprice;

				medicalinvoice->status = 0;

				while (medicalinvoice->status != 0 && medicalinvoice->status != 1)
				{
					cout << "The value is only 0 or 1. Please enter again." << endl;
					cout << "Medical Invoice Status: ";
					cin >> medicalinvoice->status;
				}

				InvoiceFunction invoiceFunction;
				int status = invoiceFunction.updateInvoicePrice(medicalinvoice);

				if (status != 0) {
					cout << "\nSuccessfully updated the medical invoice." << endl;

					cout << "\n********** Review Medical Invoice For " << medicalinvoice->medicalinid << " **********" << endl;
					string mid = medicalinvoice->medicalinid;
					MedicalInvoice* medicalinvoices = invoiceFunction.getInvoice(mid);

					if (medicalinvoices != NULL)
					{
						cout << "Medical Invoice ID: " << medicalinvoices->medicalinid << endl
							<< "Total Price (RM): " << medicalinvoices->totalprice << endl
							<< "Patient ID: " << medicalinvoices->patientid << endl
							<< "Medical Report ID: " << medicalinvoices->medicalrid << endl
							<< "Medical Invoice Status: " << medicalinvoices->status << endl << endl;
					}
				}
				else
					cout << "\nUnable to update the medical invoice!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medical invoice!" << endl;
			}

			cout << "\nDo you want to continue update medical invoice? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medical invoice? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
}

void DeleteMedicalInvoice() {
	try {
		system("CLS");

		cout << "********** Delete Medical Invoice **********" << endl;
		MedicalInvoice* medicalinvoice = new MedicalInvoice();

		cout << "Medical Invoice ID: ";
		cin >> medicalinvoice->medicalinid;

		InvoiceFunction invoiceFunction;
		int status = invoiceFunction.deleteInvoice(medicalinvoice);
		if (status != 0)
			cout << "\nSuccessfully deleted the medical invoice." << endl;
		else
			cout << "\nUnable to delete the medical invoice!" << endl;
	}
	catch (...) {
		cout << "\nUnable to delete the medical invoice!" << endl;
	}
	return;
}

void ReviewOpenInvoice() {
	system("CLS");
	InvoiceFunction invoiceFunction;
	MedicalInvoice* medicalinvoices = invoiceFunction.getOpenInvoice();

	cout << "********** Review Open Status Medical Invoice **********" << endl;
	if (medicalinvoices != NULL)
	{
		MedicalInvoice* medicalinvoice = medicalinvoices;
		do
		{
			cout << "Medical Invoice ID: " << medicalinvoice->medicalinid << endl
				<< "Total Price (RM): " << medicalinvoice->totalprice << endl
				<< "Patient ID: " << medicalinvoice->patientid << endl
				<< "Medical Report ID: " << medicalinvoice->medicalrid << endl
				<< "Medical Invoice Status: " << medicalinvoice->status << endl
				<< endl;

			medicalinvoice = medicalinvoice->next;

		} while (medicalinvoice != NULL);
	}
	else
		cout << "The medical invoice list is empty." << endl;
	return;
}

void ReviewCloseInvoice() {
	system("CLS");
	InvoiceFunction invoiceFunction;
	MedicalInvoice* medicalinvoices = invoiceFunction.getCloseInvoice();

	cout << "********** Review Close Status Medical Invoice **********" << endl;
	if (medicalinvoices != NULL)
	{
		MedicalInvoice* medicalinvoice = medicalinvoices;
		do
		{
			cout << "Medical Invoice ID: " << medicalinvoice->medicalinid << endl
				<< "Total Price (RM): " << medicalinvoice->totalprice << endl
				<< "Patient ID: " << medicalinvoice->patientid << endl
				<< "Medical Report ID: " << medicalinvoice->medicalrid << endl
				<< "Medical Invoice Status: " << medicalinvoice->status << endl
				<< endl;

			medicalinvoice = medicalinvoice->next;

		} while (medicalinvoice != NULL);
	}
	else
		cout << "The medical invoice list is empty." << endl;
	return;
}

void ReviewMedicalInvoiceByID() {
	system("CLS");
	string medicalinid;
	InvoiceFunction invoiceFunction;

	cout << "********** Review Medical Invoice By ID **********" << endl;
	cout << "Medical Invoice ID: ";
	cin >> medicalinid;

	system("CLS");
	MedicalInvoice* medicalinvoice = invoiceFunction.getInvoice(medicalinid);

	if (medicalinvoice != NULL)
	{
		cout << "Total Price (RM): " << medicalinvoice->totalprice << endl
			<< "Patient ID: " << medicalinvoice->patientid << endl
			<< "Medical Report ID: " << medicalinvoice->medicalrid << endl
			<< "Medical Invoice Status: " << medicalinvoice->status << endl << endl;
	}
	else
		cout << "Medical Invoice not found." << endl;

	InvoiceDetailFunction invoiceDetailFunction;
	InvoiceDetail* invoicedetails = invoiceDetailFunction.getInvoiceDetailMI(medicalinid);

	if (invoicedetails != NULL)
	{
		InvoiceDetail* invoicedetail = invoicedetails;
		do
		{
			cout << "Medical Invoice Detail ID: " << invoicedetail->medicalindeid << endl
				<< "Medication ID: " << invoicedetail->medicationid << endl
				<< "Quantity Required: " << invoicedetail->quantityrequired << endl
				<< endl;

			invoicedetail = invoicedetail->next;

		} while (invoicedetail != NULL);
	}
	else
		cout << "The medical invoice detail list is empty." << endl;

	return;
}

void ReviewMedicalInvoiceByReportID() {
	system("CLS");
	string medicalrid;
	InvoiceFunction invoiceFunction;

	cout << "********** Review Medical Invoice By Medical Report ID **********" << endl;
	cout << "Medical Report ID: ";
	cin >> medicalrid;

	system("CLS");
	MedicalInvoice* medicalinvoice = invoiceFunction.getInvoiceRID(medicalrid);

	if (medicalinvoice != NULL)
	{
		cout << "\nMedical Invoice ID: " << medicalinvoice->medicalinid << endl
			<< "Total Price (RM): " << medicalinvoice->totalprice << endl
			<< "Patient ID: " << medicalinvoice->patientid << endl
			<< "Medical Report ID: " << medicalinvoice->medicalrid << endl
			<< "Medical Invoice Status: " << medicalinvoice->status << endl << endl;

		InvoiceDetailFunction invoiceDetailFunction;
		InvoiceDetail* invoicedetails = invoiceDetailFunction.getInvoiceDetailMI(medicalinvoice->medicalinid);

		if (invoicedetails != NULL)
		{
			InvoiceDetail* invoicedetail = invoicedetails;
			do
			{
				cout << "Medical Invoice Detail ID: " << invoicedetail->medicalindeid << endl
					<< "Medication ID: " << invoicedetail->medicationid << endl
					<< "Quantity Required: " << invoicedetail->quantityrequired << endl
					<< endl;

				invoicedetail = invoicedetail->next;

			} while (invoicedetail != NULL);
		}
		else
			cout << "The medical invoice detail list is empty." << endl;
	}
	else
		cout << "Medical Invoice not found." << endl;

	return;

}

void ReviewAllMedicalInvoice() {
	system("CLS");
	InvoiceFunction invoiceFunction;
	MedicalInvoice* medicalinvoices = invoiceFunction.getInvoices();

	cout << "********** Review All Medical Invoice **********" << endl;
	if (medicalinvoices != NULL)
	{
		MedicalInvoice* medicalinvoice = medicalinvoices;
		do
		{
			cout << "Medical Invoice ID: " << medicalinvoice->medicalinid << endl
				<< "Total Price (RM): " << medicalinvoice->totalprice << endl
				<< "Patient ID: " << medicalinvoice->patientid << endl
				<< "Medical Report ID: " << medicalinvoice->medicalrid << endl
				<< "Medical Invoice Status: " << medicalinvoice->status << endl
				<< endl;

			medicalinvoice = medicalinvoice->next;

		} while (medicalinvoice != NULL);

	}
	else
		cout << "The medical invoice list is empty." << endl;
	return;
}

void AddMedication(string administrator) {
	try {
		system("CLS");
		Medication* medication = new Medication();
		MedicationFunction medicationFunction;

		cout << "********** Add Medicine **********" << endl;
		string a, b, c, d, e;
		Medication* medicationid = medicationFunction.getMedicationID();
		if (medicationid != NULL)
		{
			a = medicationid->medicationid;
			c = a.substr(1, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "C000" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "C00" + d;
			}
			else if (b >= 100 && b <= 999)
			{
				d = to_string(b);
				e = "C0" + d;
			}
			else
			{
				d = to_string(b);
				e = "C" + d;
			}
			medication->medicationid = e;
		}
		else
			medication->medicationid = "C0001";

		cout << "Name: ";
		getline(cin >> ws, medication->name);

		cout << "Detail: ";
		getline(cin >> ws, medication->detail);

		cout << "Unit: ";
		cin >> medication->unit;

		cout << "Unit Price (RM): ";
		cin >> medication->uPrice;

		medication->adminid = administrator;

		int status = medicationFunction.addMedication(medication);

		if (status != 0) {
			cout << "\nSuccessfully added a new medicine" << endl;

			cout << "\n********** Medicine For " << medication->medicationid << " **********" << endl;
			string mid = medication->medicationid;
			Medication* medications = medicationFunction.getMedication(mid);

			if (medications != NULL)
			{
				cout << "Medicine ID: " << medications->medicationid << endl
					<< "Name: " << medications->name << endl
					<< "Detail: " << medications->detail << endl
					<< "Unit: " << medications->unit << endl
					<< "Unit Price (RM): " << medications->uPrice << endl
					<< "Medicine created by " << medications->adminid << endl;
			}
		}
		else
			cout << "\nUnable to add a new medicine" << endl;
	}
	catch (...) {
		cout << "\nUnable to add a new medicine" << endl;
	}
	
	return;
}

void UpdateMedication(string administrator, int choose) {
	char selection;
	string test;
	if (choose == 1) {
		do {
			try {
				system("CLS");
				Medication* medication = new Medication();

				cout << "********** Update Medicine **********" << endl;

				cout << "Medicine ID: ";
				cin >> medication->medicationid;

				cout << "Name: ";
				getline(cin >> ws, medication->name);

				cout << "Detail: ";
				getline(cin >> ws, medication->detail);

				cout << "Unit: ";
				cin >> medication->unit;

				cout << "Unit Price (RM): ";
				cin >> medication->uPrice;

				medication->adminid = administrator;

				MedicationFunction medicationFunction;
				int status = medicationFunction.updateMedication(medication);

				if (status != 0) {
					cout << "\nSuccessfully updated the medicine." << endl;

					cout << "\n********** Medicine For " << medication->medicationid << " **********" << endl;
					string mid = medication->medicationid;
					Medication* medications = medicationFunction.getMedication(mid);

					if (medications != NULL)
					{
						cout << "Medicine ID: " << medications->medicationid << endl
							<< "Name: " << medications->name << endl
							<< "Detail: " << medications->detail << endl
							<< "Unit: " << medications->unit << endl
							<< "Unit Price (RM): " << medications->uPrice << endl
							<< "Medicine created by " << medications->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the medicine!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medicine!" << endl;
			}

			cout << "\nDo you want to continue update medicine? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medicine? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 2) {
		do {
			try {
				system("CLS");
				Medication* medication = new Medication();

				cout << "********** Update Medicine **********" << endl;

				cout << "Medicine ID: ";
				cin >> medication->medicationid;

				cout << "Name: ";
				getline(cin >> ws, medication->name);

				medication->adminid = administrator;

				MedicationFunction medicationFunction;
				int status = medicationFunction.updateMedicationName(medication);

				if (status != 0) {
					cout << "\nSuccessfully updated the medicine." << endl;

					cout << "\n********** Medicine For " << medication->medicationid << " **********" << endl;
					string mid = medication->medicationid;
					Medication* medications = medicationFunction.getMedication(mid);

					if (medications != NULL)
					{
						cout << "Medicine ID: " << medications->medicationid << endl
							<< "Name: " << medications->name << endl
							<< "Detail: " << medications->detail << endl
							<< "Unit: " << medications->unit << endl
							<< "Unit Price (RM): " << medications->uPrice << endl
							<< "Medicine created by " << medications->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the medicine!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medicine!" << endl;
			}

			cout << "\nDo you want to continue update medicine? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medicine? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 3) {
		do {
			try {
				system("CLS");
				Medication* medication = new Medication();

				cout << "********** Update Medicine **********" << endl;

				cout << "Medicine ID: ";
				cin >> medication->medicationid;

				cout << "Detail: ";
				getline(cin >> ws, medication->detail);

				medication->adminid = administrator;

				MedicationFunction medicationFunction;
				int status = medicationFunction.updateMedicationDetail(medication);

				if (status != 0) {
					cout << "\nSuccessfully updated the medicine." << endl;

					cout << "\n********** Medicine For " << medication->medicationid << " **********" << endl;
					string mid = medication->medicationid;
					Medication* medications = medicationFunction.getMedication(mid);

					if (medications != NULL)
					{
						cout << "Medicine ID: " << medications->medicationid << endl
							<< "Name: " << medications->name << endl
							<< "Detail: " << medications->detail << endl
							<< "Unit: " << medications->unit << endl
							<< "Unit Price (RM): " << medications->uPrice << endl
							<< "Medicine created by " << medications->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the medicine!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medicine!" << endl;
			}

			cout << "\nDo you want to continue update medicine? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medicine? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 4) {
		do {
			try {
				system("CLS");
				Medication* medication = new Medication();

				cout << "********** Update Medicine **********" << endl;

				cout << "Medicine ID: ";
				cin >> medication->medicationid;

				cout << "Unit: ";
				cin >> medication->unit;

				medication->adminid = administrator;

				MedicationFunction medicationFunction;
				int status = medicationFunction.updateMedicationUnit(medication);

				if (status != 0) {
					cout << "\nSuccessfully updated the medicine." << endl;

					cout << "\n********** Medicine For " << medication->medicationid << " **********" << endl;
					string mid = medication->medicationid;
					Medication* medications = medicationFunction.getMedication(mid);

					if (medications != NULL)
					{
						cout << "Medicine ID: " << medications->medicationid << endl
							<< "Name: " << medications->name << endl
							<< "Detail: " << medications->detail << endl
							<< "Unit: " << medications->unit << endl
							<< "Unit Price (RM): " << medications->uPrice << endl
							<< "Medicine created by " << medications->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the medicine!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medicine!" << endl;
			}

			cout << "\nDo you want to continue update medicine? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medicine? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 5) {
		do {
			try {
				system("CLS");
				Medication* medication = new Medication();

				cout << "********** Update Medicine **********" << endl;

				cout << "Medicine ID: ";
				cin >> medication->medicationid;

				cout << "Unit Price (RM): ";
				cin >> medication->uPrice;

				medication->adminid = administrator;

				MedicationFunction medicationFunction;
				int status = medicationFunction.updateMedicationPrice(medication);

				if (status != 0) {
					cout << "\nSuccessfully updated the medicine." << endl;

					cout << "\n********** Medicine For " << medication->medicationid << " **********" << endl;
					string mid = medication->medicationid;
					Medication* medications = medicationFunction.getMedication(mid);

					if (medications != NULL)
					{
						cout << "Medicine ID: " << medications->medicationid << endl
							<< "Name: " << medications->name << endl
							<< "Detail: " << medications->detail << endl
							<< "Unit: " << medications->unit << endl
							<< "Unit Price (RM): " << medications->uPrice << endl
							<< "Medicine created by " << medications->adminid << endl;
					}
				}
				else
					cout << "\nUnable to update the medicine!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medicine!" << endl;
			}

			cout << "\nDo you want to continue update medicine? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medicine? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
}

void DeleteMedication() {
	try {
		system("CLS");

		Medication* medication = new Medication();

		cout << "Medicine ID: ";
		cin >> medication->medicationid;

		MedicationFunction medicationFunction;
		int status = medicationFunction.deleteMedication(medication);
		if (status != 0)
			cout << "\nSuccessfully deleted the medicine." << endl;
		else
			cout << "\nUnable to delete the medicine!" << endl;
	}
	catch (...) {
		cout << "\nUnable to delete the medicine!" << endl;
	}

	return;
}

void ReviewMedicationByID() {
	system("CLS");
	string medicationid;
	MedicationFunction medicationFunction;

	cout << "******************** Review Medicine By ID ********************" << endl;
	cout << "Medicine ID: ";
	cin >> medicationid;

	Medication* medication = medicationFunction.getMedication(medicationid);

	system("CLS");
	if (medication != NULL)
	{
		cout << "Name: " << medication->name << endl
			<< "Detail: " << medication->detail << endl
			<< "Unit: " << medication->unit << endl
			<< "Unit Price (RM): " << medication->uPrice << endl
			<< "Medicine created by " << medication->adminid << endl;
	}
	else
		cout << "Medicine not found." << endl;
	return;
}

void ReviewAllMedication() {
	system("CLS");
	MedicationFunction medicationFunction;
	Medication* medications = medicationFunction.getMedications();

	if (medications != NULL)
	{
		Medication* medication = medications;
		do
		{
			cout << "Medicine ID: " << medication->medicationid << endl
				<< "Name: " << medication->name << endl
				<< "Detail: " << medication->detail << endl
				<< "Unit: " << medication->unit << endl
				<< "Unit Price (RM): " << medication->uPrice << endl
				<< "Medicine created by " << medication->adminid << endl
				<< endl;

			medication = medication->next;

		} while (medication != NULL);
	}
	else
		cout << "The medicine list is empty." << endl;
	return;
}

void AddInvoiceDetail() {
	try {
		system("CLS");
		InvoiceDetail* invoicedetail = new InvoiceDetail();
		InvoiceDetailFunction invoiceDetailFunction;

		cout << "********** Add Medical Invoice Detail **********" << endl;
		string a, b, c, d, e;
		InvoiceDetail* invoicedetailid = invoiceDetailFunction.getInvoiceDetailID();
		if (invoicedetailid != NULL)
		{
			a = invoicedetailid->medicalindeid;
			c = a.substr(2, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "ID00" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "ID0" + d;
			}
			else
			{
				d = to_string(b);
				e = "ID" + d;
			}
			invoicedetail->medicalindeid = e;
		}
		else
			invoicedetail->medicalindeid = "ID001";

		cout << "Medical Invoice ID: ";
		cin >> invoicedetail->medicalinid;

		cout << "Medicine ID: ";
		cin >> invoicedetail->medicationid;

		cout << "Quantity Required: ";
		cin >> invoicedetail->quantityrequired;

		int status = invoiceDetailFunction.addInvoiceDetail(invoicedetail);

		if (status != 0) {
			cout << "\nSuccessfully added a new medical invoice detail." << endl;

			cout << "\n********** Medical Invoice Detail For " << invoicedetail->medicalindeid << " **********" << endl;
			string iid = invoicedetail->medicalindeid;
			InvoiceDetail* invoicedetails = invoiceDetailFunction.getInvoiceDetail(iid);

			if (invoicedetails != NULL)
			{
				cout << "Medical Invoice Detail ID: " << invoicedetails->medicalindeid << endl
					<< "Quantity Required: " << invoicedetails->quantityrequired << endl
					<< "Medical Invoice ID: " << invoicedetails->medicalinid << endl
					<< "Medication ID: " << invoicedetails->medicationid << endl;
			}
		}
		else
			cout << "\nUnable to add a new medical invoice detail!" << endl;
	}
	catch (...) {
		cout << "\nUnable to add a new medical invoice detail!" << endl;
	}
	return;
}

void UpdateInvoiceDetail(int choose) {
	char selection;
	string test;
	if (choose == 1) {
		do {
			try {
				system("CLS");
				int tprice = 0;
				InvoiceDetail* invoicedetail = new InvoiceDetail();
				cout << "********** Update Medical Invoice Detail **********" << endl;
				cout << "Medical Invoice Detail ID: ";
				cin >> invoicedetail->medicalindeid;

				cout << "Medical Invoice ID: ";
				cin >> invoicedetail->medicalinid;

				cout << "Medicine ID: ";
				cin >> invoicedetail->medicationid;

				cout << "Quantity Required: ";
				cin >> invoicedetail->quantityrequired;


				InvoiceDetailFunction invoiceDetailFunction;
				int status = invoiceDetailFunction.updateInvoiceDetail(invoicedetail);

				if (status != 0) {
					cout << "\nSuccessfully updated the medical invoice detail." << endl;

					string iid = invoicedetail->medicalindeid;
					InvoiceDetail* invoicedetails = invoiceDetailFunction.getInvoiceDetail(iid);
					cout << "\n********** Medical Invoice Detail For " << invoicedetail->medicalindeid << " **********" << endl;
					if (invoicedetails != NULL)
					{
						cout << "Medical Invoice Detail ID: " << invoicedetails->medicalindeid << endl
							<< "Quantity Required: " << invoicedetails->quantityrequired << endl
							<< "Medical Invoice ID: " << invoicedetails->medicalinid << endl
							<< "Medicine ID: " << invoicedetails->medicationid << endl;
					}

					string mid = invoicedetails->medicalinid;
					InvoiceDetail* invoicedetailupdate = invoiceDetailFunction.getInvoiceDetailMI(mid);
					if (invoicedetailupdate != NULL)
					{
						InvoiceDetail* invoicedetail1 = invoicedetailupdate;
						do
						{
							MedicationFunction medicationFunction;
							Medication* medication = medicationFunction.getMedication(invoicedetail1->medicationid);
							if (medication != NULL) {
								tprice = tprice + (medication->uPrice * invoicedetail1->quantityrequired);
							}

							invoicedetail1 = invoicedetail1->next;

						} while (invoicedetail1 != NULL);

					}

					MedicalInvoice* medicalinvoiceU = new MedicalInvoice();
					medicalinvoiceU->totalprice = tprice;
					medicalinvoiceU->medicalinid = invoicedetails->medicalinid;
					InvoiceFunction invoiceFunction;
					invoiceFunction.updateInvoicePrice(medicalinvoiceU);
				}
				else
					cout << "\nUnable to update the medical invoice detail!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medical invoice detail!" << endl;
			}

			cout << "\nDo you want to continue update medical invoice detail? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medical invoice detail? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
	else if (choose == 2) {
		do {
			try {
				int tprice = 0;
				string mid;
				system("CLS");
				InvoiceDetail* invoicedetail = new InvoiceDetail();
				cout << "********** Update Medical Invoice Detail **********" << endl;
				cout << "Medical Invoice Detail ID: ";
				cin >> invoicedetail->medicalindeid;

				cout << "Medicine ID: ";
				cin >> invoicedetail->medicationid;

				cout << "Quantity Required: ";
				cin >> invoicedetail->quantityrequired;

				InvoiceDetailFunction invoiceDetailFunction;
				int status = invoiceDetailFunction.updateInvoiceDetailMedicine(invoicedetail);

				if (status != 0) {
					cout << "\nSuccessfully updated the medical invoice detail." << endl;

					string iid = invoicedetail->medicalindeid;
					InvoiceDetail* invoicedetails = invoiceDetailFunction.getInvoiceDetail(iid);
					cout << "\n********** Medical Invoice Detail For " << invoicedetail->medicalindeid << " **********" << endl;
					if (invoicedetails != NULL)
					{
						cout << "Medical Invoice Detail ID: " << invoicedetails->medicalindeid << endl
							<< "Quantity Required: " << invoicedetails->quantityrequired << endl
							<< "Medical Invoice ID: " << invoicedetails->medicalinid << endl
							<< "Medicine ID: " << invoicedetails->medicationid << endl;

						mid = invoicedetails->medicalinid;
					}

					InvoiceDetail* invoicedetailupdate = invoiceDetailFunction.getInvoiceDetailMI(mid);
					if (invoicedetailupdate != NULL)
					{
						InvoiceDetail* invoicedetail1 = invoicedetailupdate;
						do
						{
							MedicationFunction medicationFunction;
							Medication* medication = medicationFunction.getMedication(invoicedetail1->medicationid);
							if (medication != NULL) {
								tprice = tprice + (medication->uPrice * invoicedetail1->quantityrequired);
							}

							invoicedetail1 = invoicedetail1->next;

						} while (invoicedetail1 != NULL);

					}

					MedicalInvoice* medicalinvoiceU = new MedicalInvoice();
					medicalinvoiceU->totalprice = tprice;
					medicalinvoiceU->medicalinid = mid;
					InvoiceFunction invoiceFunction;
					invoiceFunction.updateInvoicePrice(medicalinvoiceU);

				}
				else
					cout << "\nUnable to update the medical invoice detail!" << endl;
			}
			catch (...) {
				cout << "\nUnable to update the medical invoice detail!" << endl;
			}

			cout << "\nDo you want to continue update medical invoice detail? (Y/N) ";
			cin >> test;
			test[0] = toupper(test[0]);
			while (test != "Y" && test != "N") {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue update medical invoice detail? (Y/N) ";
				cin >> test;
				test[0] = toupper(test[0]);
			}
			selection = test[0];

		} while (selection == 'Y');
	}
}

void DeleteInvoiceDetail() {
	try {
		system("CLS");

		InvoiceDetail* invoicedetail = new InvoiceDetail();
		cout << "********** Delete Medical Invoice **********" << endl;
		cout << "Medical Invoice Detail ID: ";
		cin >> invoicedetail->medicalindeid;

		InvoiceDetailFunction invoiceDetailFunction;
		int status = invoiceDetailFunction.deleteInvoiceDetail(invoicedetail);
		if (status != 0)
			cout << "\nSuccessfully deleted the medical invoice detail." << endl;
		else
			cout << "\nUnable to delete the medical invoice detail!" << endl;
	}
	catch (...) {
		cout << "\nUnable to delete the medical invoice detail!" << endl;
	}

	return;
}

void ReviewInvoiceDetailByID() {
	system("CLS");
	string medicalindeid;
	InvoiceDetailFunction invoiceDetailFunction;

	cout << "********** Review Medical Invoice Detail By ID **********" << endl;
	cout << "Medical Invoice Detail ID: ";
	cin >> medicalindeid;

	InvoiceDetail* invoicedetail = invoiceDetailFunction.getInvoiceDetail(medicalindeid);

	if (invoicedetail != NULL)
	{
		cout << "Quantity Required: " << invoicedetail->quantityrequired << endl
			<< "Medical Invoice ID: " << invoicedetail->medicalinid << endl
			<< "Medicine ID: " << invoicedetail->medicationid << endl;
	}
	else
		cout << "Medical invoice detail not found." << endl;
	return;
}

void ReviewAllInvoiceDetail() {
	system("CLS");
	InvoiceDetailFunction invoiceDetailFunction;
	InvoiceDetail* invoicedetails = invoiceDetailFunction.getInvoiceDetails();
	cout << "********** Review All Medical Invoice Detail **********" << endl;
	if (invoicedetails != NULL)
	{
		InvoiceDetail* invoicedetail = invoicedetails;
		do
		{
			cout << "Medical Invoice Detail ID: " << invoicedetail->medicalindeid << endl
				<< "Quantity Required: " << invoicedetail->quantityrequired << endl
				<< "Medical Invoice ID: " << invoicedetail->medicalinid << endl
				<< "Medicine ID: " << invoicedetail->medicationid << endl
				<< endl;

			invoicedetail = invoicedetail->next;

		} while (invoicedetail != NULL);
	}
	else
		cout << "The medical invoice detail list is empty." << endl;
	return;
}

void AddPayment() {
	try {
		system("CLS");

		cout << "********** Add Payment **********" << endl;
		time_t rawtime;
		tm* timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

		string dt = buffer;

		PaymentReport* paymentreport = new PaymentReport();
		PaymentFunction paymentFunction;

		string a, b, c, d, e;
		PaymentReport* paymentid = paymentFunction.getPaymentID();
		if (paymentid != NULL)
		{
			a = paymentid->paymentid;
			c = a.substr(2, 4);
			d, e;
			int b = stoi(c) + 1;
			if (b >= 0 && b <= 9)
			{
				d = to_string(b);
				e = "PY00" + d;
			}
			else if (b >= 10 && b <= 99)
			{
				d = to_string(b);
				e = "PY0" + d;
			}
			else
			{
				d = to_string(b);
				e = "PY" + d;
			}
			paymentreport->paymentid = e;
		}
		else
			paymentreport->paymentid = "PY001";

		paymentreport->datetime = dt;

		cout << "Medical Invoice ID: ";
		cin >> paymentreport->medicalinid;

		string id = paymentreport->medicalinid;

		InvoiceFunction invoicefunction;
		MedicalInvoice* medicalInvoice = invoicefunction.getInvoice(id);
		double price = medicalInvoice->totalprice;

		paymentreport->patientid = medicalInvoice->patientid;

		cout << "Total Payment (RM): ";
		cin >> paymentreport->totalpayment;
		double payment = paymentreport->totalpayment;

		paymentreport->totalchange = payment - price;

		paymentreport->totalprice = price;

		int status = paymentFunction.addPaymentReport(paymentreport);

		MedicalInvoice* medicalinvoice = new MedicalInvoice();

		medicalinvoice->totalprice = medicalInvoice->totalprice;
		medicalinvoice->patientid = medicalInvoice->patientid;
		medicalinvoice->medicalrid = medicalInvoice->medicalrid;
		medicalinvoice->medicalinid = medicalInvoice->medicalinid;
		medicalinvoice->status = 1;

		InvoiceFunction invoiceFunction;
		invoiceFunction.updateInvoice(medicalinvoice);

		if (status != 0) {
			cout << "\nSuccessfully added a new payment report." << endl;

			cout << "\n********** Payment Report For " << paymentreport->paymentid << " **********" << endl;
			string pid = paymentreport->paymentid;
			PaymentReport* paymentreports = paymentFunction.getPaymentReport(pid);

			if (paymentreports != NULL)
			{
				cout << "Payment Report ID: " << paymentreports->paymentid << endl
					<< "Patient ID: " << paymentreports->patientid << endl
					<< "Medical Invoice ID: " << paymentreports->medicalinid << endl
					<< "Date Time: " << paymentreports->datetime << endl
					<< "Total Price (RM): " << paymentreports->totalprice << endl
					<< "Total Payment (RM): " << paymentreports->totalpayment << endl
					<< "Total Change (RM): " << paymentreports->totalchange << endl;
			}
		}
		else
			cout << "\nUnable to add a new payment report!" << endl;
	}
	catch (...) {
		cout << "\nUnable to add a new payment report!" << endl;
	}

	return;
}

void UpdatePayment() {
	try {
		system("CLS");

		cout << "********** Update Payment **********" << endl;
		time_t rawtime;
		tm* timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

		string dt = buffer;

		PaymentReport* paymentreport = new PaymentReport();

		paymentreport->datetime = dt;

		cout << "Payment Report ID: ";
		cin >> paymentreport->paymentid;

		cout << "Medical Invoice ID: ";
		cin >> paymentreport->medicalinid;

		string id = paymentreport->medicalinid;
		InvoiceFunction invoicefunction;
		MedicalInvoice* medicalInvoice = invoicefunction.getPrice(id);
		double price = medicalInvoice->totalprice;

		paymentreport->patientid = medicalInvoice->patientid;

		cout << "Total Payment (RM): ";
		cin >> paymentreport->totalpayment;
		double payment = paymentreport->totalpayment;

		paymentreport->totalchange = payment - price;

		paymentreport->totalprice = price;

		PaymentFunction paymentFunction;
		int status = paymentFunction.updatePaymentReport(paymentreport);

		if (status != 0) {
			cout << "\nSuccessfully updated the payment report." << endl;

			cout << "\n********** Payment Report For " << paymentreport->paymentid << " **********" << endl;
			string pid = paymentreport->paymentid;
			PaymentReport* paymentreports = paymentFunction.getPaymentReport(pid);

			if (paymentreports != NULL)
			{
				cout << "Payment Report ID: " << paymentreports->paymentid << endl
					<< "Patient ID: " << paymentreports->patientid << endl
					<< "Medical Invoice ID: " << paymentreports->medicalinid << endl
					<< "Date Time: " << paymentreports->datetime << endl
					<< "Total Price (RM): " << paymentreports->totalprice << endl
					<< "Total Payment (RM): " << paymentreports->totalpayment << endl
					<< "Total Change (RM): " << paymentreports->totalchange << endl;
			}
		}
		else
			cout << "\nUnable to update the payment report!" << endl;
	}
	catch (...) {
		cout << "\nUnable to update the payment report!" << endl;
	}
	return;
}

void DeletePayment() {
	try {
		system("CLS");

		cout << "********** Delete Payment **********" << endl;
		PaymentReport* paymentreport = new PaymentReport();

		cout << "Payment Report ID: ";
		cin >> paymentreport->paymentid;

		PaymentFunction paymentFunction;
		int status = paymentFunction.deletePaymentReport(paymentreport);
		if (status != 0)
			cout << "\nSuccessfully deleted the payment report." << endl;
		else
			cout << "\nUnable to delete the payment report!" << endl;
	}
	catch (...) {
		cout << "\nUnable to delete the payment report!" << endl;
	}

	return;
}

void ReviewPaymentByID() {
	system("CLS");
	string paymentid;
	PaymentFunction paymentFunction;

	cout << "********** Review Payment Report By ID **********" << endl;
	cout << "Payment Report ID: ";
	cin >> paymentid;

	PaymentReport* paymentreport = paymentFunction.getPaymentReport(paymentid);

	if (paymentreport != NULL)
	{
		cout << "Patient ID: " << paymentreport->patientid << endl
			<< "Medical Invoice ID: " << paymentreport->medicalinid << endl
			<< "Date Time: " << paymentreport->datetime << endl
			<< "Total Price (RM): " << paymentreport->totalprice << endl
			<< "Total Payment (RM): " << paymentreport->totalpayment << endl
			<< "Total Change (RM): " << paymentreport->totalchange << endl;
	}
	else
		cout << "Payment report not found." << endl;
	return;
}

void ReviewAllPayment() {
	system("CLS");
	PaymentFunction paymentFunction;
	PaymentReport* paymentreports = paymentFunction.getPaymentReports();

	cout << "********** Review All Payment **********" << endl;
	if (paymentreports != NULL)
	{
		PaymentReport* paymentreport = paymentreports;
		do
		{
			cout << "Payment Report ID: " << paymentreport->paymentid << endl
				<< "Patient ID: " << paymentreport->patientid << endl
				<< "Medical Invoice ID: " << paymentreport->medicalinid << endl
				<< "Date Time: " << paymentreport->datetime << endl
				<< "Total Price (RM): " << paymentreport->totalprice << endl
				<< "Total Payment (RM): " << paymentreport->totalpayment << endl
				<< "Total Change (RM): " << paymentreport->totalchange << endl
				<< endl;

			paymentreport = paymentreport->next;

		} while (paymentreport != NULL);
	}
	else
		cout << "The payment report list is empty." << endl;
	return;
}

void ReviewGenderStat() 
{
	system("CLS");
	StatisticReport statisticReport;
	Statistic* statistic = statisticReport.getGenderStat();
	if (statistic != NULL)
	{
		cout << "******* Patient Statistic Report *******" << endl << endl
			<< "MALE\t\tFEMALE\t\tTOTAL" << endl
			<< statistic->male << "\t\t" << statistic->female << "\t\t" << statistic->totalpatient << endl << endl
			<< "There are " << statistic->totalpatient << " patients in the system." << endl
			<< statistic->male << " patients are male and " << statistic->female << " are female." << endl;

		int gender[2];
		gender[0] = statistic->male * 100/statistic->totalpatient;
		gender[1] = statistic->female *100/statistic->totalpatient;

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "\n\n----------------------- Bar Chart Of Percentage Of Patient Gender -----------------------" << endl << endl;
		cout << "Male\t";
		for (int i = 0; i < gender[0]; i++) {
			SetConsoleTextAttribute(hConsole, 11);
			cout << "*";
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << endl;
		cout << "Female\t";
		for (int j = 0; j < gender[1]; j++) {
			SetConsoleTextAttribute(hConsole, 14);
			cout << "*";
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << endl << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
	}
	else
		cout << "There are no patient in the system." << endl;

	return;
}

void ReviewMedicineStat()
{
	system("CLS");
	int i = 0;
	StatisticReport statisticReport;
	Statistic* statistics = statisticReport.getTopMedicine();
	if (statistics != NULL)
	{
		Statistic* statistic = statistics;
		cout << "************* Top 3 Medicine *************" << endl << endl;
		do {
			cout << "Top " << ++i << endl
				<< "Medicine ID: " << statistic->medicineid << endl
				<< "Medicine Name: " << statistic->mediname << endl
				<< "Number of Sold: " << statistic->mediquan << endl
				<< endl;

			statistic = statistic->next;

		} while (statistic != NULL);
	}
	else
		cout << "There are not any medicine have been sold." << endl;
	return;
}

void ReviewProfitStat(int choose)
{
	char selection;
	if (choose == 1) {
		do {
			system("CLS");
			string stdate;
			StatisticReport statisticReport;

			cout << "************************ Profit Statistic ************************" << endl << endl;
			cout << "Enter the year that you want the view." << endl;
			cout << "Year: ";
			cin >> stdate;
			Statistic* statistic = statisticReport.getProfitYear(stdate);
			if (statistic != NULL)
			{
				cout << endl;
				cout << "NUMBER_OF_PAYMENT\t\tPROFIT (RM)" << endl
					<< "\t" << statistic->numpay << "\t\t\t" << statistic->profit << endl << endl;
				cout << "There are " << statistic->numpay << " payment have been made in " << stdate << "." << endl
					<< "The total profit in " << stdate << " is RM" << statistic->profit << endl;

				Statistic* statisticinfos = statisticReport.getProfitYearInfo(stdate);
				if (statisticinfos != NULL) {
					cout << "\n\n************************* Profit Detail ************************" << endl << endl;
					cout << "PAYMENT ID\t\tPATIENT ID\t\tTOTAL PRICE (RM)" << endl;
					Statistic* statisticinfo = statisticinfos;
					do {
						cout << statisticinfo->paymentid << "\t\t\t" << statisticinfo->patientid << "\t\t\t" << statisticinfo->price << endl;
						statisticinfo = statisticinfo->next;

					} while (statisticinfo != NULL);
				}

			}
			else
				cout << "Unable to find the profit statistic for this duration." << endl;

			cout << "\nDo you want to continue review this statistic report? (Y/N) ";
			cin >> selection;
			selection = toupper(selection);
			while (selection != 'Y' && selection != 'N') {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue review this statistic report? (Y/N) ";
				cin >> selection;
				selection = toupper(selection);
			}
		} while (selection == 'Y');
	}
	else if (choose == 2) {
		do {
			system("CLS");
			string stdate, stmonth;
			StatisticReport statisticReport;

			cout << "************************ Profit Statistic ************************" << endl << endl;
			cout << "Enter the year that you want the view." << endl;
			cout << "Year: ";
			cin >> stdate;
			cout << "Month: ";
			cin >> stmonth;
			Statistic* statistic = statisticReport.getProfitMonth(stdate,stmonth);
			if (statistic != NULL)
			{
				cout << endl;
				cout << "NUMBER_OF_PAYMENT\t\tPROFIT (RM)" << endl
					<< "\t" << statistic->numpay << "\t\t\t" << statistic->profit << endl << endl;
				cout << "There are " << statistic->numpay << " payment have been made in " << stdate << "-" << stmonth << "." << endl
					<< "The total profit in " << stdate << "-" << stmonth << " is RM" << statistic->profit << endl;

				Statistic* statisticinfos = statisticReport.getProfitMonthInfo(stdate,stmonth);
				if (statisticinfos != NULL) {
					cout << "\n\n************************* Profit Detail ************************" << endl << endl;
					cout << "PAYMENT ID\t\tPATIENT ID\t\tTOTAL PRICE (RM)" << endl;
					Statistic* statisticinfo = statisticinfos;
					do {
						cout << statisticinfo->paymentid << "\t\t\t" << statisticinfo->patientid << "\t\t\t" << statisticinfo->price << endl;
						statisticinfo = statisticinfo->next;

					} while (statisticinfo != NULL);
				}
			}
			else
				cout << "Unable to find the profit statistic for this duration." << endl;

			cout << "\nDo you want to continue review this statistic report? (Y/N) ";
			cin >> selection;
			selection = toupper(selection);
			while (selection != 'Y' && selection != 'N') {
				cout << "You entered an invalid character. Please enter again. " << endl;
				cout << "Do you want to continue review this statistic report? (Y/N) ";
				cin >> selection;
				selection = toupper(selection);
			}
		} while (selection == 'Y');
	}
	return;
}
