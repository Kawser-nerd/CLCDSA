// Using libUtil from libGlov (Graphics Library of Victory) available at http://bigscreensmallgames.com/libGlov
#include "utils.h"
#include "file.h"
#include "strutil.h"
#include "assert.h"
#include "array.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

extern char *doA(char **&toks);
extern char *doB(char **&toks);
extern char *doC(char **&toks);
extern char *doD(char **&toks);
extern char *doE(char **&toks);

typedef char *(*Solver)(char **&toks);

void myfprintf(FILE *f, const char *fmt, ...)
{
	va_list va;
	char buf[16384];

	va_start(va, fmt);
	Vsprintf(buf, fmt, va);
	va_end(va);

	printf("%s", buf);
	fprintf(f, "%s", buf);
}

#define fprintf myfprintf


void doProblem(char *filename, Solver s, char *delims)
{
	char outname[MAX_PATH];
	sprintf(outname, "%s.out", filename);
	FILE *fout = fopen(outname, "w");
	char *data = fload(filename, "rb", NULL);
	char **toks=NULL;
	tokenizeStringAlloc(data, delims, &toks);
	int N = atoi(toks[0]);
	char **curtoks = &toks[1];
	for (int i=0; i<N; i++) {
		fprintf(fout, "Case #%d: %s\n", i+1, s(curtoks));
	}
	assert(curtoks == &toks[arrayGetSize(&toks)]);
	fclose(fout);
}


int main(int argc, char *argv[])
{
	//doProblem("A-small.in", doA, " \t\n\r");
	doProblem("A-large.in", doA, " \t\n\r");
	//doProblem("B-small-test.in", doB, " \t\n\r");
	//doProblem("B-small.in", doB, " \t\n\r");
	//doProblem("B-large.in", doB, " \t\n\r");
	//doProblem("C-small.in", doC, " \t\n\r");
	//doProblem("C-large.in", doC, " \t\n\r");
	_getch();
	return 0;
}