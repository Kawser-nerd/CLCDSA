#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	LMAX	20


long long sol;


void reset()
{
    sol = 0;
}

long long nr_test(long long nr)
{
    if (!(nr % 2) || !(nr % 3) || !(nr % 5) || !(nr % 7))
	return 1;
    
    return 0;
}

long long ugly_test(long long backsum, long long nr)
{
    long long ugly = 0;
	
    ugly += nr_test(backsum + nr);
    ugly += nr_test(backsum - nr);
    
    return ugly;
}

long long str2nr(char *str, int len)
{
    long long nr;
    char *tstr = malloc(len + 1);
    
    //printf("str2nr-str: '%s'\n", str);
    //printf("str2nr-len: %d\n", len);
    strncpy(tstr, str, len);
    tstr[len] = 0;
    //printf("str2nr-tstr: '%s'\n", tstr);
    
    sscanf(tstr, "%lld", &nr);
    free(tstr);
    //printf("str2nr-nr: '%lld'\n", nr);
    return nr;
}

long long counter(char *str, long long backsum, int lleft, int is_first)
{
    long long ugly = 0;
    long long cur_value;
    int i;
    //printf("%s\n", str);
    //long long nr = str2nr(str, lleft);
    ugly += ugly_test(backsum, str2nr(str, lleft));
    if (is_first) ugly /= 2;

    for (i = 1; i < lleft; i++) {
	cur_value = str2nr(str, i);
	
	ugly += counter(str + i, backsum + cur_value, lleft - i, 0);
	if (!is_first)
	    ugly += counter(str + i, backsum - cur_value, lleft - i, 0);
    }
    
    //for (i = 0; i < lleft; i++) printf(" ");
    //printf("str: %s - back: %lld - ugly: %lld\n", str, backsum, ugly);
    
    return ugly;
}


int main(int argc, char **argv)
{
    int tc, ti;
    char *buff = malloc(LMAX);
    
    scanf("%d", &tc);
    fgets(buff, LMAX - 1, stdin);
    for (ti = 0; ti < tc; ti++) {
	reset();
	
	fgets(buff, LMAX - 1, stdin);
	if (buff[strlen(buff) - 1] == '\n')
	    buff[strlen(buff) - 1] = 0;
	//printf("'%s'\n", buff);
	//printf("start\n");
	sol = counter(buff, 0, strlen(buff), 1);
	
	printf("Case #%d: %lld\n", ti + 1, sol);
    }

    return 0;
}
