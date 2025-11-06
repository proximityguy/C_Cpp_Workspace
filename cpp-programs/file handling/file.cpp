#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream file("C:\\Users\\HP\\Desktop\\sample.txt");

	if(!file) {
		cout<<"error creating file"<<endl;
		return 0;
	}

	file<<"hello world! \n";
	file<<"this is a new file specified";

	file.close();

	cout<<"file is written succesfully.";
	return 0;
}