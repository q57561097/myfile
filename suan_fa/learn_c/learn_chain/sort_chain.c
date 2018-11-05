# include<stdio.h>
# include "create_chain.h"
int main(){
        Link a = create_chain1(4,11);
        Link b = create_chain1(2,8);
        Link c, p;
        c = a;
        a = a->next;
        b = b->next;
        c->next = NULL;

        while (a||b){
            if(!a)
		{
                 p=b;b=b->next;  
		}
	    else {if(!b)
                  {
		   p=a;a=a->next;	
                  }   
            	  else {
                 if(a->data<=b->data){
                	p=a;
			a=a->next;
              		}
            	else
              		 {
               		p=b;
               		b=b->next;
                  }}}
           // printf("%d", p->data);
            p->next = c->next;
            c->next=p; }
       while (c->next){
            c=c->next;
           printf("%d\n",c->data);
            }
    return 0;

}

