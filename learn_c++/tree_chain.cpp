#include<iostream>
#include<string>

#define max_size 100
using namespace std;

typedef struct tree{
   char data;
   tree *lchild,*rchild;

}tree;

void inorder_print(tree *t2);
tree *create_tree(const char *str){
      tree  *str1[max_size];
      int k,j=0,top=-1;
      char ch=str[0];
      tree *p=NULL;
      tree *b=NULL;
      while (ch!='\0'){
          switch(ch){
		case '(':str1[++top]=p;k=1;break;
                case ')':top--;break;
                case ',':k=2;break;
                default : p = new tree;
                          p->data = ch;
                          p->lchild=p->rchild=NULL;
                          if (b==NULL) b=p;
                          else {
                                switch (k){
				        case 1: str1[top]->lchild=p;
					case 2: str1[top]->rchild=p;
					}
              
                               }
			}
                ch = str[++j];

		}
      //t1 = b;
      return b;
      //inorder_print(b); 		
}

void inorder_print(tree *t2){
	if (t2!=NULL){
		inorder_print(t2->lchild);
                cout <<t2->data<<endl;
                inorder_print(t2->rchild);
}
}

int main(){
      string str2 = "(A(B(,D(E,F)),C))";
      const char *str = str2.c_str();
      tree *t2;
      t2 = create_tree(str);
      //cout<<t2->data<<endl;
      inorder_print(t2);
} 
