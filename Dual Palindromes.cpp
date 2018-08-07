/*
ID: chinese21
LANG: C++
TASK: dualpal
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char arr[35];
int toB(int n, int B){//2 <= B <= 10
	int len = 0;
	while(n){
		arr[len++] = n % B - '0'; n /= B;
	}return len;
}
bool par(int len){
	for(int i = 0; i <= len / 2; i++) if(arr[i] != arr[len - 1 - i]) return false;
	return true;
}
int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	int n, s; scanf("%d%d", &n, &s);
	for(int i = s + 1; n; i++){
		int B = 2; int cnt = 1;
		for(; B <= 10; B++){
			int len = toB(i, B);
			if(par(len) && !cnt) break;
			if(par(len)) cnt--;
		}
		if(B < 11){
			printf("%d\n", i); n--;
		}
	}
	
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
