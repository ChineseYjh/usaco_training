/*
ID: chinese21
LANG: C++
TASK: beads
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	int n;
	char beads[360];
	scanf("%d%s", &n, beads);
	int ans = 0;
	for(int pos = 0; pos < n; pos++) {
		//left
		int temp = 0;
		char col = beads[pos];
		int ptr = pos;
		if(col != 'w') {
			do{
				if(beads[ptr] == col || beads[ptr] == 'w') temp++;
				else break;
				ptr = (ptr + 1) % n;
			}while(ptr != pos);
		}
		else{
			int _ptr = ptr;
			do{
				if(beads[ptr] == 'r' || beads[ptr] == 'w') temp++;
				else break;
				ptr = (ptr + 1) % n;
			}while(ptr != pos);
			int ttemp = 0;
			do{
				if(beads[_ptr] == 'b' || beads[_ptr] == 'w') ttemp++;
				else break;
				_ptr = (_ptr + 1) % n;
			}while(_ptr != pos);
			temp = max(ttemp, temp);
			temp == ttemp ? ptr = _ptr : 1;
		}
		//right
		if(ptr == pos) {	printf("%d\n", n); exit(0);	}
		int temp2 = 0;
		col = beads[(pos + n - 1) % n];
		int ptr2 = (pos + n - 1) % n;
		if(col != 'w') {
			for(; ptr2 != (ptr + n - 1) % n; ptr2 = (ptr2 + n - 1) % n) {
				if(beads[ptr2] == col || beads[ptr2] == 'w') temp++;
				else break;
			}
		}
		else{
			int _ptr = ptr2;
			for(; ptr2 != pos; ptr2 = (ptr2 + 1) % n) {
				if(beads[ptr2] == 'r' || beads[ptr2] == 'w') temp++;
				else break;
			}
			int ttemp = 0;
			for(; _ptr != pos; _ptr = (_ptr + 1) % n) {
				if(beads[_ptr] == 'b' || beads[_ptr] == 'w') ttemp++;
				else break;
			}
			temp2 = max(ttemp, temp2);
			temp2 == ttemp ? ptr2 = _ptr : 1;
		}
		temp += temp2;
		if(temp > ans) ans = temp;
	}
	printf("%d\n", ans);
	return 0;
}
