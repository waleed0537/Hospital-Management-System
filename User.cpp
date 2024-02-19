	#include<iostream>
	#include"User.h"
	#include<cstring>
	#include<fstream>
	#include<iomanip>
	#include<string.h>
	using namespace std;
	// Default Constructor for User class
	User::User() {
		strcpy(UserName, "NO NAME");
		strcpy(Password, "NOPASS");
		strcpy(CNIC, "NOCNIC");
		strcpy(Email, "NOEMAIL");
		strcpy(YearsOfExperience, "NO Experience");
		strcpy(SpecializationArea, "NO Specialization");
		strcpy(HospitalName, "NO hospital");
		strcpy(AvailablityHours, "No Availability");
		strcpy(City, "No city");
		strcpy(HourlyCharge, "Free :)");
	}
	//User::User() {
	//	strcpy(UserName, "NO NAME");
	//	strcpy(Password, "NOPASS");
	//	strcpy(CNIC, "NOCNIC");
	//	strcpy(Email, "NOEMAIL");
	//}
	// setter for username
	/*void User::setName(string p) {
		/*strcpy(UserName, p);
	}*/
	// getter for username
	string User::getName() {
		return UserName;
	}
	// Parameterized Constructor
	//User::User(char n[15], char n1[15], char n2[15], char n3[15]) {
	//	strcpy(UserName, n);
	//	strcpy(Password, n1);
	//	strcpy(CNIC, n2);
	//	strcpy(Email, n3);
	//}
	User::User(char n[15], char n1[15], char n2[15], char n3[15], char n4[15], char n5[15], char n6[15], char n7[15], char n8[15], char n9[15]) {
		strcpy(UserName, n);
		strcpy(Password, n1);
		strcpy(CNIC, n2);
		strcpy(Email, n3);
		strcpy(YearsOfExperience, n4);
		strcpy(SpecializationArea, n5);
		strcpy(HospitalName, n6);
		strcpy(AvailablityHours, n7);
		strcpy(City, n8);
		strcpy(HourlyCharge, n9);
	}
	void User::RegisterAdmin() {
		ofstream fout;
		fout.open("Admin.dat",ios::out|ios::app|ios::binary);
		User newUser3 = AdminRegisterationMenu();
		fout.write((char*)&newUser3, sizeof(User));
		fout.close();
		cout << "You are registered successfully...." << endl;
	}
	// Function to register the Doctor's data
	void User::RegisterDoctor() {
		ofstream fout;
		fout.open("Doctor.dat", ios::out | ios::app | ios::binary);
		User newUser = DoctorRegisterationMenu();
	//	User user;
	//	Doctor d;
	//	user = &d;
		cout << "You are successfully registered. Please enter this information.." << endl;
		//user->DoctorExtraData();
	    //user->display();
		fout.write((char*)&newUser, sizeof(User));
		//fout.write((char*)&user, sizeof(User));
		fout.close();
		cout << "You are registered successfully...." << endl;
	}	
	// Function to register the patient's data
	void User::RegisterPatient() {
		ofstream fout;
		fout.open("Patient.dat", ios::out | ios::app | ios::binary);
	//	u.getData();
		User newUser1 = PatientRegisterationMenu();
		fout.write((char*)&newUser1, sizeof(User));
		fout.close();
		cout << "You are registered successfully...." << endl;
		
		system("pause");
	}
	// Overall menu to ask user's choice
	void User::Menu() {
	
		cout << "0.  Exit" << endl;
		cout << "1.  Register as an Doctor " << endl;
		cout << "2.  Register as an Admin " << endl;
		cout << "3.  Register as an Patient " << endl;
	}
	// Function to as doctor if he wants to register via cnic or email
	User User::DoctorRegisterationMenu() {
		int a1 = 0;
		cout << "Do you want to register/sign up via Email or CNIC? " << endl;
		cout << "1.  Press 1 to register via Email..." << endl;
		cout << "2.  Press 2 to register via CNIC..." << endl;
		cin >> a1;
		char uname[15], pass[15], cnic[15], email[15],years[15],specialization[15],hospital[15],availability[15],city[15],hours[15];
		cout.setf(ios::left);
		if (a1 == 1) {
			bool upper1 = false;
			bool lower1 = false;
			bool digit1 = false;
			bool special1 = false;
			int flag = 0;
			ifstream fin;
			fin.open("Doctor.dat", ios::in | ios::binary);
			cout << "1.  Enter your name: " << endl;
			cin >> uname;
			bool status = AlreadyAvailableDoctor(uname);
			if (status) {
				cout << "Already Exist!..." << endl;
				cin >> uname;
			}
			else if(!status)
				cout << "2.  Enter your password: " << endl;
				cin >> Password;
			jump1:
				cout << "Invalid Password! Please enter your password again!.." << endl;
				cin >> Password;
				int size1 = strlen(Password);
				for (int i = 0; i < sizeof(Password); i++) {
					if (Password[i] >= 32 && Password[i] <= 47 || Password[i] >= 58 && Password[i] <= 95) {
						special1 = true;
					}
					if (Password[i] >= 48 && Password[i] <= 57) {
						digit1 = true;
					}
					if (Password[i] >= 65 && Password[i] <= 90) {
						upper1 = true;
					}
					if (Password[i] >= 97 && Password[i] <= 122) {
						lower1 = true;
					}
				}
				if (special1 == true && lower1 == true && upper1 == true && size1 == 8) {
					strcpy(pass, Password);
					cout << "3.  Enter your Email: " << endl;
					cin >> email;
					
				}
				else {
					if (!upper1 || !lower1 || !special1 || !digit1 || size1 != 8) {
						goto jump1;
					}
				}
				cout << "1.  Please enter your experience years: " << endl;
				cin >> YearsOfExperience;
				cout << "2.  Please enter your Specialization Area: " << endl;
				cin >> SpecializationArea;
				cout << "3.  Please enter your Availability Hours: " << endl;
				cin >> HospitalName;
				cout << "4.  Please enter your Hospital Name: " << endl;
				cin >> AvailablityHours;
				cout << "5.  Please enter your city name: " << endl;
				cin >> City;
				cout << "6.  Please enter your Hourly Charge: " << endl;
				cin >> HourlyCharge;
			//	if(SpecializationArea == "Dermatologist" || SpecializationArea =="dermatologist"||SpecializationArea =="DERMATOLOGIST"){
				//	d->count();
			//	}
				strcpy(years, YearsOfExperience);
				strcpy(specialization, SpecializationArea);
				strcpy(hospital, AvailablityHours);
				strcpy(availability, HospitalName);
				strcpy(city, City);
				strcpy(hours, HourlyCharge);
				strcpy(cnic, "NO CNIC");
				User newUser(uname, pass, cnic, email,years,specialization,availability,hospital,city,hours);
				return newUser;
		}
		else if (a1 == 2) {
			bool upper = false;
			bool lower = false;
			bool digit = false;
			bool special = false;
			ifstream fin;
			fin.open("Doctor.dat", ios::in | ios::binary);
			cout << "1.  Enter your name: " << endl;
			cin >> uname;
			bool status = AlreadyAvailableDoctor(uname);
			if (status) {
				cout << "Already Exist!..." << endl;
				cin >> uname;
			}
			else if (!status)
			cout << "2.  Enter your password: " << endl;
			cin >> Password;
	
		jump:
			cout << "Invalid Password! Please enter your password again!.." << endl;
			cin >> Password;
			int size = strlen(Password);
			for (int i = 0; i < sizeof(Password); i++) {
				if (Password[i] >= 32 && Password[i] <= 47 || Password[i] >= 58 && Password[i] <= 95) {
					special = true;
				}
				if (Password[i] >= 48 && Password[i] <= 57) {
					digit = true;
				}
				if (Password[i] >= 65 && Password[i] <= 90) {
					upper = true;
				}
				if (Password[i] >= 97 && Password[i] <= 122) {
					lower = true;
				}
			}
			if (special == true && lower == true && upper == true && size == 8) {
				strcpy(pass, Password);
				cout << "3.  Enter your CNIC: " << endl;
				cin >> cnic;
				int size2 = strlen(cnic);
				if (size2 != 13) {
					cout << "CNIC is invalid! Please enter the CNIC again!..." << endl;
					cin >> cnic;
					size2 = strlen(cnic);
					while (size2 != 13)
					{
						cout << "CNIC is invalid! Please enter the CNIC again!..." << endl;
						cin >> cnic;
						size2 = strlen(cnic);
					}
				}
			}
			else {
				if (!upper || !lower || !special || !digit || size != 8) {
					goto jump;
				}
			}
			cout << "1.  Please enter your experience years: " << endl;
			cin >> YearsOfExperience;
			cout << "2.  Please enter your Specialization Area: " << endl;
			cin >> SpecializationArea;
			cout << "3.  Please enter your Availability Hours: " << endl;
			cin >> AvailablityHours;
			cout << "4.  Please enter your Hospital Name: " << endl;
			cin >> HospitalName;
			cout << "5.  Please enter your city name: " << endl;
			cin >> City;
			cout << "6.  Please enter your Hourly Charge: " << endl;
			cin >> HourlyCharge;
			strcpy(years, YearsOfExperience);
			strcpy(specialization, SpecializationArea);
			strcpy(availability, AvailablityHours);
			strcpy(hospital, HospitalName);
			strcpy(city, City);
			strcpy(hours, HourlyCharge);
			strcpy(email, "NO Email");
			User newUser(uname, pass, cnic, email, years, specialization, availability, hospital, city, hours);
			return newUser;
		}
		return (User());
	}
	/// function to show polymorphic behavior

	// Function to check if the CNIC or Email is already available or not
	bool User::AlreadyAvailableDoctor(string p) {
		ifstream fin;
		fin.open("Doctor.dat", ios::in|ios::binary);
		User user;
		while (fin.read((char*)&user, sizeof(user))) {
		//	cout << p << " " << user.UserName << " \n";
			if (user.UserName == p)
	
				return true;
		}
		fin.close();
		return false;
	}
	bool User::AlreadyAvailablePatient(string p) {
		ifstream fin;
		fin.open("Patient.dat", ios::in|ios::binary);
		User user;
		while (fin.read((char*)&user, sizeof(user))) {
		//	cout << p << " " << user.UserName << " \n";
			if (user.UserName == p)
	
				return true;
		}
		fin.close();
		return false;
	}
	// Function to ask patient its details
	User User::PatientRegisterationMenu() {
		bool upper2 = false;
		bool lower2 = false;
		bool digit2 = false;
		bool special2 = false;
		char uname[15], pass[15], cnic[15], email[15], years[15], specialization[15], hospital[15], availability[15], city[15], hours[15];
		ifstream fin;
		fin.open("Patient.dat", ios::in | ios::binary);
		cout << "1.  Enter your name: " << endl;
		cin >> uname;
		bool status = AlreadyAvailablePatient(uname);
		if (status) {
			cout << "Already Exist!..." << endl;
			cin >> uname;
		}
		else if (!status)
		cout << "Enter your CNIC: " << endl;
		cin >> CNIC;
		int size2 = strlen(CNIC);
		if (size2 != 13) {
			cout << "CNIC is invalid! Please enter the CNIC again!..." << endl;
			cin >> CNIC;
			size2 = strlen(CNIC);
			while (size2 != 13)
			{
				cout << "CNIC is invalid! Please enter the CNIC again!..." << endl;
				cin >> CNIC;
				size2 = strlen(CNIC);
			}
		}
		cout << "Enter your password: " << endl;
		cin >> Password;
		int size3 = strlen(Password);
		jump3:
		cout << "Invalid Password! Please enter your password again!... " << endl;
		cin >> Password;
		size3 = strlen(Password);
		for (int i = 0; i < sizeof(Password); i++) {
			if (Password[i] >= 32 && Password[i] <= 47 || Password[i] >= 58 && Password[i] <= 95) {
				special2 = true;
			}
			if (Password[i] >= 48 && Password[i] <= 57) {
				digit2 = true;
			}
			if (Password[i] >= 65 && Password[i] <= 90) {
				upper2 = true;
			}
			if (Password[i] >= 97 && Password[i] <= 122) {
				lower2 = true;
			}
		}
			if (!upper2 || !lower2 || !special2 || !digit2 || size3 != 8) {
				goto jump3;
			}
			strcpy(years, "No experience");
			strcpy(specialization, "No specialization");
			strcpy(availability, "No hours");
			strcpy(hospital, "No hospital");
			strcpy(city, "No city");
			strcpy(hours, "no charge");
			strcpy(email, "NO EMAIL");
			strcpy(email, "NO EMAIL");
			User newUser(uname, pass, cnic, email, years, specialization, availability, hospital, city, hours);
			return newUser;
			return User();
	}
	// Function to login into Doctor's Profile
	User User::DoctorLoginData() {
		char uname[15], pass[15], cnic[15], email[15], years[15], specialization[15], hospital[15], availability[15], city[15], hours[15];
		ifstream fin;
		fin.open("Doctor.dat", ios::in | ios::binary);
		cout << "Enter your username: " << endl;
		cin >> uname;
		cout << "Enter your password: " << endl;
		cin >> pass;
		User status3 = DoctorLoginCheck(uname, pass);
		cout<<"The years are: "<<status3.YearsOfExperience<<endl;
		cout<<"The specialization is: "<<status3.SpecializationArea<<endl;
		cout<<"The hospital name is: "<<status3.AvailablityHours<<endl;
		cout<<"The availabilty hours are: "<<status3.HospitalName<<endl;
		cout<<"The city name is: "<<status3.City<<endl;
		cout<<"The hourly charge is: "<<status3.HourlyCharge<<endl;
		strcpy(years, YearsOfExperience);
		strcpy(specialization, SpecializationArea);
		strcpy(availability, AvailablityHours);
		strcpy(hospital, HospitalName);
		strcpy(city, City);
		strcpy(hours, HourlyCharge);
		strcpy(email, "NO EMAIL");
		strcpy(cnic, "NO CNIC");
		User newUser(uname, pass, cnic, email, years, specialization, availability, hospital, city, hours);
		return newUser;
		return (User());
	}
	// Function to open the doctor file
	void User::DoctorLogin() {
		fstream fout;
		fout.open("Doctor.dat", ios::out | ios::app | ios::binary);
		User newUser1 = DoctorLoginData();
		fout.write((char*)&newUser1, sizeof(User));
	//	display(newUser1);
		fout.close();
	}
	// Overall menu to ask user's choice
	void User::Menu1() {
	
		cout << "0.  Exit" << endl;
		cout << "1.  Login as an Doctor " << endl;
		cout << "2.  Login as an Admin " << endl;
		cout << "3.  Login as an Patient " << endl;
	}
	// check if the doctor's profile exists or not
	User User::DoctorLoginCheck(string a, string b) {
		ifstream fin;
		fin.open("Doctor.dat", ios::in | ios::binary);
		User user3;
		while (fin.read((char*)&user3, sizeof(user3))) {
			//	cout << p << " " << user.UserName << " \n";
			if (user3.UserName == a && user3.Password == b){
			
			cout<<"Welcome Dr. "<<a<<" back to your profile..."<<endl;
				return user3;
			}
		}
		//	cout<<"Please register your account!... "<<endl;
		//	cin>>a;
		
		return User();
		fin.close();
	
	}
	// check if the patient profile exists or not
	bool User::PatientLoginCheck(string a, string b) {
		ifstream fin;
		fin.open("Patient.dat", ios::in | ios::binary);
		User user4;
		while (fin.read((char*)&user4, sizeof(user4))) {
			//	cout << p << " " << user.UserName << " \n";
	
		//	if (user4.UserName == "waleed" && user4.Password == "Walee78*")
	
				return true;
		}
		fin.close();
		return false;
	}
	// function to ask patient its details
	User User::PatientLoginData() {
		char uname3[15], pass3[15], cnic3[15], email3[15], years3[15], specialization3[15], hospital3[15], availability3[15], city3[15], hours3[15];
		ifstream fin;
		fin.open("Patient.dat", ios::in | ios::binary);
		cout << "Enter your username: " << endl;
		cin >> uname3;
		cout << "Enter your password: " << endl;
		cin >> pass3;
		bool status3 = PatientLoginCheck(uname3, pass3);
		if (status3) {
			cout << "Welcome back " << uname3 << " to your profile!..." << endl;
	
		}
		else if (!status3) {
			cout << "No record found!... Please Register your account!..." << endl;
		}
		strcpy(years3, "No years");
		strcpy(specialization3, "No specialization");
		strcpy(availability3, "Not availble");
		strcpy(hospital3, "No hospital");
		strcpy(city3, "NO city");
		strcpy(hours3, "No hours");
		strcpy(email3, "NO EMAIL");
		strcpy(cnic3, "NO CNIC");
		User newUser(uname3, pass3, cnic3, email3, years3, specialization3, availability3, hospital3, city3, hours3);
		return newUser;
		return (User());
	}
	void User::PatientLogin() {
		fstream fout;
		fout.open("Patient.dat", ios::out | ios::app | ios::binary);
		User newUser3 = PatientLoginData();
		fout.write((char*)&newUser3, sizeof(User));
		fout.close();
	}
	bool User::AlreadyAvailableAdmin(string p){
		ifstream fin;
		fin.open("Admin.dat", ios::in|ios::binary);
		User user;
		while (fin.read((char*)&user, sizeof(user))) {
		//	cout << p << " " << user.UserName << " \n";
			if (user.UserName == "hadi" && user.Password == "Walee78*" || user.UserName == "waleed" && user.Password == "Walee78*")
	
				return true;
		}
		fin.close();
		return false;
	}
	User User::AdminRegisterationMenu(){
		bool upper2 = false;
		bool lower2 = false;
		bool digit2 = false;
		bool special2 = false;
		char uname[15], pass[15], cnic[15], email[15], years[15], specialization[15], hospital[15], availability[15], city[15], hours[15];
		ifstream fin;
		fin.open("Patient.dat", ios::in | ios::binary);
		cout << "1.  Enter your name: " << endl;
		cin >> uname;
		bool status = AlreadyAvailableAdmin(uname);
		if (status) {
			cout << "Already Exist!..." << endl;
			cin >> uname;
		}
		else if (!status)
		cout << "Enter your CNIC: " << endl;
		cin >> CNIC;
		int size2 = strlen(CNIC);
		if (size2 != 13) {
			cout << "CNIC is invalid! Please enter the CNIC again!..." << endl;
			cin >> CNIC;
			size2 = strlen(CNIC);
			while (size2 != 13)
			{
				cout << "CNIC is invalid! Please enter the CNIC again!..." << endl;
				cin >> CNIC;
				size2 = strlen(CNIC);
			}
		}
		cout << "Enter your password: " << endl;
		cin >> Password;
		int size3 = strlen(Password);
		jump3:
		cout << "Invalid Password! Please enter your password again!... " << endl;
		cin >> Password;
		size3 = strlen(Password);
		for (int i = 0; i < sizeof(Password); i++) {
			if (Password[i] >= 32 && Password[i] <= 47 || Password[i] >= 58 && Password[i] <= 95) {
				special2 = true;
			}
			if (Password[i] >= 48 && Password[i] <= 57) {
				digit2 = true;
			}
			if (Password[i] >= 65 && Password[i] <= 90) {
				upper2 = true;
			}
			if (Password[i] >= 97 && Password[i] <= 122) {
				lower2 = true;
			}
		}
			if (!upper2 || !lower2 || !special2 || !digit2 || size3 != 8) {
				goto jump3;
			}
			strcpy(years, "No experience");
			strcpy(specialization, "No specialization");
			strcpy(availability, "No hours");
			strcpy(hospital, "No hospital");
			strcpy(city, "No city");
			strcpy(hours, "no charge");
			strcpy(email, "NO EMAIL");
			User newUser(uname, pass, cnic, email, years, specialization, availability, hospital, city, hours);
			return newUser;
			return User();
	}
	void User::AdminLogin(){
		fstream fout;
		fout.open("Admin.dat", ios::out | ios::app | ios::binary);
		User newUser1 = AdminLoginData();
		fout.write((char*)&newUser1, sizeof(User));
		fout.close();
	}
	User User::AdminLoginData(){
		char uname3[15], pass3[15], cnic3[15], email3[15], years3[15], specialization3[15], hospital3[15], availability3[15], city3[15], hours3[15];
		ifstream fin;
		fin.open("Admin.dat", ios::in | ios::binary);
		cout << "Enter your username: " << endl;
		cin >> uname3;
		cout << "Enter your password: " << endl;
		cin >> pass3;
		bool status3 = AdminLoginCheck(uname3, pass3);
		if (status3) {
			cout << "Welcome back " << uname3 << " to your profile!..." << endl;
		//	int c = 0;
		//	cout << "1.  Press 1 to view details: " << endl;
		//	cin >> c;
			//user->display();
		}
		else if (!status3) {
			cout << "No record found!... Please Register your account!..." << endl;
		}
		strcpy(years3, "No years");
		strcpy(specialization3, "No specialization");
		strcpy(availability3, "Not availble");
		strcpy(hospital3, "No hospital");
		strcpy(city3, "NO city");
		strcpy(hours3, "No hours");
		strcpy(email3, "NO EMAIL");
		strcpy(cnic3, "NO CNIC");
		User newUser(uname3, pass3, cnic3, email3, years3, specialization3, availability3, hospital3, city3, hours3);
		return newUser;
		return (User());
	}
	bool User::AdminLoginCheck(string a , string b){
		ifstream fin;
		fin.open("Admin.dat", ios::in | ios::binary);
		User user4;
		while (fin.read((char*)&user4, sizeof(user4))) {
			//	cout << p << " " << user.UserName << " \n";
	
			if (user4.UserName == a && user4.Password == b)
	
				return true;
		}
		fin.close();
		return false;
	}
	/*void User::display(User u5){
	//	this->YearsOfExperience = u5.YearsOfExperience;
	//	this->HospitalName = u5.HospitalName;
		cout<<"The years are : "<<u5.YearsOfExperience<<endl;
		cout<<"The hospital name is: "<<u5.HospitalName<<endl;
	}*/
	///////////////////////////// Doctor Class //////////////////////////////////////////////////////
	// Default Constructor for doc class
	//Doctor::Doctor() {
	//	strcpy(YearsOfExperience, "NO Experience");
	//	strcpy(SpecializationArea, "NO Specialization");
	//	strcpy(HospitalName, "NO hospital");
	//	strcpy(AvailablityHours, "No Availability");
	//	strcpy(City, "No city");
	//	strcpy(HourlyCharge, "Free :)");
	//}
	//// parametrized constructor for doc class
	//Doctor::Doctor(char a[20], char b[20], char c[20], char d[20], char e[20], char f[20]) {
	//	strcpy(YearsOfExperience, a);
	//	strcpy(SpecializationArea, b);
	//	strcpy(HospitalName, c);
	//	strcpy(AvailablityHours, d);
	//	strcpy(City, e);
	//	strcpy(HourlyCharge, f);
	//}
	//void Doctor::setYears(char a[20]) {
	//	strcpy(YearsOfExperience, a);
	//}
	//string Doctor::getYears() {
	//	return YearsOfExperience;
	//}
	//// Function to get extra info from the doctor 
	//void Doctor::DoctorExtraData() {
	//
	//	cout << "1.  Please enter your experience years: " << endl;
	//	cin >> YearsOfExperience;
	//	cout << "2.  Please enter your Specialization Area: " << endl;
	//	cin >> SpecializationArea;
	//	cout << "3.  Please enter your Availability Hours: " << endl;
	//	cin >> AvailablityHours;
	//	cout << "4.  Please enter your Hospital Name: " << endl;
	//	cin >> HospitalName;
	//	cout << "5.  Please enter your city name: " << endl;
	//	cin >> City;
	//	cout << "6.  Please enter your Hourly Charge: " << endl;
	//	cin >> HourlyCharge;
	//	cout << "Years: " << YearsOfExperience << endl;
	//	int a = 0;
	//	cout << "Press 1 if you want to add your Availibility and Hourly charge:  " << endl;
	//	cout << "Press 2 if you want to edit yout Availibility and Hourly charge:" << endl;
	//	cout << "Press 3 if you want to delete yout Availibility and Hourly charge:" << endl;
	//	cout << endl;
	//	cin >> a;
	//	if (a == 1) {
	//		AddAvailabilityHoursandHourlyCharge();
	//	}
	//	else if (a == 2) {
	//		int c = 0;
	//		cout << "Please enter Hours you want to update: " << endl;
	//		cin >> AvailablityHours;
	//		cout << "Please enter Hourly charge you want to update: " << endl;
	//		cin >> HourlyCharge;
	//		EditAvailabilityHoursAndHourlyCharge(AvailablityHours, HourlyCharge);
	//	}
	//	else if (a == 3) {
	//		DeleteAvailbilityHoursAndHourlyCharge();
	//	}
	//}
	//void Doctor::AddAvailabilityHoursandHourlyCharge() {
	//	int g = 0;
	//	cout << "1.  Press 1 to add your availability hours :" << endl;
	//	cout << "2.  Press 2 to add your Hourly charge: " << endl;
	//jump6:
	//	cin >> g;
	//	if (g == 1) {
	//		cout << "Enter Availibilty Hours: " << endl;
	//		cin >> AvailablityHours;
	//	}
	//	if (g == 2) {
	//		cout << "Enter your Hourly Charge: " << endl;
	//		cin >> HourlyCharge;
	//	}
	//	
	//}
	//
	//void Doctor::EditAvailabilityHoursAndHourlyCharge(string a, string b) {
	//	
	//}
	//void Doctor::DeleteAvailbilityHoursAndHourlyCharge() {
	//
	//}
	//void Doctor::display() {
	//	cout << "Your experience is: " << YearsOfExperience << endl;
	//	cout << "Your hours are: " << HourlyCharge << endl;
	//	cout << "The hopsital name is: " << HospitalName << endl;
	//}
	///////////////////////////////////////////////////////// Patient Class //////////////////////////////////////////////////////////////////////////
	/// Proper menu for the patient
	void Patient::ExtraDataPat(){
		jump0:
		int m = 0;
		cout<<"1.  Press 1 to search for the doctor..."<<endl;
		cout<<"2.  Press 2 to check doctor availability..."<<endl;
		cout<<"3.  Press 3 to book and cancel appointments with the doctor..."<<endl;
		cout<<"4.  Press 4 to update appointments..."<<endl;
		cout<<"5.  Press 5 to change the profile details..."<<endl;
		cout<<"6.  Press 6 to book video consultations..."<<endl;
		cout<<"7.  Press 7 to check all the scheduled appointments..."<<endl;
		cout<<"8.  Press 8 to recharge your account..."<<endl;
		cin>> m;
		if(m == 1){
			SearchDoctor();
			goto jump0;
		}
		if( m==3 ){
			
		}
		//if( m==2 ){
		//	CheckAvailability();
		//}
	}
	void Patient::CheckAppointment(){
		
	}
	
	/////// Function to check doctor's availability //////////
	// Function to search doctor by patient's choice/////
	void Patient::SearchDoctor(){
		int helper1 = 0;
		string haha;
		int s = 0 ;
		jump7:
		cout<<"1.  Press 1 to search doctor by speciality"<<endl;
		cout<<"2.  Press 2 to search doctor by hospital name"<<endl;
		cout<<"3.  Press 3 to search doctor by city name"<<endl;
		ifstream fin;
		cin>>helper1;
		Feedback f1;
		if(helper1==1){
			cout<<"Please enter the speciality you want to book appointment for: "<<endl;
			cin>>haha;
		
			fin.open("Doctor.dat", ios::in|ios::binary);
			Patient patient;
			
			while (fin.read((char*)&patient, sizeof(patient))) {
		//	cout << p << " " << user.UserName << " \n";
		//	jump0:
			if (patient.SpecializationArea == haha)
				{
			
			cout<<"The doctor with "<<patient.SpecializationArea<<" are "<<patient.UserName<<endl;
			cout<<"The availability hours for"<<patient.UserName<<" are "<<patient.HospitalName<<endl;
			cout<<"The hourly charge for"<<patient.UserName<<" are "<<patient.HourlyCharge<<endl;
			cout<<"Do you want to book appointment for "<<patient.UserName<<" ?"<<endl;
		string a ;
		cin>>a;
		if(a=="Yes" || a == "YES" || a =="yes"){
			cout<<"Give your time: ";
			string po;
			cin>>po;
			if(patient.HospitalName == po){
				cout<<"Appointment BOOKED!..."<<endl;
				f1.take_Feedback(po);
			}
		}
		else if(a == "no" || a == "NO" || a == "No"){
				cout<<"GO for the next Doctor!... "<<endl;
		}
	//	break;
	
}
			//CheckAvailability(haha);
		
	}
	/*	cout<<"Do you want to book appointment: "<<endl;
		string a ;
		cin>>a;
		if(a=="Yes" || a == "YES" || a =="yes"){
			cout<<"Please enter the doctor's name with thom you want to book appointment : "<<endl;
			string no;
		cin>>no;
			cout<<"1.  Press 1 for the Online Consulation"<<endl;
			cout<<"2.  Press 2 for the Physical Consultaion"<<endl;
			int b =0;
			cin>>b;
			Patient p1;
			fin.open("Doctor.dat", ios::in|ios::binary);
			while (fin.read((char*)&p1, sizeof(p1))) {
			if(b==1 && p1.UserName == no){
				cout<<"The hourly charge for the Online Consulation of "<<p1.UserName<<" is"<<
				p1.HourlyCharge<<endl;
			}
		}
	}*/
}
		if(helper1==2){
			cout<<"Please enter the hospital name you want to search for: "<<endl;
			cin>>haha;
			
			fin.open("Doctor.dat", ios::in|ios::binary);
			Patient patient;
			
			while (fin.read((char*)&patient, sizeof(patient))) {
		//	cout << p << " " << user.UserName << " \n";
			if (patient.HospitalName == haha){
			
			cout<<"The doctor with "<<patient.HospitalName<<" are "<<patient.UserName<<endl;
			cout<<"The availability hours for"<<patient.UserName<<" are "<<patient.HospitalName<<endl;
			cout<<"The hourly charge for"<<patient.UserName<<" are "<<patient.HourlyCharge<<endl;
				cout<<"Do you want to book appointment for "<<patient.UserName<<" ?"<<endl;
		string a ;
		cin>>a;
		if(a=="Yes" || a == "YES" || a =="yes"){
			cout<<"Give your time: ";
			string po;
			cin>>po;
			if(patient.HospitalName == po){
				cout<<"Appointment BOOKED!..."<<endl;
			
				f1.take_Feedback(po);
			}
		}
		else if(a == "no" || a == "NO" || a == "No"){
				cout<<"GO for the next Doctor!... "<<endl;
		}
		}
	
		}
	
	}
		if(helper1==3){
			cout<<"Please enter the city name you want to search for: "<<endl;
			cin>>haha;
				
			fin.open("Doctor.dat", ios::in|ios::binary);
			Patient patient;
			
			while (fin.read((char*)&patient, sizeof(patient))) {
		//	cout << p << " " << user.UserName << " \n";
			if (patient.City == haha){
			
			cout<<"The doctor with "<<patient.City<<" are "<<patient.UserName<<endl;
		cout<<"The availability hours for"<<patient.UserName<<" are "<<patient.HospitalName<<endl;
		cout<<"The hourly charge for"<<patient.UserName<<" are "<<patient.HourlyCharge<<endl;
			cout<<"Do you want to book appointment for "<<patient.UserName<<" ?"<<endl;
		string a ;
		cin>>a;
		if(a=="Yes" || a == "YES" || a =="yes"){
			cout<<"Give your time: ";
			string po;
			cin>>po;
			if(patient.HospitalName == po){
				cout<<"Appointment BOOKED!..."<<endl;
				f1.take_Feedback(po);
			}
		}
		else if(a == "no" || a == "NO" || a == "No"){
				cout<<"GO for the next Doctor!... "<<endl;
		}
		}
		}
	}
		fin.close();	
	}
