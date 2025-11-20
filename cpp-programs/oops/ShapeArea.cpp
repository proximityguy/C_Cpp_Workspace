#include<iostream>
#include<iomanip>
using namespace std;

class Shape{
public:
	Shape(){
		cout<<"shape class invoked"<<endl;
	}

	~Shape(){
		cout<<"shape class revoked"<<endl;
	}

	void area(){
		cout<<"areas of shapes are:"<<endl;
	}
};

class Circle:public Shape{
public:
	float radius;
	const int PI = 22/7;

	Circle(){
		cout<<"circle class invoked"<<endl;
	}

	~Circle(){
		cout<<"circle class revoked"<<endl;
	}

	void area(){
		cout<<"radius: "<<radius<<endl;
		cout<<fixed<<setprecision(2)<<"Area of circle = "<<(PI * radius * radius)<<endl;
	}
};

class Square:public Shape{
public:
	float side;

	Square(){
		cout<<"square class invoked"<<endl;
	}

	~Square(){
		cout<<"square class revoked"<<endl;
	}

	void area(){
		cout<<"side: "<<side<<endl;
		cout<<fixed<<setprecision(2)<<"Area of square = "<<(side * side)<<endl;
	}
};

int main(){

	cout<<"creating instances of circle and square:"<<endl;
	Circle c;
	Square s;

	cout<<"enter radius of circle: ";
	cin>>c.radius;
	c.area();

	cout<<"enter side of square: ";
	cin>>s.side;
	s.area();

	return 0;
}


