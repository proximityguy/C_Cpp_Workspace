/* A bank wants to maintain simple account operations for its customers
requirements:
-> create a BankAccount class with - accountHolderName, accountNumber, and balance
-> member functions should:
	* deposit money
	* withdraw money (only if sufficient balance)
	* display account details and balance
-> create one account object and perform deposit withdrawl, and detail display operations
*/

#include<iostream>
using namespace std;

class BankAccount{
	int acNo;
	string acHolderName;
	float balance;

public:

	void createAccount(){
		cout<<"enter acNo: ";
		cin>>acNo;
		cout<<"enter acHolderName: ";
		cin>>acHolderName;
		cout<<"enter the initial balance: ";
		cin>> balance;
	}

	void displayDetails(){
		cout<<"------------------\n";
		cout<<"acNo: "<<acNo<<endl;
		cout<<"acHolderName: "<<acHolderName<<endl;
		cout<<"balance: "<<balance<<endl;
		cout<<"------------------\n";		
	}

	void depositAmt(float depAmt){
		if(depAmt<1){
			cout<<"invalid deposit amount. please enter a positive amount"<<endl;
		} else{
		balance+=depAmt;
		cout<<"deposit successful! \n new balance: "<<balance<<endl;	
		}
	}

	void withdrawAmt(float withAmt){
		if(withAmt<1){
		cout<<"invalid withdrawal amount. please enter a positive amount"<<endl;
		} else if(balance <= withAmt){
			cout<<"insufficient balance...:(";
		} else{
			balance-=withAmt;
			cout<<"withdrawal successful! \n new balance: "<< balance <<endl;
		}
	}

	bool search(int accountNo){
		return(acNo == accountNo);
	}

};

int main(){

	BankAccount accounts[100];
	int totalAccounts = 0;

	while(true){
	int choice;
	cout<<"\n=== welcome to bank ===\n";
	cout<<"1. create an account: \n";
	cout<<"2. check details of an account: \n";
	cout<<"3. deposit money: \n";
	cout<<"4. withdraw money: \n";
	cout<<"0. to exit..:)\n";
	cout<<"enter an option: ";
	cin>>choice;

	if(choice == 0){
		cout<<"Thank you for banking with us!\n";
		break;
	}

	int searchAccNo;
	bool found;

	switch(choice){
		case 1: accounts[totalAccounts].createAccount();
				totalAccounts++;
			break;
		case 2: cout<<"enter acNo: ";
				cin>>searchAccNo;
				found = false;
				for (int i = 0; i < totalAccounts; ++i)
				{
					if(accounts[i].search(searchAccNo)){
						accounts[i].displayDetails();
						found = true;
						 break;
					}
				}

				if(!found) cout<<"account not found! \n";
			break;
		case 3: cout<<"enter acNo: ";
				cin>>searchAccNo;
				found = false;
				for (int i = 0; i < totalAccounts; ++i)
				{
					if(accounts[i].search(searchAccNo)){
						float amt;
						cout<<"enter deposit amount: ";
						cin>>amt;
						accounts[i].depositAmt(amt);
						found = true;
						 break;
					}
				}

				if(!found) cout<<"account not found! \n";
			break;
		case 4: cout<<"enter acNo: ";
				cin>>searchAccNo;
				found = false;
				for (int i = 0; i < totalAccounts; ++i)
				{
					if(accounts[i].search(searchAccNo)){
						float amt;
						cout<<"enter withdrawal amount: ";
						cin>>amt;
						accounts[i].withdrawAmt(amt);
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