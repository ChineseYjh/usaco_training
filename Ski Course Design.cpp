/*
ID: chinese21
LANG: C++
TASK: skidesign
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int ans = INF;
int hills[1100];
const int x = 17;
int main()
{
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	int n; scanf("%d", &n); for(int i = 0; i < n; i++) scanf("%d", hills + i);
	sort(hills, hills + n);
	if(hills[n - 1] - hills[0] <= x) { puts("0"); exit(0);}
	int low = hills[0], up = hills[n - 1] - x;
	for(int i = low; i <= up; i++){
		int temp = 0; int dh;
		for(int j = 0; j < n; j++) {if((dh = i - hills[j]) > 0) temp += dh * dh; else if((dh = hills[j] - i - x) > 0) temp += dh * dh;}
		if(temp < ans) ans = temp;
	}printf("%d\n", ans);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
