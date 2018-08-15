/*
ID: chinese21
LANG: C++
TASK: hamming
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n, b, d;
int range;//exclusive
int choice[70] = {-1};
bool bitdif(int n, int m){//whether hamming distance between n and m is at least d
	int dif = 0;
	for(int i = 0; i < b; i++) if((n & (1 << i) )!= (m & (1 << i))) dif++;
	return dif >= d;
}
void print_choice(){
	for(int i = 1; i < n; i++){
		printf("%d", choice[i]);
		if(i % 10) putchar(' '); else putchar('\n');
	}printf("%d\n", choice[n]);
}
bool dfs(int cur){
	if(cur <= n){
		int x = choice[cur - 1];
		if(range - x < n - cur + 2) return false;//not able to fullfill choice[1-n]
		for(int i = x + 1; i < range; i++){
			int j = 1; for(; j < cur; j++) if(!bitdif(i, choice[j])) break;//pruning
			if(j < cur) continue; 
			choice[cur] = i;
			if(dfs(cur + 1)) return true; 
		}
		return false;
	}print_choice();
	return true;
}
int main()
{
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	
	scanf("%d%d%d", &n, &b, &d);
	range = 1 << b;
	dfs(1);
	
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
