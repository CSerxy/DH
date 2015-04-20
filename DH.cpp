#include"Calculator.h"
#include<list>
#include<iostream>
#include<string>
using namespace std;

void translate(string u,list<int>& test);
int main(void){
	string u;
	list<int> p,g,a,b,KA;
	cout<<"This program implement Diffie-Hellman algorithm."<<endl;
	cout<<"Please input a prime number p: ";
	cin>>u;
	cout<<endl;
	translate(u,p);
	cout<<"Please input a primitive root g: ";
	cin>>u;
	cout<<endl;
	translate(u,g);
	cout<<"Please input the first secret key a: ";
	cin>>u;
	cout<<endl;
	translate(u,a);
	cout<<"Please input the second secret key b: ";
	cin>>u;
	cout<<endl;
	translate(u,b);

	Calculator A(g,a,p),B(g,b,p);
	cout<<"The first public key A is: "<<A.GetResult()<<endl;
	cout<<"The second public key B is: "<<B.GetResult()<<endl;
	translate(A.GetResult(),KA);
	Calculator K(KA,b,p);
	cout<<"The session key K is: "<<K.GetResult()<<endl;
	cout<<endl;
	return 0;
}

void translate(string u,list<int>& test){
	int i;
	for (i=0;i<u.length();i++) {
		test.push_back(int(u[i])-48);
	}
}
