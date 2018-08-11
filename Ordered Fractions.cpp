/*
ID: chinese21
LANG: C++
TASK: frac1
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int dp[200]; // i's numerator is dp[i]
struct decimal
{
	int num, dem;
	decimal(int a = 0, int b = 0): num(a), dem(b) {}
} d[40000];
int ptr;
bool operator < (const decimal& a, const decimal& b){
	return a.num * b.dem < a.dem * b.num;
}
int gcd(int a, int b){
	return a % b ? gcd(b, a % b) : b;
}
int main()
{
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	int n; scanf("%d", &n);
	printf("0/1\n1/%d\n", n);
	for(int i = 2; i < n; i++){
		for(int j = 2; j < n; j++){
			int x = dp[j] + 1;
			if(x * n < i * j){
				dp[j] = x;
				if(x != 1 && gcd(j, x) != 1) continue; else d[ptr++] = decimal(x, j);
			}
		}
		if(gcd(i, n) == 1) d[ptr++] = decimal(i, n);
	} sort(d, d + ptr);
	for(int i = 0; i < ptr; i++) printf("%d/%d\n", d[i].num, d[i].dem);
	if(n != 1) puts("1/1");
	
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
