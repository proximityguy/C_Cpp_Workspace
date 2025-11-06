// create a class Product with attributes productName and price. Write a function applyDiscount(float discountnPercent)
// that reduces the price using the 'this' pointer. display the updated price of the product.
#include<iostream>
using namespace std;
class Product{

public:
	string productName;
	float price;

	float applyDiscount(float discountPercent){
		return (this->price - (this->price * discountPercent / 100));
	}
};

int main(){

	float d;
	Product p;
	
	cout<<"enter product name: ";
	cin>>p.productName;
	cout<<"enter price: ";
	cin>>p.price;
	cout<<"enter discount percent: ";
	cin>>d;

	cout<<"discounted price: "<<p.applyDiscount(d);

	return 0;
}