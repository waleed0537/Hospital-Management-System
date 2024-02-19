#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class User {
protected:
	char UserName[20];
	char Password[20];
	char CNIC[20];
	char Email[20];
	char YearsOfExperience[20];
	char SpecializationArea[20];
	char HospitalName[20];
	char AvailablityHours[20];
	char City[20];
	char HourlyCharge[20];
public:
	User();
	User(char n[20], char n1[20], char n2[20], char n3[20], char n4[15], char n5[15], char n6[15], char n7[15], char n8[15], char n9[15]);
	bool AlreadyAvailablePatient(string p);
	bool AlreadyAvailableDoctor(string p);
	void RegisterPatient();
	void RegisterDoctor();
	void getData();
	void Menu();
	void display(User);
	string getName();
	void setName(string);
	bool AlreadyAvailable(string);
	User DoctorRegisterationMenu();
	User PatientRegisterationMenu();
	bool checkPassword(string pass);
	void Read(string);
	User AdminRegisterationMenu();
	bool AlreadyAvailableAdmin(string);
	void RegisterAdmin();
	void Menu1();
	void AdminLogin();
	User AdminLoginData();
	void DoctorLogin();
	User DoctorLoginData();
	bool PatientLoginCheck(string, string);
	bool AdminLoginCheck(string, string);
	User PatientLoginData();
	void PatientLogin();
	void my_read(string file_name);
	User DoctorLoginCheck(string, string);
	virtual void ExtraDataPat() {}
	virtual void ExtraDataDoc() {}
	virtual void ExtraDataAdm() {}
	virtual void SearchDoctor() {}
	//	virtual	void CheckAvailability(){}
		//virtual void display(){}
}u;
using namespace std;
class Patient : public User {
public:
	void ExtraDataPat();
	void SearchDoctor();
	void CheckAvailability(string);
	void CheckAppointment();
	void PhysicalConsultations();
	void OnlineConsultations(string);
};
class Doctor : public User {

public:
	void ExtraDataDoc();
	virtual void count() {}
	void checkSpeicializaion();
//	virtual void Payment();
};

class Admin : public User {
public:
	void ExtraDataAdm();
	void AddDoctorData();
	void EditDoctorData();
};
class Appointment {
public:

};
class Feedback : public User{
	float rating;
	string review;
	public:
	void take_Feedback(string);
};
class Gynecologist :public Doctor {
public:
	void count();
};
class Dermatologist :public Doctor {
public:
	void count();
};
class Oncologist :public Doctor {
public:
	void count();
};
class Orthopedic :public Doctor {
public:
	void count();
};
class Surgen :public Doctor {
public:
	void count();
};
