/*
ID: chinese21
LANG: C++
TASK: castle
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

struct node
{
	int id;
	bool wall[4];
} nodes[60][60];//n*m
int m, n;
int s[2510], ptr;//id->s
void dfs(int i, int j, int& s){
	nodes[i][j].id = ptr; s++;
	for(int k = 0; k < 4; k++){
		if(nodes[i][j].wall[k] == 0){
			int ti = i, tj = j;
			k % 2 ? (k == 1 ? ti-- : ti++) : (k == 0 ? tj-- : tj++);
			if(nodes[ti][tj].id == 0) dfs(ti, tj, s);
		}
	}
}

int main()
{
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	//input
	scanf("%d%d", &m, &n); int temp;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &temp);
			for(int k = 0; k < 4; k++){
				if(temp & 1) nodes[i][j].wall[k] = 1;
				temp >>= 1;
			}
		}
	}
	//fill id and s
	ptr = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(nodes[i][j].id) continue;
			int ss = 0;
			dfs(i, j, ss);
			s[ptr++] = ss;
		}
	}
	ptr--;
	printf("%d\n%d\n", ptr, *max_element(s + 1, s + ptr + 1));
	int col, row, ms = 0; char d;
	for(int j = 1; j <= m; j++){
		for(int i = n; i >= 1; i--){
			int ts, thisid = nodes[i][j].id, thiss = s[thisid];
			if(nodes[i][j].wall[0] && thisid != nodes[i][j - 1].id && (ts = s[nodes[i][j - 1].id] + thiss) > ms) ms = ts, row = i, col = j - 1, d = 'E';
			if(nodes[i][j].wall[1] && thisid != nodes[i - 1][j].id && (ts = s[nodes[i - 1][j].id] + thiss) > ms) ms = ts, row = i, col = j, d = 'N';
			if(nodes[i][j].wall[2] && thisid != nodes[i][j + 1].id && (ts = s[nodes[i][j + 1].id] + thiss) > ms) ms = ts, row = i, col = j, d = 'E';
			if(nodes[i][j].wall[3] && thisid != nodes[i + 1][j].id && (ts = s[nodes[i + 1][j].id] + thiss) > ms) ms = ts, row = i + 1, col = j, d = 'N';
		}
	}
	printf("%d\n%d %d %c\n", ms, row, col, d);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
