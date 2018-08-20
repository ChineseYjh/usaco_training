/*
ID: chinese21
LANG: C++
TASK: lamps
*/
//@author: ChineseYjh
//#include<bits/stdc++.h>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int TP = 16;

int n, c;
string status[20];//TP
int ptr;
bool is_on[6];//is_pressed
int on[101], off[101], pon, poff;
void fill_status(int cur) {
	if (cur <= 4) {
		is_on[cur] = false; fill_status(cur + 1);
		is_on[cur] = true; fill_status(cur + 1);
		return;
	}
	string temp = "0"; for (int i = 0; i < n; i++) temp += "1";
	if (is_on[1]) for (int i = 1; i <= n; i++) temp[i] = !(temp[i] - '0') + '0';
	if (is_on[2]) for (int i = 1; i <= n; i += 2) temp[i] = !(temp[i] - '0') + '0';
	if (is_on[3]) for (int i = 2; i <= n; i += 2) temp[i] = !(temp[i] - '0') + '0';
	if (is_on[4]) for (int i = 1; i <= n; i += 3) temp[i] = !(temp[i] - '0') + '0';
	temp[0] = is_on[1] + is_on[2] + is_on[3] + is_on[4] + '0';
	status[++ptr] = temp;
}
bool cmp(const string& a, const string& b) {
	int i = 1; for (; i <= n && a[i] == b[i]; i++);
	if (i == n + 1) return false;
	return a[i] < b[i];
}
bool pred(const string& a, const string& b) {
	if(a == "" || b == "") return false;
	int i = 1; for (; i <= n && a[i] == b[i]; i++);
	return i == n + 1;
}
bool is_possible(const string& s) {
	if (c < s[0] - '0' || (c - s[0] + '0') % 2) return false;
	for (int i = 1; i <= pon; i++) if (s[on[i]] == '0') return false;
	for (int i = 1; i <= poff; i++) if (s[off[i]] == '1') return false;
	return true;
}
int main()
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	//input
	scanf("%d", &n);
	fill_status(1);
	sort(status + 1, status + TP + 1, cmp);
	//for (int i = 1; i < TP; i++) if (pred(status[i], status[i + 1])) status[i + 1][0] = status[i][0] = 'x';
	//TP = unique(status + 1, status + TP + 1, pred) - status - 1;
	scanf("%d", &c);
	int temp;
	while (scanf("%d", &temp) && temp != -1) on[++pon] = temp;
	while (scanf("%d", &temp) && temp != -1) off[++poff] = temp;
	//output
	bool flag = false;
	string ref("");
	for (int i = 1; i <= TP; i++) {
		if (is_possible(status[i]) && !pred(status[i], ref)) {
			ref = status[i];
			flag = true;
			for (int j = 1; j <= n; j++) printf("%c", status[i][j]);
			putchar('\n');
		}
	}if (!flag) puts("IMPOSSIBLE");
	//system("pause");
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
