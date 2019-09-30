#include <stdio.h>
#include <string.h>

long long int ton(char* buf){
	long long int s = 0;
	while(*buf != '\0'){
		s = s*10 + *buf - '0';
		buf++;
	}
	return s;
}

int len(char* buf){
	int l = 0;
	while(*buf++ != '\0') l++;
	return l;
}

void rev(char* buf){
	int l = len(buf);
	int i = l-1;
	char c;
	//printf(" (rev:%s",buf);
	while(buf[l-1] == '0') l--;
	for(i=0;i<l/2;i++){
		c = buf[i];
		buf[i] = buf[l-i-1];
		buf[l-i-1] = c;
	}
	//printf("->%s) ",buf);
}

int proc(char* buf){
	int l = len(buf);
	int s = 0, c = 0;
	int i;
	//printf (" ( p:%s ) ",buf);
	if(l == 1 && buf[0] == '0') return 0;
	for(i=l/2-1;i>=0;i--){
		c = c*10+buf[i]-'0';
	}

	for(i=l/2;i<l;i++){
		s = s*10+buf[i]-'0';
		buf[i] = '0';
	}
	//printf(" (c:%d s:%d) ",c,s);

	if(c == 1){
		for(i=0;i<l-1;i++){ buf[i] = '9'; }
		buf[l-1] = '\0';
		return s+1;
	}
	if(s == 0){
		sprintf(buf,"%lld",ton(buf)-1);
		return 1;
	}
	if(c!=0){
		buf[l-1] = '1';
		rev(buf);
	}
	return s;
}
	
int main(){
	int i,T;
	char buf[16];
	int s, c;

	scanf("%d",&T);
	for(i=0;i<T;i++){
		s = 0;
		scanf("%s",buf);
		while(1){
			//printf("%s", buf);
			c=proc(buf);
			if(c==0) break;
			s += c;
			//printf(" -> %s (%d) ", buf, c);
		}
		//printf(" => %d\n",s);
		printf("Case #%d: %d\n",i+1,s);
	}
	return 0;
}
