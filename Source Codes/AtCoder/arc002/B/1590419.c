#include <stdio.h>
#include <stdbool.h>

void Calc(int *y, int *m, int *d);
void Inc(int *y, int *m, int *d);
bool MonthEnd(int *y, int *m, int *d);
bool Uru(int y);

int main (){
	int y, m, d;
	int *py, *pm, *pd;
	while(1){
		if(scanf("%d/%d/%d", &y, &m, &d) != 3){
			scanf("%*s", &y, &m, &d);
			printf("??/??/???????????.\n");
		}else
			break;	
	}

	py = &y;
	pm = &m;
	pd = &d;

	Calc(py, pm, pd);

	printf("%d/%02d/%02d\n", y, m, d);

	return 0;
}

void Calc(int *y, int *m, int *d){

	while(1){
		if( *y % (*m * (*d)) == 0)
			return;
		else
			Inc(y, m, d);
	}
}


void Inc(int *y, int *m, int *d){
	if((*m) == 12 && (*d) == 31){
		(*y)++;
		*m = 1;
		*d = 1;
	}
	else if(MonthEnd(y, m, d)){
		(*m)++;
		*d = 1;
	}
	else
		(*d)++;


	return;
}

bool MonthEnd(int *y, int *m, int *d){
	bool end = false;

	if((*m) == 4 || (*m) == 6 || (*m) == 9 || (*m) == 11){
		if(*d == 30)
			end = true;
	} else if ((*m) == 2){
		if((*d) == 28 && Uru(*y)){
		}
		else if((*d) == 29 || (*d) == 28)
			end = true;
	} else if((*d) == 31)
		end = true;

	return end;
}

bool Uru(int y){
	bool uru = false;

	if(y % 400 == 0){
		uru = true;
	}else if(y % 100 == 0){
	}else if(y % 4 == 0){
		uru = true;
	}

	return uru;
} ./Main.c: In function ‘main’:
./Main.c:14:10: warning: too many arguments for format [-Wformat-extra-args]
    scanf("%*s", &y, &m, &d);
          ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%*s", &y, &m, &d);
    ^