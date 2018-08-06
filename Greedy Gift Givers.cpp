/*
ID: chinese21
LANG: C++
TASK: gift1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, int>ac;
string names[12];
int main()
{
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int num; scanf("%d", &num);
	string temp;
	for(int i = 1; i <= num; i++){
		cin>>temp; ac[temp] = 0;
		names[i] = temp;
	}
	int m, p;
	while(cin >> temp){
		scanf("%d%d", &m, &p);
		if(p == 0) continue;
		string name;
		for(int i = 1; i <= p; i++){
			cin >> name; ac[name]+=m / p;
		}
		ac[temp] = ac[temp]-m+m%p;
	}
	for(int i = 1; i <= num; i++){
		printf("%s %d\n", names[i].c_str(), ac[names[i]]);
	}
	return 0;
}
