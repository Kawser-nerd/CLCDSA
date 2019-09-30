#include <stdio.h>
#include <string.h>

int main(){
	int T;
	fscanf(stdin,"%d",&T);
	
	for(int t=1;t<=T;t++){
		char buf[21];
		fscanf(stdin,"%s\n",buf);
		int len=strlen(buf);
		int index=0;
		
		for(int i=1;i<len;i++){
			if(buf[i]>buf[index])
				index=i;
			else if(buf[i]<buf[index]){
				buf[index]--;
				for(int j=index+1;j<len;buf[j++]='9');
			}
		}

		printf("Case #%d: %s\n",t,buf[0]=='0'?buf+1:buf);
	}
}