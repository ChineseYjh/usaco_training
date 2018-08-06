/*
ID: chinese21
LANG: C++
TASK: friday
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 7;
int mon[13] = {0, 31, 28, 31, 30,31,30,31,31,30,31,30,31};
bool is_run(int year){
	if((year % 100 == 0 && year % 400 == 0 )||(year % 100 != 0 && year % 4 == 0)){
		mon[2] = 29; return true;
	}
	else{
		mon[2] = 28; return false;
	}
}
int ans[8];
int main()
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	
	int n; scanf("%d", &n);
	int day = 3;//1899.12.13
	for(int i = 0; i < n; i++){
		is_run(1900 + i);
		day = (day + mon[12]) % mod;
		if(day == 0) day = 7;
		ans[day]++;
		for(int m = 2; m <= 12; m++){
			day = (day + mon[m - 1]) % mod;
			if(day == 0) day = 7;
			ans[day]++;
		}
	}
	printf("%d %d", ans[6], ans[7]);
	for(int i = 1; i <= 5; i++) printf(" %d", ans[i]);
	putchar('\n');
	return 0;
}
