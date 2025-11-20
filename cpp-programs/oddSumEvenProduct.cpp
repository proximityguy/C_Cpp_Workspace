#include<iostream>
using namespace std;

int checkEvenOdd(int num){
	if(num%2 == 0){
		sum(num, res1);
	} else {
		product(num, res2);
	}
}

int sum(int num, int* res1 = 0){

}

int product(int num, int* res2 = 1){

}

int main(){

	int n1, n2;
	int* res1, res2;

	cin>>n1>>n2;

	checkEvenOdd(n1);
	checkEvenOdd(n2);

		cout<<res1;
		cout<<res2;


	return 0;
}