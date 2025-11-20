#include<iostream>
#include<string>
using namespace std;

class Employee{
public:
	int id;
	string name;

	Employee(int id, string name){
		this->id = id;
		this->name = name;
	}

	void display(){
		cout<<"id: "<<id<<endl;
		cout<<"name: "<<name<<endl;
	}

	virtual void calculateSalary() = 0;
};

class FullTimeEmp : public Employee{
public:
	float salary;
	
	FullTimeEmp(int id, string name, float s) : Employee(id, name), salary(s){}

	void calculateSalary() override{
		cout<<"salary:"<<salary<<endl;
	}
};

class PartTimeEmp : public Employee{
public:
	float workHour, payPerHour;

	PartTimeEmp(int id, string name, float hr, float pph) : Employee(id, name), workHour(hr), payPerHour(pph) {}

	void display(){
		Employee::display();
		cout<<"work hours: "<<workHour<<endl;
		cout<<"payPerHour: "<<payPerHour<<endl;
	}

	void calculateSalary() override{
	float salary = workHour * payPerHour;
		cout<<"total salary: "<<salary<<endl;
	}
};

int main(){
	int id;
	string name;
	float salary, workHour, payPerHour;

	cout<<"enter data for Full Time Employee: \n";
	cout<<"id: ";
	cin>>id;
	cout<<"name: ";
	cin>>name;
	cout<<"salary: ";
	cin>>salary;
	FullTimeEmp f1(id, name, salary);

	cout<<"enter data for Part Time Employee: \n";
	cout<<"id: ";
	cin>>id;
	cout<<"name: ";
	cin>>name;
	cout<<"work hour: ";
	cin>>workHour;
	cout<<"payPerHour: ";
	cin>>payPerHour;
	PartTimeEmp p1(id, name, workHour, payPerHour);

	cout<<"--- Full Time Employee ---\n";
	f1.display();
	f1.calculateSalary();
	cout<<"--- Part Time Employee ---\n";
	p1.display();
	p1.calculateSalary();



	return 0;
}