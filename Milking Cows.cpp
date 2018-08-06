/*
ID: chinese21
LANG: C++
TASK: milk2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int l[5100], r[5100];
struct farmer
{
	int l, r;	
} f[5100];
bool operator < (const farmer& f1, const farmer& f2){
	return f1.l < f2.l || f1.l == f2.l && f1.r < f2.r; 
}
signed main() {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	int n; scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld%lld", &(f[i].l), &(f[i].r));
	sort(f + 1, f + n + 1);
	int ans = f[1].r - f[1].l;//最长连通串长度 
	int temp = ans;//当前连通串长度 
	int last = f[1].r;//前i-1个连通串最远右端 
	int ans2 = 0;//最长断层 
	for(int i = 2; i <= n; i++){
		if(f[i].l <= last && f[i].r > last){
			temp += f[i].r - last;
			if(temp > ans) ans = temp;
		}
		else if(f[i].l > last){
			temp = f[i].r - f[i].l;
			if(temp > ans) ans = temp;
			if(f[i].l - last > ans2) ans2 = f[i].l - last;
		}
		if(f[i].r > last) last = f[i].r;
	}
	printf("%lld %lld\n", ans, ans2);
	return 0;
}
