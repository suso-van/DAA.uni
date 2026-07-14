#include<stdio.h>

#define INF 9999

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

int main()
{
    int coin[10];
    int dp[100];
    int n,amount;
    int i,j;

    printf("Enter number of coins: ");
    scanf("%d",&n);

    printf("Enter coin values:\n");

    for(i=0;i<n;i++)
        scanf("%d",&coin[i]);

    printf("Enter amount: ");
    scanf("%d",&amount);

    dp[0]=0;

    for(i=1;i<=amount;i++)
        dp[i]=INF;

    for(i=1;i<=amount;i++)
    {
        for(j=0;j<n;j++)
        {
            if(coin[j]<=i)
                dp[i]=min(dp[i],1+dp[i-coin[j]]);
        }
    }

    printf("Minimum Coins = %d",dp[amount]);

    return 0;
}
