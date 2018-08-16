/*
ID: chinese21
LANG: C++
TASK: preface
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

const string num[4][10]={{"","I","II","III","IV","V","VI","VII","VIII","IX"},  //个位
{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},//十位
{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},//百位
{"","M","MM","MMM"}};//千位
char code[8] = {'\0','I','V','X','L','C','D','M'};
int ans[30];//string[i]->ans
void decode(int n){//n->string
	string str(""); int t; for(int i = 3; i >= 0; i--) if((t = n / (int)pow(10, i) % 10)) str += num[i][t];
	for(string::iterator it = str.begin(); it != str.end(); it++) ans[*it - 'A']++;
}
int main()
{
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) decode(i);
	int t; for(int i = 1; i <= 7; i++) if((t = ans[code[i] - 'A']))printf("%c %d\n", code[i], t);
	
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
