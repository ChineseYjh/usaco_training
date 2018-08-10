/*
ID: chinese21
LANG: C++
TASK: milk3
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int a, b, c;
bool v[22][22];//v[a][c]
void dfs(int aa, int cc){
	v[aa][cc] = true;
	int ta, tb, tc; 
	//a->b
	if(c - cc > b) ta = c - b - cc; else ta = 0;
	if(!v[ta][cc]) dfs(ta, cc);
	//b->a
	if(c - cc > a) ta = a; else ta = c - cc;
	if(!v[ta][cc]) dfs(ta, cc);
	//a->c
	tc = aa + cc, ta = 0; if(!v[ta][tc]) dfs(ta, tc);
	//c->a
	if(cc + aa > a) ta = a, tc = cc - a + aa; else tc = 0, ta = aa + cc;
	if(!v[ta][tc]) dfs(ta, tc);
	//b->c
	tc = c - aa; if(!v[aa][tc]) dfs(aa, tc);
	//c->b
	if(c - aa > b) tc = c - b - aa; else tc = 0;
	if(!v[aa][tc]) dfs(aa, tc); 
}

int main()
{
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	scanf("%d%d%d", &a, &b ,&c);
	dfs(0, c);
	for(int i = 0; i < c; i++) if(v[0][i]) printf("%d ", i);
	printf("%d\n", c);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
