#include<stdio.h>

int main()
{
    int n,W;
    int wt[10],val[10];
    int dp[10][20];
    int i,j;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter weights:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&wt[i]);

    printf("Enter values:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&val[i]);

    printf("Enter capacity: ");
    scanf("%d",&W);

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;

            else if(wt[i]<=j)
            {
                int take=val[i]+dp[i-1][j-wt[i]];
                int leave=dp[i-1][j];

                if(take>leave)
                    dp[i][j]=take;
                else
                    dp[i][j]=leave;
            }

            else
                dp[i][j]=dp[i-1][j];
        }
    }

    printf("Maximum Profit = %d",dp[n][W]);

    return 0;
}
