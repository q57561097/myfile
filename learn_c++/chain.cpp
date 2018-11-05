#include<iostream>

using namespace std;

typedef struct Node{
        struct Node *next;
        int data;
}Liststruct;


void insert_node(int num, Node *rear){
    cout<<rear<<endl;
    Node *new_node = new Node;
    new_node->data = num;
    new_node->next = NULL;
    rear->next = new_node;
    //cout<<rear->next->data<<endl;
    rear = new_node; 
}

Node *find_node_by_key(int num, Node *head){
	Node *p = head;
        while (p!=NULL&&p->data!=num){
               p=p->next;
} 
        return p;
}
void insert_node_by_index(int num, Node *rear, int data){
	Node *p, *s;
        p = rear;
        int j=0;
        while (p->next !=NULL&& j<num-1){
	p=p->next;
        j++;
}
        if (j!=num-1) cout<<"数值太大"<<endl;
        else{
            s = new Node;
            s->data=data;
            s->next= p->next;
            p->next=s;
}
}
void create_node(int num, Node *head){
	//static Node *head = new Node;
        Node *rear = head;
        rear->next = NULL;
        int i;
        for (i=1;i<=num;i++){
           Node *new_node = new Node;
           new_node->data = i;
           new_node->next = NULL;
           rear->next = new_node;
           cout<<rear->next->data<<endl;
          rear = new_node;
    }
     
}

void print_node(Node *head){
        Node *p= head;
	while (p->next!=NULL){
		p=p->next;
                cout<<p->data<<endl;

}

}

void del_node(int num, Node *head){
  Node *p = head;
  int j=0;
  while (p!=NULL&&j<num -1){
         p=p->next;
         j++;
    
}
if (j!=num-1) cout<<"索引过大"<<endl;
else {
	Node *s;
        s=p->next;
        p->next=s->next;
        delete s;
}
}
int main(){
     Node *rear, *p, *head;
     head = new Node;
     create_node(10, head);
     rear = head; 
     //for (i=1;i<=10;i++) insert_node(i, rear);
    
     //cout<<rear->data<<"1"<<endl;
     //cout<<p->next->data<<"2"<<endl;
     //cout<<head->next->data<<"3"<<endl;
     print_node(head);
     p = find_node_by_key(15, head);     
     if (p!=NULL) cout<<p<<endl;
     else  cout<<"null"<<endl;
     insert_node_by_index(5, head, 15);
     print_node(head);
     cout<<"insert"<<endl;
     if (p!=NULL) cout<<p->data<<endl;
     else cout<<"null"<<endl;
     cout<<"del"<<endl;
     del_node(5, head);
     print_node(head);
     


}


