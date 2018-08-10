/*
ID: chinese21
LANG: C++
TASK: sprime
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n;//int rib[10]
bool is_prime(ll a){
	for(ll i = 2; i * i <= a; i++) if(a % i == 0) return false;
	return true;
}
void sprime(int cur, ll temp){//cur >= 1
	if(cur == n){
		printf("%lld\n", temp); return;
	}
	for(int i = 1; i <= 9; i += 2){
		temp = 10 * temp + i;
		if(!is_prime(temp)){ temp /= 10; continue;}
		sprime(cur + 1, temp);
		temp /= 10;
	}
}
int main()
{
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	
	scanf("%d", &n); ll head[] = {2, 3, 5, 7, 0};
	//cout<<is_prime(2333)<<is_prime(233);
	for(int i = 0; head[i]; i++){
		sprime(1, head[i]);
	} 
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
