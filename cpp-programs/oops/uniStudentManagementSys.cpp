#include<iostream>
using namespace std;

class Person{
public:
	string name;

	void showName(){
		cout<<"Name: "<<name<<endl;
	}
};

class Student : public Person {
public:
	int roll_no;

	void showRollNo(){
		cout<<"Roll No: "<<roll_no<<endl;
	}
};

class GraduateStudent : public Student {
public:
	string researchTopic;

	void showResearchTopic(){
		cout<<"Research Topic: "<<researchTopic<<endl;
	}
};

int main(){

	GraduateStudent g;

	g.name = "Ayush";
	g.roll_no = 3;
	g.researchTopic ="Blockchain";

	g.showName();
	g.showRollNo();
	g.showResearchTopic();

	return 0;
}