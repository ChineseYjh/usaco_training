/*
ID: chinese21
LANG: C++
TASK: subset
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int INF = 0x3f3f3f3f;

int n;
int dp[50][1200];
signed main()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	
	scanf("%lld", &n);
	if(n % 4 == 1 || n % 4 == 2){ puts("0"); exit(0);}
	for(int i = 0; i <= n; i++) dp[i][0] = 1;//dp[0][i] = dp[1][i(>1)] = 0
	int range = n * (n + 1) / 4;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= range; j++) if(j < i) dp[i][j] = dp[i - 1][j]; else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
	printf("%lld\n", dp[n][range] / 2);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
