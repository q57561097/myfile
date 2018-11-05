#include<iostream>
using namespace std;
#define add(a,b) a*b
#define PI 23
#define S(r) PI*r*r
int main(){
     int a,b;
     a = 10 * add(1,2);
     cout <<a<<endl;
     b = S(1+2);
     cout <<b<<endl;
     #if 2>1
     cout <<1<<endl;
     #else
     cout <<2<<endl;
     #endif
}
