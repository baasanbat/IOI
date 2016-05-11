#include <stdio.h>
int main() {
	int n, ret=-1;
	scanf("%d", &n);
	int i; for (i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		ret = k>ret?k:ret;
	}
	printf("%d\n", ret);
	return 0;
}
