#include <stdlib.h>
#include <stdio.h>
int main(void) {
	int i,j;
	unsigned long long k = 0;
	unsigned long long **m, **mt;
	while (1) {
		// allocate matrix m
		m = malloc(1000 * sizeof(unsigned long long*));
		if (!m) { return -1; }
		for (i = 0; i < 1000; i++) {
			m[i] = malloc(1000 * sizeof(unsigned long long));
			if (!m[i]) { return -1; }
		}

		// allocate matrix mt
		mt = malloc(1000 * sizeof(unsigned long long*));
		if (!mt) { return -1; }
		for (i = 0; i < 1000; i++) {
			mt[i] = malloc(1000 * sizeof(unsigned long long));
			if (!mt[i]) { return -1; }
		}

		// fill matrix m with values
		for (i = 0; i < 1000; i++) {
			for (j = 0; j < 1000; j++) {
				m[i][j] = 1000 * i + j;
			}
		}

		// transpose matrix m, write to mt
		for (i = 0; i < 1000; i++) {
			for (j = 0; j < 1000; j++) {
				mt[i][j] = m[j][i];
			}
		}

		// free matrices m and mt
		for (i = 0; i < 1000; i++) {
    		free(m[i]);
    		free(mt[i]);
		}
		free(m);
		free(mt);
		k++;
		printf("Finished cycle: %lld\n", k);
	}
	return 0;
}
