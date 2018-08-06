/*
ID: chinese21
LANG: C++
TASK: transform
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char m[11][11];
char temp[11][11];
char ttemp[11][11];
char _m[11][11];

void r90(char m[][11], char temp[][11], int n){
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) temp[j][n - i + 1] = m[i][j];
}
void r180(char m[][11], char temp[][11], int n){
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) temp[n - i + 1][n - j + 1] = m[i][j];
}
void r270(char m[][11], char temp[][11], int n){
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) temp[n - j + 1][i] = m[i][j];
}
void mir(char m[][11], char temp[][11], int n){
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) temp[i][n - j + 1] = m[i][j];
}
bool same(char m[][11], char temp[][11], int n){
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(temp[i][j] != m[i][j]) return false;
	return true;
}
int main() {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)  for(int j = 1; j <= n; j++) cin >> m[i][j];
	for(int i = 1; i <= n; i++)  for(int j = 1; j <= n; j++) cin >> _m[i][j];
	r90(m, temp, n); if(same(_m, temp, n)) {puts("1"); exit(0); }
	r180(m, temp, n); if(same(_m, temp, n)) {puts("2"); exit(0); }
	r270(m, temp, n); if(same(_m, temp, n)) {puts("3"); exit(0); }
	mir(m, temp, n); if(same(_m, temp, n)) {puts("4"); exit(0); }
	mir(m, temp, n); r90(temp, ttemp, n); if(same(ttemp, _m, n)) {puts("5"); exit(0); }
	mir(m, temp, n); r180(temp, ttemp, n); if(same(ttemp, _m, n)) {puts("5"); exit(0); }
	mir(m, temp, n); r270(temp, ttemp, n); if(same(ttemp, _m, n)) {puts("5"); exit(0); }
	if(same(m, _m, n)){puts("6"); exit(0); }
	puts("7");
	return 0;
}
