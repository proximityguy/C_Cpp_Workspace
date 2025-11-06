/*
you are developing a unified payment handler module for an e-commerce platform. when a customer places an order, they can choose only one payment method from the following
1. cash on delivery(amount in )
2. credit card(card number)
3. upi (upi id)

to efficientlyu manage memory, you neeed to store only the details of the selected payment method for each transaction
your task is to:
define a union name PaymentDetail to store the payment data - only one method should be active at a time.
detfine a structure named payment that constains:
customer name;
the union paymentdetail;
*/
#include<iostream>
using namespace std;

union PaymentDetails{
	float cash;
	// string cc;
	// string upi;
	char cc[16];
	char upi[30];
};

struct Payment{
	PaymentDetails pd;
	string custName;
	string contact;
	float amount;
	int payment_mode;
	char confirm;
	bool flag;

	void makePayment(){
		cout<<"enter customer name: ";
		cin>>custName;
		cout<<"enter contact: ";
		cin>>contact;
		cout<<"enter amount to be paid: ";
		cin>>amount;
		cout<<"choose one payment method: \n 	 1. cash\n 	2. credit card\n 	3. upi\n";
		
		int choice;
		cin>>choice;

		switch(choice){
		case 1: 
			pd.cash = amount;
			payment_mode = 1;
			break;
		case 2:
			cout<<"enter credit card no: ";
			cin>>pd.cc;
			cout<<"waiting for payment....!";
			payment_mode = 2;
			break;
		case 3:
			cout<<"enter upi id: ";
			cin>>pd.upi;
			cout<<"waiting for payment....!";
			payment_mode = 3;
			break;
		}

			cout<<"\n is payment done: (y/n): ";
			cin>>confirm;
			if(confirm == 'y' || 'Y'){
				flag = true;
			} else {
				flag = false;
			}
	}

	void displayDetails(){
		cout<<"customer name: "<<custName<<endl;
		cout<<"contact: "<<contact<<endl;
		cout<<"billing amount: "<<amount<<endl;
		cout<<"mode of payment: ";
		
		// if(!pd.cc.empty()){
		// 	cout<<"credit card: "<<pd.cc<<endl;
		// } else if(!pd.upi.empty()){
		// 	cout<<"upi id: "<<pd.upi<<endl;
		// } else {
		// 	cout<<"cash: ₹"<<pd.cash<<endl;
		// }

		switch(payment_mode){
		case 1: cout<<"credit card \n card number: "<<pd.cc<<endl;
			break;
		case 2: cout<<"upi \n upi id: "<<pd.upi<<endl;
			break;
		case 3: cout<<"cash \n amount: ₹"<<pd.cash<<endl;
		}

		cout<<"is payment done: ";
		if(flag == true){
			cout<<"yes \n";
		} else {
			cout<<"no \n";
		}
	}

	bool search(string cont){
		return (cont == contact);
	}
};

int main(){

	const int maxCustPerDay = 100;
	int totalCust = 0;
	Payment p[maxCustPerDay];

	while(true){
	int choice;
	cout<<"\n=== welcome to jiomart ===\n";
	cout<<"1. make a payment \n";
	cout<<"2. check PaymentDetails \n";
	cout<<"3. list all transactions \n";
	cout<<"0. exit \n";
	cout<<"enter an option: ";
	cin>>choice;

	if(choice == 0){
		cout<<"Thank you for shopping!\n";
		break;
	}

	string searchByContact;
	bool found;

	switch(choice){
		case 1: p[totalCust].makePayment();
				totalCust++;
			break;
		case 2: cout<<"enter contact: ";
				cin>>searchByContact;
				found = false;
				for (int i = 0; i < maxCustPerDay; ++i)
				{
					if(p[i].search(searchByContact)){
						p[i].displayDetails();
						found = true;
						 break;
					}
				}

				if(!found) cout<<"account not found! \n";
			break;
		
	default: cout<<"invalid choice! try again. \n";
		// case 0: exit(0);
	}

	}

	return 0;
}