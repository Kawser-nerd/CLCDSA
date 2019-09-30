#include <stdio.h>
#include <string.h>

int ti, tn, i;
char str[10000], out[10000], outa[10000], outb[10000];

int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		fscanf(stdin, "%s", str);
		for (i = 0; str[i]; ++i) {
			strncpy(outa, out, i);
			outa[i] = str[i];
			outa[i + 1] = 0;
			strncpy(outb + 1, out, i);
			outb[0] = str[i];
			outb[i + 1] = 0;
			if (strcmp(outa, outb) >= 0) {
				strcpy(out, outa);
			} else {
				strcpy(out, outb);
			}
		}
		fprintf(stdout, "%s\n", out);
	}
}

