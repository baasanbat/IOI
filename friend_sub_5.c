#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1002
int v[N][N]; //graph
char used[N]; //dfs
char color[N]; //bipartite
int vv[N][N];

int dfs(int source, int target, int n) {
	if (source == target) return 1;
	
	used[source] = 1;
	int ret = -1;
	int i; for (i = 0; i < n; i++) {
		if (v[source][i]==1 && used[i]!=1) {
			ret = dfs(i, target, n);
			if (ret != -1) {
				v[source][i]--;
				v[i][source]++;
				return ret;
			}
		}
	}
	return ret;
}

int ford_fulkerson(int source, int target, int n) {
	int flow = 0;
	memset(used, 0, sizeof used);
	while (dfs(source, target, n) == 1) {
		memset(used, 0, sizeof used);
		flow++;
	}
	return flow;
}

void color_graph(int c, int k, int n) {
	color[k] = c;
	int i; for (i = 1; i <= n; i++) {
		if (color[i]==-1 && vv[k][i])
			color_graph(c==0?1:0, i, n);
	}
}

int main(int argc, char *argv[]) {
	//freopen("05-021.in", "r", stdin);
	int n; scanf("%d", &n);
	int i; for (i = 0; i < n; i++) { int k; scanf("%d", &k); }
	for (i = 2; i <= n; i++) {
		int HOST, A; scanf("%d%d", &HOST, &A); HOST++;
		if (!A) {
			vv[HOST][i] = vv[i][HOST] = 1;
		} else {
			int j; for (j = 1; j <= n; j++) 
				if (vv[HOST][j])
					vv[j][i] = vv[i][j] = 1;
		}
	}
/*	
	for (i = 1; i <= n; i++) {
		int j; for (j = 1; j <= n; j++)
			printf("%d ", vv[i][j]);
		printf("\n");
	}
*/	
	memset(color, -1, sizeof color);
	memset(v, 0, sizeof v);
	for (i = 1; i <= n; i++)
		if (color[i] == -1)
			color_graph(0, i, n);
	//for (i = 1; i <= n; i++) printf("%d ", color[i]);
	//printf("\n");
	for (i = 1; i <= n; i++)
		if (!color[i]) {
			v[0][i] = 1;
			int j; for (j = 1; j <= n; j++)
				if (color[j] && vv[i][j]) {
					v[i][j] = 1;
					v[j][n+1] = 1;
				}
		}
/*	
	for (i = 0; i <= n+1; i++) {
		int j; for (j = 0; j <= n+1; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
*/	
	printf("%d\n", n-ford_fulkerson(0, n+1, n+2));
	return 0;
}
