#include<iostream>
using namespace std;

class Counter{
private:
	int count;
public:
	Counter(){
		count = 0;
	}

	int increaseCount(int n){
		count = n;
		return count;
	}
};

int main(){
	int initial, newvalue;
	cin>>initial;
	cin>>newvalue;

	Counter c;
	cout<<"initial value: " <<c.increaseCount(initial)<<endl;
	cout<<"new value: " <<c.increaseCount(newvalue)<<endl;	

	return 0;
}