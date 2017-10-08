#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <deque>
#include <stack>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
int N;
stack<int> st;
long long result = INT64_MIN;
int main() {
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < N; i++) {
		int now = v[i];
		long long wid = 0;
		long long high = 0;
		while (!st.empty() && now < v[st.top()]) {
			high = v[st.top()];//개빡
			st.pop();
			if (!st.empty()) {
				wid = i - st.top() - 1;
			}
			else {
				wid = i;
			}
			result = max(result, wid*high);
		}
		st.push(i);
	}
	while (!st.empty()) {
		long long high = v[st.top()];//개빡
		long long wid;
		st.pop();
		if (!st.empty()) {
			wid = N - st.top() - 1;
		}
		else {
			wid = N;
		}
		result = max(result, wid*high);
	}
	cout << result << endl;
	return 0;
}