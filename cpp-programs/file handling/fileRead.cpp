#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream file("C:\\Users\\HP\\Desktop\\sample.txt");

	if(!file){
		cout<<"error in reading the file."<<endl;
		return 0;
	}

	string str;

	while(!file.eof()){
	getline(file, str);
	cout<<str<<endl;
	}


	return 0;

}