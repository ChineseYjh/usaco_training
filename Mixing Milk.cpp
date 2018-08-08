/*
ID: chinese21
LANG: C++
TASK: milk
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct milk
{
	int price, vol;
} milks[5100];
bool operator < (const milk& m, const milk& n){
	return m.price < n.price || m.price == n.price && m.vol > n.vol;
}
int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) scanf("%d%d", &milks[i].price, &milks[i].vol);
	sort(milks, milks + m);
	int out = 0, ptr = 0;
	while(n - milks[ptr].vol > 0){//not >=, if m == n == 0, it will cause segmentation fault
		n -= milks[ptr].vol; out += milks[ptr].vol * milks[ptr].price; ptr++;
	}
	out += n * milks[ptr].price; printf("%d\n", out); 
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
