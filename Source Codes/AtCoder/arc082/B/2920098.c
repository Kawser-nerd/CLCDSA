#include<stdio.h>                                                               
int main()                                                                      
{   int a[100005]={0};                                                          
	int n;                                                                         
	scanf("%d",&n);                                                                
	for(int i=1;i<=n;i++)                                                          
	{                                                                              
		scanf("%d",&a[i]);                                                            
	}                                                                              
	int sum=0;                                                                     
	if(a[1]==1)                                                                    
	{                                                                              
		int t=a[2];                                                                   
		a[2]=a[1];                                                                    
		a[1]=t;                                                                       
		sum=sum+1;                                                                    
	}                                                                              
	for(int i=2;i<n;i++)                                                           
	{                                                                              
		if(a[i]==i)                                                                   
		{                                                                             
			int p=a[i+1];                                                                  
			a[i+1]=a[i];                                                                 
			a[i]=p;                                                                 
			sum++;                                                                       
		}                                                                             
	}                                                                              
	  if(a[n]==n)                                                                  
	 {
 		int n=a[1];
 		a[1]=a[n];
 		a[n]=n;
 		sum++;
 	}                                                                              
	printf("%d\n",sum);                                                            
	                                                                               
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);                                                                
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);                                                            
   ^