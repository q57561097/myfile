#include<iostream>
#define max_size 10
using namespace std;

typedef struct queue{

   int data[max_size];
   int front;
   int rear;

}queue;


void Insert (int num, queue *que){

if((que->rear+1)%max_size == que->front) cout<<"队满"<<endl;
else {que->data[que->rear] =num;
      cout<<num<<"入队"<<endl;
      que->rear = (que->rear+1) %max_size;

    }

}

void pop(queue *que){
if(que->rear == que->front) cout<<"队空"<<endl;

else {  cout<<que->data[que->front]<<"出队"<<endl;
        que->front = (que->front+1) % max_size;
     } 

}
int main(){
  queue que;
  que.front=que.rear=0;
  
  int i;
  for (i=0;i<=5;i++)  Insert(i,&que);
  for (i=0;i<=15;i++) pop(&que);
}
             