////// Function to book and cancel Online Consultations
/*void Patient::OnlineConsultations(string s1){
	ifstream fin;
		fin.open("Doctor.dat", ios::in|ios::binary);
			Patient patient;
			string g;
			jump69:
			cout<<"Enter the time you want to book the appointment for: ";
			cin>>g;
			while (fin.read((char*)&patient, sizeof(patient))) {
		//		cout<<"  "<<patient.UserName <<" "<< s1 <<endl;
		//	cout<<"  "<<patient.HospitalName<<" "<<g<<endl;
		//	cout << p << " " << user.UserName << " \n";
			if (patient.UserName == s1 && patient.HospitalName == g){
		//	cout<<"  "<<patient.UserName <<" "<< s1 <<endl;
		//	cout<<"  "<<patient.HospitalName<<" "<<g<<endl;
			cout<<"Appointment Booked Successfully!..."<<endl;
		}
		else{
			//cout<<"  "<<patient.UserName <<" "<< s1 <<endl;
			//cout<<"  "<<patient.HospitalName<<" "<<g<<endl;
			cout<<"Sorry! The doctor isn't free in this time slot!..."<<endl;
			goto jump69;
		}
		}
}*/
	// FUnction to check the availability of the particular doctor
	
	// proper menu for the doctor
	void Doctor::ExtraDataDoc(){
		cout<<"1.  Press 1 to edit delete and add your availability..."<<endl;
		cout<<"2.  Press 2 to edit delete and add your hourly charge..."<<endl;
		cout<<"3.  Press 3 to check patient's appointment detail..."<<endl;
		cout<<"4.  Press 4 to update the status of appointments..."<<endl;
		cout<<"5.  Press 5 to edit your profile..."<<endl;
		cout<<"6.  Press 6 to check all scheduled appointments..."<<endl;
	}
	// ADmin add doctor data
