#include<iostream>
#include<fstream>
using namespace std;
int main(){
   char data[100]; 
   ofstream outfile;
   outfile.open("./outfile");
   cout << "Writing to the file"<< endl;
   cout << "enter your name";
   cin.getline(data, 100);
   outfile << data <<endl;
   outfile.close();
   

}
