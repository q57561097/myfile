#include<iostream>
#define max_size 10
using namespace std;

typedef struct tree{
	int data;
	tree *lchild,*rchild;
}tree;
	

tree *insert_node(tree *tr, int data){
	tree *node;
	node = new tree;
	node->data=data;
	node->lchild= NULL;
	node->rchild=NULL;
	tree *p=tr, *f=NULL;
	if (tr==NULL) return node;
	while (p!=NULL){
		f=p;
		if(node->data<p->data) p=p->lchild;
		else p=p->rchild;	
	}
	if (node->data<f->data) f->lchild=node;
	else f->rchild=node;
	return tr;

}

tree *create_tree(){
	tree *tr, *node;
	tr = NULL;
        int i;
	for (i=max_size;i>0;i--) tr=insert_node(tr,i);
	return tr;
}

void print_tree(tree *tr){
	if (tr!=NULL){
	print_tree(tr->lchild);
	cout<<tr->data<<endl;
	print_tree(tr->rchild);
	}
	
	}

int main(){
	tree *tr, *node;
	tr = create_tree();
	tr = insert_node(tr, 3);
	print_tree(tr);
        
	return 0;
	}
