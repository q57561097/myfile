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
//typedef struct tu_link{
//	char point;
//	tu_node *link;
//}tu_link;


int line1[][size]= {{0,1,1,1,0},
		    {0,0,0,1,0},
		    {0,1,0,0,1},
		    {0,0,1,0,1},
		    {0,1,0,0,0}};


void create_tu(tu *t){
	char points[]={'0','1','2','3','4'};
	int i, j;
        for (i=0;i<size;i++) {
	t->point[i]=points[i];
	for (j=0;j<size;j++) t->line[i][j] = line1[i][j];

	}
	
		
}





void create_chain(tu *t, tu_node **link){
	//tu *t = create_tu();
	tu_node *n, *q, *p;
	int i,j, num;
	for (i=0;i<size;i++){
		cout<<i<<endl;
		//p = new tu_link;
		//link[i] = p;
		link[i]->point = t->point[i];
		n = link[i];
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
	cout<<777<<endl;

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
void dfs_chain_tu(tu_node **t, int i){
	tu_node *p;
	tu_node *s;
	s=t[i];
	p=s;
	int j;
	visit3[i]=1;
	cout<<p->point<<endl;
	while (p->next!=NULL){
		p=p->next;
		j=p->index;
		if (visit3[j]!=1){
		dfs_chain_tu(t, j);
	}	
	}
}
int main(){
	tu t;
        int i;
	create_tu(&t);
	tu_node *p;
	dfs_tu(&t, 0);
        cout<<"bfs"<<endl;
	bfs_tu(&t, 0);
	cout<<"chain dfs"<<endl;
        tu_node *link[size];	
	for (i=0;i<size;i++) {
	cout<<i<<endl;
	p = new tu_node;
	cout<<9999<<endl;
	link[i]= p;
	};
	create_chain(&t, link);
	dfs_chain_tu(link,0);
        cout<<999<<endl;
	
}
