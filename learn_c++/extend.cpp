#include<iostream>
#include<string>
using namespace std;

class class1{
  private:
    int name;
  public:
   void  get_name(){
    cout << name << endl;
} 
   class1(int name1){
     name = name1;

}   
   virtual void print_name(){
    cout << "class1" << endl;


}

};

class class2: public class1{
  public:
     class2(int name1):class1(name1){
           
}
     void print_name(){
     cout << "class2" << endl;
}
};

int main(){
    class2 object(3);
    class1 *object2;
    //object.name = 2;
    object.get_name();
    object.print_name();
    object2 = &object;
    object2->print_name();

}
