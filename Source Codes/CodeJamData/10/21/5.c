#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doTestCase();

int main(){
	int i,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		printf("Case #%d: ",i);
		doTestCase();
	}
	return 0;
}

#define MAXSIZE 110

char * parent(char * path, char * buf);

void doTestCase(){
	int n,m,i,j,c=0;
	scanf("%d %d",&n,&m);
	char * arrEx[n];
	char * arrNew[m];
	char *buf=(char *) malloc(sizeof(char)*MAXSIZE);
	char *buf2=(char *) malloc(sizeof(char)*MAXSIZE);
	char *p=(char *) malloc(sizeof(char)*MAXSIZE);
	char *t;
	
	for (i=0;i<n;i++){
		arrEx[i]=(char *) malloc(sizeof(char)*MAXSIZE);
		scanf("%s",arrEx[i]);
	}
	
	for (i=0;i<m;i++){
		arrNew[i]=(char *) malloc(sizeof(char)*MAXSIZE);
		scanf("%s",arrNew[i]);
	}
	
	for (i=0;i<m;i++){
		strcpy(p,arrNew[i]);
		while(p[1]!=0){
			for (j=0;j<n;j++){
				if (strcmp(p,arrEx[j])==0)
					break;
			}
			if (j!=n)
				break;
		
			for (j=0;j<i;j++){
				strcpy(buf,arrNew[j]);
				while (buf[1]!=0){
					if (strcmp(buf,p)==0){
						break;
					}
					else{
						parent(buf,buf2);
						t=buf2;
						buf2=buf;
						buf=t;
					}
				}
				
				if (buf[1]!=0)
					break;
			}
			
			if (i==j){
				//printf("'%s'\n",p);
				//printf("%d ",p[strlen(p)-1]);
				c++;
				parent(p,buf2);
				t=buf2;
				buf2=p;
				p=t;
				//printf("%s\n",p);
			}
			else
				break;
		}
	}
	printf("%d\n",c);	
}
		
	
	
char * parent(char * path, char * buf){
	int i,e=0;
	buf[0]=path[0];
	for (i=1;path[i]!='\0';i++){
		if (path[i]=='/') 
			e=i;
		buf[i]=path[i];
	}
	if (e==0) 
		e++;
	buf[e]='\0';
	return buf;
}

