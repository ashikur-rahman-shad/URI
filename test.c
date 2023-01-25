 #include <stdio.h>

void prepare_adj_mat(int *adj,int n, int m){
//1  2  3  4
//5  6  7  8
//9 10 11 12

//  1 2 3 
//1 0 1 0
//2 1 0 1
//3 0 1 0

int i,j, x;
//n=row
//m=column
for(i=0;i<n*m;i++)
    for(j=0;j<n*m;j++)
        *adj[i][j]=0;


for(i=0; i<n*m;i++){
    x=i+1;
    if(x%m!=1)
        adj[i][i-1]=1;
    if(x%m!=0)
        adj[i][i+1]=1;
    if(x-m!>1)
        adj[i][i-m]=1;
    if(x+m<m*n)
        adj[i][i+m]=1;  
}

}

int main()
{
    int n = 5, m = 6;
    int adj[n * m][n * m];
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
    //dijkstra(adj_mat, n, m1, m2);
    prepare_adj_mat(&adj,n,m);
    for(i=0;i<n*m;i++){
        for(j=0;j<n*m;j++)
            printf("%d ",adj[i][j]);
        prinf("\n");
    }
    printf("\n");
    return 0;
}
