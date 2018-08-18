/*
ID: chinese21
LANG: C++
TASK: runround
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;

bool is_runaround(ull n){
	int bit = 1; for(; n / (ull)pow(10, bit); bit++);
	//store
	int nums[30]; bool visited[10]; memset(visited, 0, sizeof(visited));
	for(int i = bit; i > 0; i--){
		int t = nums[bit - i] = (n / (ull)pow(10, i - 1)) % 10;
		if(t == 0 || visited[t]) return false;
		visited[t] = true;
	}
	//simulate
	int ptr = 0, step = nums[ptr]; visited[step] = false; 
	for(int i = 1; i < bit; i++){
		ptr = (ptr + step) % bit; step = nums[ptr];
		if(visited[step] == false) return false;
		visited[step] = false;
	}if((ptr + step) % bit) return false;
	return true;
}

int main()
{
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	
	ull n; scanf("%lld", &n);
	for(ull i = n + 1; ; i++){
		if(is_runaround(i)) {printf("%lld\n", i); break;}
	}
	
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
