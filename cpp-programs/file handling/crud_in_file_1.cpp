#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream file("C:\\Users\\HP\\Desktop\\num.txt");

	if(!file){
		cout<<"error in creating the file";
		return 0;
	}

	int first, last;
	cout<<"enter two values: ";
	cin>>first>>last;

	for(int i = 1; i <= first; ++i){
		file<<i<<endl;
	}

	file<<last;

	file.close();

	ifstream infile("C:\\Users\\HP\\Desktop\\num.txt");

	if(!infile){
		cout<<"error in creating the file";
		return 0;
	}

	string str;
	cout<<"readin the file: "<<endl;
	while(!infile.eof()){
		getline(infile, str);
		cout<<str<<endl;
	}

	infile.close();

	return 0;
}