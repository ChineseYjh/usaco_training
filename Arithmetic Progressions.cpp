/*
ID: chinese21
LANG: C++
TASK: ariprog
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int cnt;
bool bs[300000];
int s[90000];
int ptr;
bool dfs(int a, int d, int n){
	for(int i = 0; i < n; i++){
		if(bs[a] == false){
			for(int j = 1; j <= i; j++) bs[a - j * d] = false;
			return false;
		}
		a += d;
	}
	return true;
}

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	
	int n, m; scanf("%d%d", &n, &m);
	//pre-process
	for(int i = 0; i <= m; i++) for(int j = 0; j <= m; j++) bs[i * i + j * j] = true, s[ptr++] = i * i + j * j;
	sort(s, s + ptr);
	ptr = unique(s, s + ptr) - s;
	//search
	int a, b, bbound = 2 * m * m / (n - 1);
	for(b = 1; b <= bbound; b++){
		for(int i = 0; i < ptr; i++){
			a = s[i];
			if(dfs(a, b, n)) {
				printf("%d %d\n", a, b); cnt++;
			}
		}
		for(int i = 0; i < ptr; i++) bs[s[i]] = true;
	}
	if(!cnt) puts("NONE");
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
