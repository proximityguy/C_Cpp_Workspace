#include<iostream>
using namespace std;

class Student
{
	int regNo;
	string name;
	string course;
	float marks[3];

public:

	void setData(){
		cout<<"enter RegNo: ";
		cin>>regNo;
		// cin.ignore();	// used to ignore whitespaces
		cout<<"enter name: ";
		getline(cin>>ws, name);	// used to get a stream of character with/without spaces
		cout<<"enter your course: ";
		getline(cin>>ws, course);	// 'ws' is used to ignore whitespaces

		for (int i = 0; i < 3; i++)
		{
			cout<<"enter marks in subj"<<i+1<<" : ";
			cin>>marks[i];
		}

	}

	void getData(){
		cout<<"RegNo: "<<regNo<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Course: "<<course<<endl;

		for (int i = 0; i < 3; i++)
		{
			cout<<"marks in subj"<<i+1<<" : "<<marks[i]<<endl; 
		}

		calculateMarks();
	}

	void calculateMarks(){
		float totalMarks = 0, avgMarks = 0;
		for (int i = 0; i < 3; ++i)
		{
			totalMarks+=marks[i];
		}

		avgMarks = totalMarks/3;

		cout<<"total marks: "<<totalMarks<<endl;
		cout<<"average marks: "<<avgMarks<<endl;
	}
	
};

int main(){

	Student s1;
	s1.setData();
	s1.getData();


	return 0;
}