#include<iostream>
#define size 5
using namespace std;

typedef struct tu{
	char point[size];
	int line[][size];

}tu;

typedef struct tu_node2{
	int index;
	struct tu_node2 *next;
	char point;	
}tu_node;
typedef struct tu_link{
	char point;
	tu_node *link;
}tu_link;


int line1[][size]= {{0,1,1,1,0},
		    {0,0,0,1,0},
		    {0,1,0,0,1},
		    {0,0,1,0,1},
		    {0,1,0,0,0}};


tu *create_tu(){
	tu *t = new tu;
	char points[]={'0','1','2','3','4'};
	int i, j;
        for (i=0;i<size;i++) {
	t->point[i]=points[i];
	for (j=0;j<size;j++) t->line[i][j] = line1[i][j];

	}
	
	return t;	
}





void create_chain(tu *t, tu_node **link){
	//tu *t = create_tu();
	cout<<333<<endl;
	tu_node *n, *q, *p;
	cout<<7777777777<<endl;
	int i,j;
	cout<<5555555<<endl;
	for (i=0;i<size;i++){
		cout<<i<<endl;
		//p = new tu_link;
		cout<<999<<endl;
		//link[i] = p;
		link[i]->point = t->point[i];
		n = link[i]->next;
		for (j=0;j<size;j++){
			if (t->line[i][j]==1) {
				q= new tu_node;
				q->index = j;
				q->next = NULL;
				n->next=q;
				n=q;
				cout<<"v"<<i<<"v"<<j<<endl;		
				}
		} 
	}

}
int visit[size];
void dfs_tu(tu *t, int i){
	int j;
        if (visit[i]!=1){
	cout<<t->point[i]<<endl;
	visit[i]=1;
	for (j=0;j<size;j++){
	if (t->line[i][j]==1) dfs_tu(t, j);
	
	}

	}
	}
void bfs_tu(tu *t, int j){
	int visit2[size];
	visit2[j] = 1;
	int front=0,rear=0, p, i;
	int data[size];
	data[rear++] =0;
	cout<<t->point[0]<<endl;
	while (front!=rear){
	p=data[front++];
	for (i=0;i<size;i++){
		if(t->line[p][i]==1&&visit2[i]!=1) {
		cout<<t->point[i]<<endl;
		data[rear++] = i;
		visit2[i] = 1;
		};

	}
	}
}
int visit3[size];
void dfs_chain_tu(tu_link *t[], int i){
	tu_node *p;
	tu_link *s;
	s=t[i];
	p=s->link;
	int j;
	while (p->next!=NULL){
		p-p->next;
		j=p->index;
		if (visit3[j]!=1){
		visit3[j]=1;
		cout<<s->point<<endl;
		dfs_chain_tu(t, j);
	}	
	}
}
int main(){
	tu *t = create_tu();
	tu_node *p;
	cout<<5555555555<<endl;
	p = new tu_node;
	cout<<777777<<endl;
	dfs_tu(t, 0);
        cout<<"bfs"<<endl;
	bfs_tu(t, 0);
	cout<<"chain dfs"<<endl;
        tu_node *link[size];

	cout<<77777<<endl;
	int i;
	for (i=0;i<size;i++) {
	cout<<i<<endl;
	//p = new tu_node;
	cout<<9999<<endl;
	link[i]= p;
	};
	create_chain(t, link);
	//dfs_chain_tu(ch,0);
	return 0;
}
