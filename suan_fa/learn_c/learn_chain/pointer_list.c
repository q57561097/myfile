#include<stdio.h>

void change_list_value(int(*arr)[2]){
     *(*(arr+1)+1)=10;
}

void main(){
    int list[] = {1,2,3};
    int *p = list;
    //change_list_value(p);
    //printf("%d\n",list[1]);
    int a[2][2] = {1, 2, 3,4};
    int (*p2)[2];
    p2 = a;
    void copy_string(int from[]);
   // printf("%d\n", a[1][1]);
    change_list_value(p2);
    //printf("%d\n", a[1][1]);
    copy_string(p); 

}
void copy_string(int from[]){
 printf("%d\n", *(++from));

}
