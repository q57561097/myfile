#include<iostream>
using namespace std;
template <typename T>
T print1(T a)
{
a++;
return a;
}
int main()
{
int b=2;
cout<<print1(b)<<endl;
return 0;
}
