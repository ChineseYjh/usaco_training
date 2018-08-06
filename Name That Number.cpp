/*
ID: chinese21
LANG: C++
TASK: namenum
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//牛编号 
char num[13];
//牛名字 
char name[13];
//数字->编号 
char Map[10][3] = {{},{},{'A', 'B', 'C'}, {'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
//编号->数字 
int Map2[27] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9};
//按名字第一个字母对应的数字分类的合法名字字典 
string dict[10][5010];
//按名字第一个字母对应数字分类的合法名字的个数 
int dict_num[10];
bool Find(int cur, int len){
	if(cur == len){
		bool flag = false;
		int y = Map2[name[0] - 'A'];
		int x = dict_num[y];
		for(int s = 0; s < x; s++){
			if(dict[y][s].length() != len) continue;
			int i;
			for(i = 0; i < len; i++) if(name[i] != (dict[y][s].c_str())[i])break;
			if(i == len) { flag = true; puts(name);}
		}
		if(flag) return true; else return false;
	}
	else{
		int x = num[cur] - '0';
		bool flag = false;
		for(int i = 0; i < 3; i++){
			name[cur] = Map[x][i];
			if(Find(cur + 1, len)) flag = true;
		}
		return flag;
	}
}

int main() {
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	
	scanf("%s", num);
	int len = strlen(num);
	//freopen("in.txt", "r", stdin);
	freopen("dict.txt", "r", stdin);
	string temp;
	while(cin >> temp){
		dict[Map2[temp[0] - 'A']][dict_num[Map2[temp[0] - 'A']]++] = temp;
	}
	if(!Find(0, len)) puts("NONE");
	return 0;
}
