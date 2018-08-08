/*
ID: chinese21
LANG: C++
TASK: barn1
*/

//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int barns[210];
void find_min(int& l, int& r, int s){//[l,r) <= s
	l = 1; for(; !barns[l]; l++); for(; barns[l]; l++);
	r = l + 1; for(; !barns[r]; r++);
	int m = r - l, tl = l, tr = r;
	while(tr <= s){
		for(; tr <= s && barns[tr]; tr++); tl = tr;
		for(; tr <= s && !barns[tr]; tr++);
		if(tr <= s && tr - tl < m) l = tl, r = tr, m = r - l;
	}
}
int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int m, s, c;scanf("%d%d%d", &m, &s, &c);
	int num;
	for(int i = 0; i < c; i++){
		scanf("%d", &num); barns[num] = 1;
	}
	//count the original stalls
	int stalls = 0; for(int i = 1; i <= s; i++) if(barns[i] && !barns[i - 1]) stalls++;
//	int cnt = 0; for(int i = 1; i <= s; i++) if(barns[i]) cnt++; cout << cnt;
	if(stalls <= m) {printf("%d\n", c); exit(0);}
	//it has at least 2 consecutive blocks
	int cost = c;
	while(stalls - m > 0){
		int l, r; find_min(l, r, s);
		for(int i = l; i < r; i++) barns[i] = 1;
		cost += r - l;
		stalls--;
	}
	printf("%d\n", cost);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
