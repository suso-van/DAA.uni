#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    char x[20],y[20];
    int dp[20][20];
    int i,j,m,n;

    printf("Enter first string: ");
    scanf("%s",x);

    printf("Enter second string: ");
    scanf("%s",y);

    m=strlen(x);
    n=strlen(y);

    for(i=0;i<=m;i++)
        dp[i][0]=0;

    for(j=0;j<=n;j++)
        dp[0][j]=0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];

            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    printf("Length of LCS = %d",dp[m][n]);

    return 0;
}
