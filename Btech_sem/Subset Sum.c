#include<stdio.h>

int main()
{
    int set[10];
    int dp[20][50];
    int n,sum;
    int i,j;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");

    for(i=1;i<=n;i++)
        scanf("%d",&set[i]);

    printf("Enter required sum: ");
    scanf("%d",&sum);

    for(i=0;i<=n;i++)
        dp[i][0]=1;

    for(j=1;j<=sum;j++)
        dp[0][j]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(set[i]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-set[i]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][sum])
        printf("Subset Exists");
    else
        printf("Subset Does Not Exist");

    return 0;
}
