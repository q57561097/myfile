#include<iostream>
#define size 5
using namespace std;

typedef struct tu{
	char point[size];
	int line[size][size];

}tu;

typedef struct tu_node2{
	int index;
	struct tu_node2 *next;	
}tu_node;
typedef struct tu_link{
	char point;
	tu_node *link;
}tu_link;


int line1[size][size]= {{0,1,1,1,0},
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





void create_chain(tu *t, tu_link **link){
	//tu *t = create_tu();
	tu_node *n, *q;
	tu_link *p;
	int i,j, num;
	for (i=0;i<size;i++){
		cout<<i<<endl;
		p = new tu_link;
		link[i] = p;
		p->point = t->point[i];
		q = new tu_node;
		q ->next=NULL;
		p->link=q;
		n = q;
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
void dfs_chain_tu(tu_link **t, int i){
	tu_node *p;
	tu_link *s;
	s=t[i];
	p=s->link;
	int j;
	visit3[i]=1;
	cout<<s->point<<endl;
	while (p->next!=NULL){
		p=p->next;
		j=p->index;
		if (visit3[j]!=1){
		dfs_chain_tu(t, j);
	}	
	}
}

void bfs_chain_tu(tu_link**t, int i){
	int visit4[size];
	tu_link *queue[size];
	tu_node *p;
	tu_link *q;
	int front=0,rear=0;
	queue[rear++]=t[i];
	cout<<t[i]->point<<endl;
	visit4[i]=1;
	while (front!=rear){
		p=queue[front++]->link;
		while (p->next!=NULL){
			p=p->next;
			if (visit4[p->index]!=1){
				q=t[p->index];
				visit4[p->index]=1;
				cout<<q->point<<endl;
				queue[rear++]=q;
			}
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
        tu_link *link[size];	
	create_chain(&t, link);
	dfs_chain_tu(link,0);
	cout<<"chain bfs"<<endl;
	bfs_chain_tu(link,0);
        return 0;
	
}
