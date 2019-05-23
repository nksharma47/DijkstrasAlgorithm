#include <stdio.h>

int main(void) 
{
	int cost[10][10],start,visited[10],pred[10],dist[10],min,i,j,n,count,next;
	
	printf("Enter No. of Vertices:\n");
	scanf("%d",&n);
	printf("Enter Adjacency Matrix:\n");
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        scanf("%d",&cost[i][j]);
	    }
	}
	printf("Enter starting vertex: ");
	scanf("%d",&start);
	
	for(int i=0;i<n;i++)
	{
	    dist[i]=cost[start][i];
	    visited[i]=0;
	    pred[i]=start;
	}
	visited[start]=1;
	dist[start]=0;
	count=1;
	while(count < n-1)
	{
	    min=999;
	    for(i=0;i<n;i++)
	    {
	        if(min>dist[i] && !visited[i])
	        {
	            min=dist[i];
	            next=i;
	        }
	    }
	    visited[next]=1;
	    for(i=0;i<n;i++)
	    {
	        if(!visited[i])
	        {
	            if(min + cost[next][i] < dist[i])
	            {
	                dist[i]=min+cost[next][i];
	                pred[i]=next;
	            }
	        }
	    }
	    count++;
	}
	for(i=0;i<n;i++)
	{
	    if(i != start)
	    {
	        printf("\nDist of %c from %c = %d ",'A'+i,'A'+start,dist[i]);
	        printf("\nPath of %c",'A'+i);
	        j=i;
	        do
	        {
	            j=pred[j];
	            printf(" -> %c",'A'+j);
	        }while(j!=start);
	            
	    }
	}
	return 0;
}

