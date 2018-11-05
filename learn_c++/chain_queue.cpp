#include<iostream>

using namespace std;

typedef struct qnode{
      int data;
      qnode *next;

}qnode;

typedef struct q_link{
     qnode *front, *rear;

}q_link;


void insert(int num ,q_link *queue){
    qnode *q = new qnode;
    q->data = num;
    q->next = NULL;
    queue->rear->next=q;
    queue->rear = q;
    cout<<num<<"入队"<<endl;
   

}

void pop(q_link *Q){
     qnode *p;
     if (Q->front == Q->rear) cout<<"队空"<<endl;
     else {
          p=Q->front->next;
          cout<<p->data<<"出队"<<endl;
          Q->front->next = p->next;
          if (p==Q->rear) Q->rear=Q->front;
          delete p;
         }
}


int main(){
    q_link Q;
    qnode *p = new qnode;
    p->next = NULL;
    Q.front=Q.rear=p;
    int i;
    for (i=0;i<=10;i++) insert(i, &Q);
    for (i=0;i<=15;i++) pop(&Q);


}
