#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define N 1000
using namespace std;
vector <int> v[N];
vector <int> jin;
int dp[N][2];
int rec(int dad, int child, int status) {
	if (dp[child][status] != -1) return dp[child][status];

	bool is_leaf = 1;
	int ret = 0;

	for (int i = 0; i < v[child].size(); i++) {
		int u = v[child][i];
		if (u == dad) continue;

		is_leaf = 0;
		ret += (status==1?
			(rec(child, u, 0)) :
			(max(rec(child, u, 0), rec(child, u, 1)))
		);
	}
	ret += status==1?jin[child]:0;
	if (is_leaf) {
		dp[child][0] = 0;
		dp[child][1] = jin[child];
		return dp[child][status];
	}
	return dp[child][status] = ret;
}

int main(int argc, char *argv[]) {
	memset(dp, -1, sizeof dp);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		jin.push_back(k);
	}
	for (int i = 1; i < n; i++) {
		int HOST, A;
		scanf("%d%d", &HOST, &A);
		//A zuvhun 0 baina
		v[HOST].push_back(i);
		v[i].push_back(HOST);
	}
	printf("%d\n", max(rec(-1, 0, 0), rec(-1, 0, 1)));
	return 0;
}
