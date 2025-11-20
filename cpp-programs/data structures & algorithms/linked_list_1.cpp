#include<iostream>
using namespace std;

struct Student{
	int roll;
	string name;

	Student* next;

	Student(int r, string n){
		roll = r;
		name = n;
		next = nullptr;
	}
};

int main(){
	Student head = new Student(1, 'john');
	Student first = new Student(2, 'smith');

	head->next = first;

	cout<<head.roll<<endl;
	cout<<head.name<<endl;
	cout<<

}