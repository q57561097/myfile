#include<iostream>
#include<string>
#define max_size 100
using namespace std;

typedef struct tree{
	char data;
        tree *lchild,*rchild;
}tree;


tree *create_tree(){
	string str = "ABC@D@@@@EF";
        const char *str1 = str.data(); 
	char ch;
        tree *queue[max_size];
        tree *t,*s;
        int front,rear,j=0;
        front =0;
        rear = 0;
        ch =str1[0];
        while (ch!='\0'){
        s=NULL;
        if (ch!='@'){
		s=new tree;
                s->data=ch;
                s->lchild=s->rchild=NULL;
		}
	queue[rear++]=s;
	if (rear==1) t=s;
	else {
              if(s!=NULL&&queue[front]!=NULL){
		if (rear%2!=0) queue[front]->lchild=s;
		else queue[front]->rchild=s;
	
		}  
		 if (rear%2==0) front++;
		}
	ch=str[++j];
}
       return t;
}

void print_tree(tree *t){
	tree *queue[max_size];
	tree *p;
	if (t==NULL) return;
        else cout<<t->data<<endl;
        int front, rear;
        queue[0] =t;
	front =0, rear=1;
	while (front!=rear){
		p=queue[front++];
		if (p->lchild!=NULL){
			cout<<p->lchild->data<<endl;
			queue[rear++]=p->lchild;
			}
		if (p->rchild!=NULL){
			cout<<p->rchild->data<<endl;
			queue[rear++]=p->rchild;
			}
	}	
	
}
int main(){
    tree *t = create_tree();
	print_tree(t);

}
