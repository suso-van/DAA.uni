#include<stdio.h>

#define INF 99999

int main()
{
    int p[10];
    int m[10][10];
    int n,i,j,k,L,q;

    printf("Enter number of matrices: ");
    scanf("%d",&n);

    printf("Enter dimensions:\n");

    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);

    for(i=1;i<=n;i++)
        m[i][i]=0;

    for(L=2;L<=n;L++)
    {
        for(i=1;i<=n-L+1;i++)
        {
            j=i+L-1;
            m[i][j]=INF;

            for(k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];

                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }

    printf("Minimum Multiplications = %d",m[1][n]);

    return 0;
}
