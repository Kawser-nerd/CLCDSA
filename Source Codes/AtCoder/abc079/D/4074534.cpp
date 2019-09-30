#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std ;

int m ,n  ,  dis[15] , vis[15] , e[15][15] ;

const int MAX = 9999999 ; 

int need[205][205] ;


int a[10] ;


int dij(int u){
	for(int i = 0 ; i < 10 ; i++) dis[i] = e[u][i] ; // ???? , ??????? , ?????????????  
	vis[u] = 1 ;
	
	//for(int i = 0 ; i < 10 ; i++) printf("%d\n" , dis[i]) ;
	
	for(int i = 0 ; i < 9 ; i++){
		int v ;
		int minn = MAX ;
		
		for(int j = 0 ; j <= 9 ; j++){
			if(!vis[j]&&dis[j]<minn){
				//system("pause") ;
				v = j ;
				minn = dis[j] ;
			//	printf("%d   %d  \n" , v , minn) ;
			}
		} 
		//system("pause") ;
		vis[v] = 1 ;
		for(int j = 0 ; j <= 9 ; j++){
			//printf("%d " , dis[1]) ;
			dis[j] = min(dis[j] , dis[v]+e[v][j]) ;
			//printf("%d\n" , dis[j]) ;	 
		}
	}
	
	return dis[1] ;
	//for(int i = 0 ; i <= 9 ; i++){
	//	printf("%d  " , dis[i]) ;
	//}
	//putchar('\n') ;
	
}

int main(){
	
	int m , n , s ;
	cin>>m>>n ;
	
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			scanf("%d" , &e[i][j]) ;
		}
		//dis[i] = MAX ;
	}
	
	int sum = 0 ;
	
	//memset(vis,0,sizeof(vis)) ;
	
	//for(int i = 0 ; i <=9 ; i++){
		//dij(i) ;
		//a[i] = dis[1] ;
	//}
//	for(int i = 0 ; i <= 9 ; i++){
	//	printf("%d  " , a[i]) ;
//	}
	for(int i = 0 ; i <=9 ; i++){
		
		memset(vis,0,sizeof(vis)) ;
		for(int j = 0 ; j <= 9 ; j++){
			dis[j] = MAX ;
		}
		a[i] = dij(i);
		//printf("%d   "  , a[i]) ;
	}

	//for(int i = 0 ; i <=9 ; i++){
		//printf("%d    " , dis[i]) ;
	//}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			scanf("%d" , &s) ;
			if(s == -1) continue ;
			//printf("%d\n" , dis[need[i][j]]) ;
			//system("puase") ;
			
			sum += a[s] ;
		}
	}
	cout<<sum<<endl ;
	
	return 0 ;
	
}