#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream read_file;
    read_file.open("./outfile");
    char data[200];
    read_file >>data ;
    cout << data << endl;
    read_file.close();

}


