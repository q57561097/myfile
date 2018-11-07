#include<iostream>
using namespace std;
typedef struct stack{
        char data;
        stack *next;

}stack;

void push(char num, stack *top){
	stack *p;
        p = new stack;
        p->data = num;
        p->next = top->next;
        top->next= p;
}


stack pop(stack *top, char &e){
stack *p;
if (top->next !=NULL){
   p=top->next;
   e=p->data;
   top->next=p->next;
   delete p;
}
}

bool check_stack(){
   stack *top = new stack;
   char list[10];
   cin.get(list,10);
   char a='a';
   int i;
   //for (i=0;i<10;i++) cout<<list[i]<<endl;
   for (i=0;i<10;i++){
	if (list[i] == '(' || list[i]== '[') push(list[i], top);
   	else if (list[i] == ')'){
        a = 'a';
        pop(top, a);
        if (a != '(') return false;
	
          }
        else if (list[i] == ']'){
         a = 'a';
         pop(top,a);
         if (a!= '[') return false;
        }          
}
   return true;
}
int main(){
	stack *top;
        top = new stack;
        top->next=NULL;
        char a;
        pop(top, a);
        cout<<a<<"pop1"<<endl;
        push('1', top); 
        pop(top, a);
        cout<<a<<"pop2"<<endl;
        cout<<check_stack()<<endl;

}
