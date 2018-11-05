#include<iostream>
using namespace std;
int main(){
  int const *p;
 // const int *p:
  int a = 1;
  int b = 3;
  p =&a;
  *p = 2;
  p =&b;
  cout<<*p<<endl;
  cout<<a<<endl;
  return 0;
}
