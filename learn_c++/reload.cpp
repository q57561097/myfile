#include<iostream>
#include<iomanip>
using namespace std;
int add(int a, int b, int c){
	return a+b+c;
}

int add(int a, int b){
	return a+b;
}
int main(){
   int a=1, b=2, c;
   c = add(a,b);
   cout<<c<<endl;
 
}
