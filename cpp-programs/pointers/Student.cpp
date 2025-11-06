// create a class Student with attributes name and marks
// -> write a function getTopper(Student s) that compares the marks of the current object with another student s
// -> the function should return the 'this' pointer if the current student has higher or equal marks, otherwise return the pointer to student s
// ->finally, display the details of the topper student
#include<iostream>
using namespace std;
class Student{
private:
	string name;
	float marks;
public:
	void setData(string name, float marks){
		this->name = name;
		this->marks = marks;
	}

	void getData(){
		cout<<"student name: "<<this->name;
		cout<<"marks: "<<this->marks;
	}
}