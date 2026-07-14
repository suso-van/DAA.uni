#include<stdio.h>

int main()
{
    int dp[10][10];
    int i,j,m,n;

    printf("Enter rows and columns: ");
    scanf("%d%d",&m,&n);

    for(i=0;i<m;i++)
        dp[i][0]=1;

    for(j=0;j<n;j++)
        dp[0][j]=1;

    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }

    printf("Number of Paths = %d",dp[m-1][n-1]);

    return 0;
}
