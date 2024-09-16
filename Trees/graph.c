#include<stdio.h>
int G[5][5]={
	{0,1,1,0,0},
	{1,0,0,1,0},
	{1,0,0,0,1},
	{0,1,0,0,1},
	{0,0,1,1,0},
};
int visited[5]={0,0,0,0,0};

void dfs(int a){
	printf("%d ",a);
	int i;
	visited[a]=1;
	for(i=0;i<5;i++){
		if(G[a][i]==1 && visited[i]==0){
			dfs(i);
			}
	}
}


int main(){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
		printf("\n\n\n\n\n");
	dfs(4);
}