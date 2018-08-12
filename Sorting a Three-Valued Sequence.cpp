/*
ID: chinese21
LANG: C++
TASK: sort3
*/
//@author: ChineseYjh
//#include<bits/stdc++.h>
#include<cstdio>
#include<set>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

set<int>bkt[4];
int arr[1010], n;
int cnt;

void solve(int start, int num, int v) {//[start, start + num) should all be v finally
	for (set<int>::iterator it = bkt[v].begin(); it != bkt[v].end(); it++) {
		if (*it < start + num) continue;
		int temp = INF, index = -1; 
		for (int i = start; i < start + num; i++) 
			if (arr[i] > v && arr[i] < temp) 
				temp = arr[i], index = i;
		set<int>::iterator t = bkt[temp].begin(); 
		for (; *t != index; t++); 
		bkt[temp].erase(t); 
		bkt[temp].insert(*it);//update bkt[temp] and its sequence
		swap(arr[index], arr[*it]); cnt++;//update arr
	}
}
int main()
{
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i), bkt[arr[i]].insert(i);
	solve(0, bkt[1].size(), 1);
	solve(bkt[1].size(), bkt[2].size(), 2);
	printf("%d\n", cnt);

	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
