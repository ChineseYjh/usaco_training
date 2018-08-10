/*
ID: chinese21
LANG: C++
TASK: numtri
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int tri[1010][1010];
int sum[1010];
int main()
{
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	int n; scanf("%d", &n); for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++) scanf("%d", &tri[i][j]);
	for(int i = 1; i <= n; i++) sum[i] = tri[n][i];
	for(int i = n - 1; i >= 1; i--) for(int j = 1; j <= i; j++) sum[j] = tri[i][j] + max(sum[j], sum[j + 1]);
	printf("%d\n", sum[1]);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
