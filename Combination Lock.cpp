/*
ID: chinese21
LANG: C++
TASK: combo
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int pwd1[3], pwd2[3], in[3];
int n;
bool check(int *pwd){//len == 3
	return min(abs(pwd[0] - in[0]), n - abs(pwd[0] - in[0])) <= 2 && min(abs(pwd[1] - in[1]), n - abs(pwd[1] - in[1])) <= 2 && min(abs(pwd[2] - in[2]), n - abs(pwd[2] - in[2])) <= 2;
}
int main()
{
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	
	scanf("%d", &n); for(int i = 0; i < 3; i++) scanf("%d", pwd1 + i); for(int i = 0; i < 3; i++) scanf("%d", pwd2 + i);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		in[0] = i;
		for(int j = 1; j <= n; j++){
			in[1] = j;
			for(int k = 1; k <= n; k++){
				in[2] = k;
				if(check(pwd1) || check(pwd2)) cnt++;
			}
		}
	}printf("%d\n", cnt);
	
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