void Admin::AddDoctorData(){
		ofstream fout;
		fout.open("Doctor.dat", ios::out | ios::app | ios::binary);
		User newUser = DoctorRegisterationMenu();
		cout << "You are successfully registered. Please enter this information.." << endl;
		fout.write((char*)&newUser, sizeof(User));	
		fout.close();
		cout << "You are registered successfully...." << endl;	
}
void Admin::EditDoctorData(){
		ofstream fout;
		fout.open("Doctor.dat", ios::out | ios::app | ios::binary);
		User newUser = DoctorRegisterationMenu();
		cout << "You are successfully registered. Please enter this information.." << endl;
		fout.write((char*)&newUser, sizeof(User));	
		fout.close();
		cout << "You are registered successfully...." << endl;
}
	// proper manu for the admin
void Admin::ExtraDataAdm(){
	Admin a1;
		cout<<"1.	Press 1 for adding Doctor's data"<<endl;
		cout<<"2.	Press 2 for viewing Doctor'd data"<<endl;
		int u;
		cin>>u;
		if(u==1){
			AddDoctorData();
		}
		if(u==2){
		ifstream fin;
		fin.open("Doctor.dat", ios::in|ios::binary);
		
		while (fin.read((char*)&a1, sizeof(a1))) {
		cout<<"The years are: "<<a1.YearsOfExperience<<endl;
		cout<<"The specialization is: "<<a1.SpecializationArea<<endl;
		cout<<"The hospital name is: "<<a1.AvailablityHours<<endl;
		cout<<"The availabilty hours are: "<<a1.HospitalName<<endl;
		cout<<"The city name is: "<<a1.City<<endl;
		cout<<"The hourly charge is: "<<a1.HourlyCharge<<endl;	
	}
	fin.close();
		}
	}
	///// Feedback class
