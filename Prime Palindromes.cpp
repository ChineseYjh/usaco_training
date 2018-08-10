/*
ID: chinese21
LANG: C++
TASK: pprime
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

inline bool is_prime(int a){
	int bound = (int)sqrt(a);
	for(int i = 2; i <= bound; i++) if(a % i == 0) return false;
	return true;
}
//reverse the number
inline int rev(int a, int len){
	int ans = 0; for(int i = 0; i < len; i++) ans += ((a / (int)pow(10, i)) % 10 * (int)pow(10, len - i - 1));
	return ans;
}
int main()
{
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	
	int a, b; scanf("%d%d", &a, &b);
	if(a <= 2) puts("2"); if(a <= 3) puts("3"); if(a <= 5) puts("5"); if(a <= 7) puts("7"); if(a <= 11) puts("11");
	//firstly generate palindromes
	bool is_on = false;
	for(int len = 2; len <= 4; len++){
		int low = (int)pow(10, len - 1), up = (int)pow(10, len) - 1;
		for(int root = low; root <= up; root++){
			int r = rev(root / 10, len - 1); if(r % 2 == 0) continue;
			int x = root * (int)pow(10, len - 1) + r;
			if(x >= a) is_on = true;
			if(x > b){len = 4; break;}
			if(is_on && is_prime(x)) printf("%d\n", x);
		} 
	}
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
