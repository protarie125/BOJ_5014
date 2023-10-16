#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int f, s, g, u, d;
vb isVisited;
int solve() {
	isVisited = vb(f + 1, false);
	isVisited[s] = true;

	auto q = queue<pii>{};
	q.push({ s, 0 });

	while (!q.empty()) {
		auto [now, ct] = q.front();
		q.pop();

		if (now == g) {
			return ct;
		}

		if (now + u <= f && !isVisited[now + u]) {
			isVisited[now + u] = true;
			q.push({ now + u, ct + 1 });
		}

		if (1 <= now - d && !isVisited[now - d]) {
			isVisited[now - d] = true;
			q.push({ now - d, ct + 1 });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> f >> s >> g >> u >> d;
	auto ans = solve();

	if (-1 == ans) {
		cout << "use the stairs";
		return 0;
	}

	cout << ans;

	return 0;
}