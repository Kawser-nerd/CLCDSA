#include <stdio.h>

void next_mntyr(int *y, int *m, int *d){
	if(*m == 12){
		(*y)++;
		*m = 1;
		*d = 1;
	}else{
		(*m)++;
		*d = 1;
	}
return;
}

void tomorrow(int *y, int *m, int *d){
	if(*d <= 27){
		 (*d)++;
		 return;
	}

	int uruu = (*m==2 && (*y%400==0 || (*y%4==0 && *y%100!=0))) ? 1 : 0;
	
	switch(*d){
	case 28:
		if(uruu){
			(*d)++;
			return;
		}else if(*m==2){
			next_mntyr(y, m, d);
			return;
		}else{
			(*d)++;
			return;
		}

	case 29:
		if(uruu){
			next_mntyr(y, m, d);
			return;
		}else{
			(*d)++;
			return;
		}

	case 30:
		if(*m==4 || *m==6 || *m==9 || *m==11){
			next_mntyr(y, m, d);
			return;
		}else{
			(*d)++;
			return;
		}

	case 31:
		next_mntyr(y, m, d);
		return;
	}	
}


int main(){
	int Y, M, D;
	scanf("%d/%d/%d", &Y, &M, &D);

	while(Y%(M*D)){
		tomorrow(&Y, &M, &D);
	}

	printf("%04d/%02d/%02d\n", Y, M, D);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:63:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d/%d/%d", &Y, &M, &D);
  ^