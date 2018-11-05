#include <stdio.h>
# include<stdlib.h>
# include "create_chain.h"

Link create_chain1(int start, int end){
        Link p,head = (Link)malloc(sizeof(Node));
	Link s;
        p = head;
        int i;
	for (i=start;i<end;i++)
	{
	   s = (Link)malloc(sizeof(Node));
	   s->data = i;
	   p->next = s;
           p=s;
	}
	return head;

}
//void main(){
//	Link p = create_chain1();
//        int num;
//        
//	while (p->next){
//	    p = p->next;
//            printf("%d\n", p->data);
//
//	}
//
//
//}
