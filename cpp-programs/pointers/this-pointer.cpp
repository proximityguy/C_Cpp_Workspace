#include<iostream>
using namespace std;

class demo{
public:
	int value;

	bool compare(demo d){
		return (this->value == d.value);
	}
};

int main(){

	demo obj1, obj2;
	cin>>obj1.value>>obj2.value;

	if(obj1.compare(obj2)){
		cout<<"equal objects";
	} else {
		cout<<"not equal objects";
	}

	return 0;
}