#include<iostream>

using namespace std;

class base{
	private:
	 static int x;
	 int h;
	public:
		int y;
		void get_num(){
			cout<<y<<endl;
		}
		friend class three;
		friend void get_h(base);

		
		void print1(){
		cout<<"base"<<endl;
		}
		virtual void print2(){
 		cout<<"base"<<endl;
		}
		void get_x();
	protected: 
	int z;
		
};

void base :: get_x(){
	cout<<"x:"<<x<<endl;
}
int base::x=5;
void get_h(base bc){
	cout<<"h:"<<bc.h<<endl;
}
class one:public base{

	public:
		one(int);
		one(int, int);
		one(const one &oc);
		void get_y(){
			cout<<y<<endl;
		}
		void print1(){
		cout<<"one"<<endl;

		}
		void print2(){

		cout<<"one"<<endl;
		}
	
};
one::one(const one &oc){
	y=oc.y;
}

one::one(int num1){
			y=444;
			z=num1;
		}
one::one(int num1, int num2){
		y=num2;}
class three{
	public:
		void set_h(base& bc, int num){
			bc.h=num;
		}
	
};
int main(){
	base a,j;
	base *b;
	one d(1,3);
	one h(7);
	base &c = d;
	a = d;
	b= &d;
	//d.get_x();
	//a.get_y();
	//d.get_y()i
	d.get_y();
	h.get_y();
	
	three th;
	th.set_h(j, 55);
	get_h(j);
	one fuzhi(h);
	fuzhi.get_y();
	c.print1();
	c.print2();
	b->print1();
	b->print2();
	a.print1();
	a.print2();
}
