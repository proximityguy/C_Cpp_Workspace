#include<iostream>
using namespace std;

class Person{
private:
	string name;
	int age;
public:
	Person(){
		cout<<"Person object initialized"<<endl;
	}

	void setName(string name){
		this->name = name;
	}

	void setAge(int age){
		this->age = age;
	}

	void display(){
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age;
	}
};

int main(){
	string name;
	int age;

	getline(cin, name);
	cin>>age;

	Person p;
	p.setName(name);
	p.setAge(age);

	p.display();

	return 0;
}