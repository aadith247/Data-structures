#include <bits/stdc++.h>
using namespace std;


#define N 7


int multistagegraph(int stages, int graph[N][N], int start) {
   
    if(start==6)
    {
        return 0;
    }

     int mini=INT_MAX;

     
    for(int i=0;i<N;i++)
    {

        if(graph[start][i]!=0 && graph[start][i]!=1000)
        {

           int x=graph[start][i]+multistagegraph(stages-1,graph,i);
           mini=min(mini,x);
        }

    }
    return mini;


 
}

int main() {

    int graph[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},          
        {0, 0, 2, 1, 1000, 1000, 1000},   
        {0, 1000, 0, 1000, 3, 4, 1000},  
        {0, 1000, 1000, 0, 2, 3, 1000},    
        {0, 1000, 1000, 1000, 0, 1000, 2},  
        {0, 1000, 1000, 1000, 1000, 0, 3},  
        {0, 1000, 1000, 1000, 1000, 1000, 0} 
    };
   
         int x= multistagegraph(4,graph,1);
         cout << x;
         cout << endl;


    };
