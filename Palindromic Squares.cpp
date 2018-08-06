/*
ID: chinese21
LANG: C++
TASK: palsquare
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int toB(int n, int B, char *arr){
	int len = 0;
	char buf[20];
	while(n){
		int x = n % B;
		char w = (x < 10 ? char(x + '0') : char('A' + x - 10)); 
		buf[len++] = w;
		n /= B;
	}
	for(int i = 0; i < len; i++) arr[i] = buf[len - 1 - i];
	return len;
}
bool judge(char *arr, int len){
	for(int i = 0; i < len; i++) if(arr[i] != arr[len - 1 - i]) return false;
	return true;
}
int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	
	int B; scanf("%d", &B);
	for(int i = 1; i <= 300; i++){
		char sq[20];
		memset(sq, 0, sizeof(sq));
		int len = toB(i * i, B, sq);
		if(judge(sq, len)){
			char ori[20];
			memset(ori, 0 ,sizeof(ori));
			toB(i, B, ori);
			printf("%s %s\n", ori, sq);
		}
	}
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
