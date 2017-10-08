#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
int N;
double DP[1 << 17];
int task[17][17];//i번째 사람이 j번째 일
struct dat {
	int now_index;
	int task_state;
	double now;
};
int main() {
	int T;
	cin >> T;
	for(int t=1;t<=T;t++) {
		//초기화 필요
		
		for (int i = 0; i < 17; i++) {
			for (int j = 0; j < 17; j++) {
				task[i][j] = 0;
			}
		}
		for (int i = 0; i < (1 << 17); i++) {
			DP[i] = 0.0;
		}
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &task[i][j]);
			}
		}
		//go
		queue<dat> q;
		q.push({1,0,1.0});
		int full = (1 << N+1) - 2;
		double max_result = 0.0;
		while (!q.empty()) {
			int now_index = q.front().now_index;
		    int state = q.front().task_state;
			double now = q.front().now;
			q.pop();
			if (state == full) {
				max_result = max(max_result, now);
				continue;
			}
			if (DP[state] <= now) {
				for (int i = 1; i <= N; i++) {
					if (!(state&(1 << i))) {
						q.push({ now_index + 1,state | (1 << i),((double)task[now_index][i] / 100)*now });
						DP[state | (1 << i)] = max(DP[state | (1 << i)], ((double)task[now_index][i] / 100)*now);
					}
				}
			}
		}
		cout << setprecision(6) << fixed;
		cout <<"#"<<t<<" "<< max_result*100 << endl;
	}


	return 0;
}
