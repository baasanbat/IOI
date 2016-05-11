#include <stdio.h>
int main() {
	int n, ret=0;
	scanf("%d", &n);
	int i; for (i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		ret += k;
	}
	printf("%d\n", ret);
	return 0;
}
