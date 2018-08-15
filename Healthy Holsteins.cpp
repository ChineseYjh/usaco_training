/*
ID: chinese21
LANG: C++
TASK: holstein
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int need[30], v;
int feed[20][30], g;
int buy[30];
int dfs(int cur, int depth){
	if(cur <= depth){
		int x = buy[cur - 1];
		if(depth - cur + 1 > g - x) return 0; //make sure buy[1-depth] can be filled
		for(int i = x + 1; i <= g; i++){
			 buy[cur] = i;
			 int ans = dfs(cur + 1, depth);
			 if(ans) return ans;
		}
	}
	//cur == depth
	bool flag = true;
	for(int i = 1; i <= v; i++){
		int x = 0;
		for(int j = 1; j <= cur; j++) x += feed[buy[j]][i];
		if(x < need[i]){flag = false; break;}
	}if(flag) return depth;
	return 0;
}
int main()
{
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	
	scanf("%d", &v); for(int i = 1; i <= v; i++) scanf("%d", need + i);
	scanf("%d", &g); for(int i = 1; i <= g; i++) for(int j = 1; j <= v; j++) scanf("%d", &feed[i][j]);
	int cur = 0;
	for(int i = 1; i <= g - 1; i++) if((cur = dfs(1, i))) break;
	if(cur == 0){
		printf("%d", g); for(int i = 1; i <= g; i++) printf(" %d", i); putchar('\n'); exit(0);
	}
	printf("%d", cur); for(int i = 1; i <= cur; i++) printf(" %d", buy[i]); putchar('\n');
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
