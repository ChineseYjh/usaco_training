/*
ID: chinese21
LANG: C++
TASK: crypt1
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, table[11];
bool check(int a){
	for(; a; a /= 10) if(!table[a % 10]) return false;
	return true;
}
int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	int temp;
	scanf("%d", &n); for(int i = 0; i < n; i++){ scanf("%d", &temp); table[temp] = 1;}
	int cnt = 0;
	for(int i = 111; i <= 999; i++){
		if(!check(i)) continue;
		for(int j = 11; j <= 99; j++){
			if(!check(j)) continue;
			int a = i * (j % 10); if(a / 1000 || !check(a)) continue;
			int b = i * (j / 10); if(b / 1000 || !check(b)) continue;
			a = a + 10 * b; if(!check(a)) continue;
			cnt++; //printf("%d %d\n", i, j);
		}
	}printf("%d\n", cnt);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
