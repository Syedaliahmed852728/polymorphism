//Name :Syed Ali Ahmed                          department: FBAS/BSSE/F-21
//Roll No :4308                                 university:International Islamic University Islamabad

//here we covers all the concept of polymorphism

#include <iostream>
#include <typeinfo>
using namespace std;
#define MAX 5000
struct Myage {
	unsigned int day;
	unsigned int month;
	unsigned int year;
	Myage(int dd, int mm, int yy) :day(dd), month(mm), year(yy) {}
	Myage() {
		day = 0;
		month = 0;
		year = 0;
	}
};
class person {
	unsigned int ID;
	string Name;
	Myage age;
public:
	person(int id, string name, Myage Age) : ID(id), Name(name), age() {}
	person() {
		ID = 0;
		Name = "\0";
		age.day = 0;
		age.month = 0;
		age.year = 0;
	}
	virtual void readData();
	virtual void displData();
	virtual void isOutStanding() = 0;
};
void person::readData() {
	cout << "Enter ID :- ";
	cin >> ID;
	cout << "Enter the Name :- ";
	cin >> Name;
	cout << "Enter Age " << endl;
	cout << "month:- "; cin >> age.month;
	cout << "day:- "; cin >> age.day;
	cout << "year:- "; cin >> age.year;
	cout << endl;
}
void person::displData() {
	cout << "ID:- " << ID << endl;
	cout << "Name:-" << Name << endl;
	cout << "Date of Birth:- " << age.month << " / " << age.day << " / " << age.year << endl;
}
class student :public person {
	string programme;
	unsigned int semester;
	float CGPA;
public:
	student(int id, string Name, Myage DOB, string programm, unsigned int sem, float gpa) :
		person(id, Name, DOB), programme(programm), semester(sem), CGPA(gpa) {}
	student() {
		programme = "\0";
		semester = 0;
		CGPA = 0.0;
	}
	void readData();
	void displData();
	void isOutStanding();
};
void student::isOutStanding() {
	if (CGPA > 3.5)
		cout << "outstanding" << endl;

	else
		cout << "Not outstanding" << endl;

}
void student::readData() {
	person::readData();
	cout << "Enter Degree/programme :- "; cin >> programme;
	cout << "Enter Semester Number:- "; cin >> semester;
	cout << "Enter CGPA:- "; cin >> CGPA;
	cout << endl;
}
void student::displData() {
	person::displData();
	cout << "Degree/programme :- " << programme << endl;
	cout << "Semester Number :- " << semester << endl;
	cout << "CGPA :- " << CGPA << endl;
	isOutStanding();
}
class teacher :public person {
	string designation;
	string department;
	float salary;
	unsigned int publication;
public:
	teacher(int id, string Name, Myage DOB, string desig, string depart, float pay, unsigned int publ) :
		person(id, Name, DOB), designation(desig), department(depart), salary(pay), publication(publ) {}
	teacher() {
		designation = "\0";
		department = "\0";
		salary = 0.0;
		publication = 0;
	}
	void readData();
	void displData();
	void isOutStanding();
};
void teacher::isOutStanding() {
	if (publication > 5)
		cout << "oustanding" << endl;

	else
		cout << "Not outStading" << endl;

}
void teacher::displData() {
	person::displData();
	cout << "Designation :- " << designation << endl;
	cout << "Department :- " << department << endl;
	cout << "salary :- " << salary << endl;
	cout << "Number of publication :- " << publication << endl;
}
void teacher::readData() {
	person::readData();
	cout << "Enter designation:- "; cin >> designation;
	cout << "Enter department:- "; cin >> department;
	cout << "Enter salary:- "; cin >> salary;
	cout << "Enter Number of publication:- "; cin >> publication;
}
void menu() {
	cout << "1.Create Student" << endl;
	cout << "2.Create Teacher" << endl;
	cout << "3.diplay student" << endl;
	cout << "4.display Teacher" << endl;
	cout << "5.exit" << endl;
}
int main()
{
	person* ptr[MAX];
	char option;
	int n = 0,total1=0,total2=0,x=0;
	do {
		menu();
		cout << "chose your option" << endl;
		cin >> option;
		switch (option) {
		case '1':
			cout << "how many student you want to create" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				total1++;
				ptr[x] = new student;
				cout << "enter the data of " << total1 << " student " << endl;
				ptr[x++]->readData();
			}
			break;
		case '2':
			cout << "how many teacher you want to create" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				total2++;
				ptr[x] = new teacher;
				cout << "enter the data of " << total1    << " teacher " << endl;
				ptr[x++]->readData();
			}
			break;
		case '3':

			for (int i = 0; i < x; i++) {
				if (typeid(*ptr[i]) == typeid(student)) {
					cout << "                 student " << i+1 << " " << endl;
					ptr[i]->displData();
					cout << endl;
				}
			}
			break;
		case '4':
			for (int i = 0; i < x; i++) {
				if (typeid(*ptr[i]) == typeid(teacher)) {
					cout << "                 teacher " << i+1 << " " << endl;
					ptr[i]->displData();
					cout << endl;
				}
			}
		}
	} while (true);

}

