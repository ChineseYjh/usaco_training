/*
ID: chinese21
LANG: C++
TASK: wormhole
*/
//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int n, cnt;
struct pos
{
	int x, y; int id;
}poses[14], buf[14];
bool v[14];
bool sim(){
	int visited[14];
	for(int i = 0; i < n; i++){//start: buf[i]
		memset(visited, 0, sizeof(visited)); visited[i] = true;
		int ptr = i;
		for(;;){
			//find the exit
			ptr % 2 ? ptr-- : ptr++;
			//find the entrance
			int flag = -1;
			for(int i = 0, dis = INF; i < n; i++){
				if(buf[i].y == buf[ptr].y && buf[i].x > buf[ptr].x && buf[i].x - buf[ptr].x < dis){
					dis = buf[i].x - buf[ptr].x; flag = i;
				}
			}if(flag == -1)break;
			if(visited[flag]) return true;
			ptr = flag;
		}
	}return false;
}
void pairs(int cur, int len){
	if(cur == len){
		if(sim()){
			cnt++;
			//for(int i = 0; i < len; i++) printf("%d ", buf[i].id); puts("");
		}//for(int i = 0; i < len; i++) printf("%d ", buf[i].id); puts("");
		return;
	}int i = 0;
	for(; i < len; i++) if(v[i] == false) {buf[cur++] = poses[i], v[i] = true; break;}
	for(int j = i + 1; j < len; j++){
		if(v[j] == false){
			buf[cur++] = poses[j], v[j] = true;
			pairs(cur, len);
			v[j] = false;cur--;
		}
	}v[i] = false;
}
int main()
{
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	scanf("%d", &n); for(int i = 0; i < n; i++) scanf("%d%d", &poses[i].x, &poses[i].y);
	//for(int i = 0; i < n; i++)poses[i].id = i + 1;
	pairs(0, n);
	printf("%d\n", cnt);
	//printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
