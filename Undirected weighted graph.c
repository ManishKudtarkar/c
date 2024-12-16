# include <stdio.h>
# include <stdlib.h>

# define size 4

int Graph[size][size];

void InitGraph()
{
    int i, j;
    
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
            Graph[i][j] = -1;
    printf("Graph Prepared: %d Nodes No Edges \n",size);
}

void InsertEdge()
{
    int s,e,w;
    
    printf("Give Start,Endpoint and Weight for the Edge \n");
    scanf("%d %d %d", &s, &e, &w);
    
    Graph[s][e] = w;
    Graph[e][s] = w;
}

void DisplayGraph()
{
    int i, j;
    
    for(i=0; i<size; i++)
    {
        printf("Node %d connects with: \t",i);
        for(j=0; j<size; j++)
        {
            if(Graph[i][j] != -1)
                printf("%d \t (%d) : \t", j, Graph[i][j]);
        }
        printf("\n");
    }
}

void PrimsPath()
{
    
}

void KruskalPath()
{
    
}

int main() 
{
    int ch = 1;
    
    InitGraph();
    
    while(ch)
    {
        printf("<1> Insert an Edge <2> Display Graph \n");
        printf("<3> Prims Min Path <4> Kruskals Min Path\n");
        printf("<0> Exit \n");
        
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                    InsertEdge();
                    break;
            case 2:
                    DisplayGraph();
                    break;
            case 3:
                    PrimsPath();
                    break;
            case 4:
                    KruskalPath();
                    break;
            default:
                    exit(0);
        }
    }
    
    return 0;
}
