#include <stdio.h>
void dijkstra(int G[][], int n, int startnode, int endnode)
{
    int cost[n][n], distance[n], pred[n];
    int visited[n], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != startnode && distance[i] != INFINITY)
        {
            printf("\n\nDistance of %d = %d", i + 1, distance[i]);
            printf("\nPath = %d", i + 1);
            j = i;
            do
            {
                j = pred[j];
                printf(" <- %d", j + 1);
            } while (j != startnode);
        }
}

void prepare_adj_mat(int adj_mat[][],int n, int m){
1 2 3
4 5 6
7 8 9

n=row
m=column
x=i+1

if(x%m!=1)
    adj[]
    
}

int main()
{
    int n = 5, m = 6;
    int adj_mat[n * m][n * m];
    int i, j, count = 0, i1, i2, m1, m2, j1, j2, temp;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            if (temp == 1)
            {
                i1 = i;
                j1 = j;
                m1 = count;
            }
            else if (temp == 2)
            {
                i2 = i;
                j2 = j;
                m2 = count;
            }

            count++;
        }
    }
    dijkstra(adj_mat, n, m1, m2);
    printf("\n");
    return 0;
}
