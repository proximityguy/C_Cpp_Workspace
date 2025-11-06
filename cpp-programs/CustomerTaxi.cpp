	// a city taxi service maintains details of customers who book rides. each customer's information includes:
	// name,	pickup distance from taxi stand,	drop distance from taxi stand
	// the taxi fare is calculated based on the distance travelled:
	// fare = (drop distance - pickup distance) * 10 [₹ 10 per km]

	// the company wants to manage dynamic customer bookings using pointers
	// your task:-
	// 1. create a structure Customer with members name, pickup, drop, and fare
	// 2. dynamically allocate memory for 'n' customers using a pointer
	// 3. input details of each customer using pointer notation [not array indexing]
	// 4. calculate fare for each customer using pointer
	// 5. display all the customer details (name, pickup, drop, fare)
	// 6. also display the customer who paid the maximum fare
#include<iostream>
using namespace std;

class CustomerTaxi{
	string cname;
	int pickup;
	int drop;
	float fare;

public:
	void setData(){
		cout<<"enter name: ";
		cin>>cname;
		cout<<"enter pickup distance: ";
		cin>>pickup;
		cout<<"enter drop distance: ";
		cin>>drop;
	}

	void getData(){
		cout<<"cust_name: "<<cname<<endl;
		cout<<"pickup distance: "<<pickup<<endl;
		cout<<"drop distance: "<<drop<<endl;
		
	}
};

int main(){

	int size;
	cout<<"enter the number of customers whose data you want to store: \n";
	cin>>size;

	CustomerTaxi cust = new CustomerTaxi[size];
	CustomerTaxi* 

	for (int i = 0; i < size; ++i)
	{
		cout<<"data of customer ["<<i<<"] -> \n";
		cust[i]->setData();
	}

	for(int i = 0; i < size; ++i){
		cout<<"data of customers -- \n";
		cust[i]->getData();
	}

	return 0;
}