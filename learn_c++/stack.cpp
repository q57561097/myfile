#include<iostream>
#include<cstdlib>
#define max_size 5
using namespace std;
typedef struct stack{
    int top;
    int data[max_size];
}stack;
bool stackfull(stack *stacks);
void insert_stack(int num, stack *stacks){
      if (stackfull(stacks)){
         cout <<"栈已满" <<endl;
}     
      else {
        stacks->data[++stacks->top] = num;}

}

bool stackempty(stack *stacks){
   if (stacks->top == -1) return true;
   else return false;

}

bool stackfull(stack *stacks){
  if (stacks->top == max_size -1) return true;
  else return false;

}

int del_stack(stack *stacks){
  if (stackempty(stacks)){
     cout<<"栈已空"<<endl;
     //exit(0);
     return 0;
}
  else{
     return stacks->data[stacks->top--];
}
}

void print_stack(stack *stacks){
     int top;
     top = stacks->top;
     while(top>=0){
           cout<<stacks->data[top]<<endl;
           top--;

}

}
int main(){
   stack stacks;
   stacks.top=-1;
   int i;
   stack *stack1;
   stack1 = &stacks;
   for (i=10;i>1;i--){
       insert_stack(i ,stack1);

}
  print_stack(stack1);
  cout<<"del"<<endl;
  for (i=10;i>1;i--) cout<<del_stack(stack1)<<endl;
  cout<<"print"<<endl;
  print_stack(stack1);
}
