#include<stdio.h>
#include<stdlib.h>
#include "create_chain.h"
extern Link create_chain1();
void main()
	{
        Link a = create_chain1(1, 10);
        Link b = create_chain1(5,15);
        Link d,u,c;
        d=a;
        c=a->next;
        b=b->next;
        while(b&&c)
	        {
                 if (c->data==b->data)
                    {
			u=b;
                   	a->next=c;
                        a=a->next;
                    	c=c->next;
                    	b=b->next;
                        
			}
                else if(c->data>b->data)
			{
			   u=b;
                           b=b->next;
			}
                else
			{
                         u=c;
                         c=c->next;
			}
                free(u);

		}
      while(c)
		{
                u=c;
                c=c->next;
                free(u);
              }
      while(b)
            {
              u=b;
              b=b->next;
              free(u);
		}
      a->next=NULL;
      while(d->next)
             {
            d=d->next;
            printf("%d\n", d->data);
	}
}