void Feedback::take_Feedback(string p){
		
		cout << "How was your Checkup. We hope you were satisfied. Please give us a review about your experience: ";
		while(review != "q"){
			cin>>review;
		}
		cout << "\nThanks for your remarks. Now tell us what rating would you give to the Doctor(Out of 5):  ";
		cin >> rating;

}
	int main() {
		
		int a = 0;
		int num = 0;
		cout << "----------------------------------------------------------" << endl;
	    cout << "|============== Hospital Management System ==============|" << endl;
	    cout << "|                                                        |" << endl;
	    cout << "|   	          Welcome to olaDOC                      |" << endl;
	    cout << "----------------------------------------------------------" << endl;
	
	    cout << endl << endl;
	    cout << "-----------------------------------------------------------" << endl;
	    cout << "|========================= Menu =========================|" << endl;
	    cout << "----------------------------------------------------------" << endl;
	    cout << "|                                                        |" << endl;
	    cout<<endl;
	    cout<<endl;
		string ask;
		jump11:
		cout << "Are you a new user ? ";
		jump2:
		cin >> ask;
		User *u2;
	//	Doctor d;
		Patient p;
	//	Admin a1;
	//	u2 = &d;
		u2 = &p; 
	//	u2 = &a1;
		if (ask == "Yes" || ask == "yes" || ask == "YES") {
			u.Menu();
			do {
				//system("cls");
			
				cin >> num;
				if (num == 1) {
				
			
					User user1;
					user1.RegisterDoctor();
				goto jump11;
				
				}
				else if (num == 2) {
					User u1;
					u1.RegisterAdmin();
					goto jump11;
				}
				else if (num == 3) {
					User user1;
					user1.RegisterPatient();
						goto jump11;
				}
				system("pause");
				} while (num);
			}
		if (ask == "no") {
			u.Menu1();
			do {
			//	system("cls");
				cin >> num;
				if (num == 1) {
					User user1;
					user1.DoctorLogin();
					u2->ExtraDataDoc();
				}
				else if (num == 2) {
					User user2;
					Admin a;
					user2.AdminLogin();
					a.ExtraDataAdm();
				}
				else if (num == 3) {
					User user3;
					user3.PatientLogin();
					u2->ExtraDataPat();
				}
				
			} while (num);
			system("pause");
		}
		return 0;
	}

