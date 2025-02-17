#include <bits/stdc++.h>
using namespace std;

bool allgood(int power, vector<vector<int>> &cows) {
	int start = 0;
	queue<int> frontier;
	frontier.push(start);
	vector<int> visited(cows.size());
	visited[start] = 1;
	while(!frontier.empty()) {
		int curr = frontier.front();
		frontier.pop();
		for (int c = 0; c < cows.size(); c++) {
			int dx = cows[curr][0] - cows[c][0];
			int dy = cows[curr][1] - cows[c][1];
			int dsquared = dx * dx + dy * dy;
			if (!visited[c] && dsquared <= power) {
				frontier.push(c);
				visited[c] = 1;
			}
		}
	}
	for (int elem : visited) {
		if (elem == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int N;
	cin >> N;
	vector<vector<int>> cows(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		cin >> cows[i][0] >> cows[i][1];
	}
	int hi = INT_MAX;
	int lo = 0;
	int valid = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (allgood(mid, cows)) {
			valid = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << valid;
}
