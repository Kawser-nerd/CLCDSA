#include<stdio.h>
#include<assert.h>
int a[10];
int b[10];
int c[10]={0,2,5,5,4,5,6,3,7,6};
int t,n,m;

int f(int d){
	if(a[d]){
		putchar('0'+d);
		n-=c[d];
		assert(n>=0);
		return 1;
	}
	return 0;
}

int g(int d){
	if(a[d]){
		b[d]++;
		n-=c[d];
		assert(n>=0);
		return 1;
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&t);
		a[t]++;
	}
	if(a[1]){
		//1???
		if(n%2==1){
			//1,1
			if(f(7));//7111
			//3,1
			else if(f(5));//511
			else if(f(3));//311
			else if(f(2));//211
			//5,1
			else if(f(8));//81
			else assert(0);
		}
		for(int i=0;i<n/2;i++)putchar('1');
	}else if(a[7]){
		//7???
		if(n%3==1){
			//1,1
			if(g(4));//774
			//4,1
			else if(f(8));//87
			//4,2
			else if(g(5))g(5);//75
			else if(g(3))g(3);//73
			else if(g(2))g(2);//72
			else assert(0);
		}else if(n%3==2){
			//2,1
			if(g(5));//77775
			else if(g(3));//77773
			else if(g(2));//77772
			//2,2
			else if(g(4))g(4);//77744
			//8,2
			else if(f(8))f(8);//887
			else assert(0);
		}
		for(int i=0;i<n/3;i++)putchar('7');
	}else if(a[4]){
		//4???
		if(n%4==1){
			//1,1
			if(f(5));//544444
			else if(g(3));//444443
			else if(g(2));//444442
			else if(a[8]){
				//5,2
				if(f(9))f(8);//98444
				else if(a[6])f(8),f(6);//86444
				//9,3
				else if(f(8))f(8),f(8);//8884
				else assert(0);
			}else assert(0);
		}else if(n%4==2){
			//2,1
			if(f(9));//9444
			else if(f(6));//6444
			//2,2
			else if(f(5))f(5);//5544
			else if(g(3))g(3);//4433
			else if(g(2))g(2);//4422
			//6,2
			else if(f(8))f(8);//884
			else assert(0);			
		}else if(n%4==3){
			//3,2
			if(n>=11&&a[9]&&(a[5]||a[3]||a[2])){
				f(9);
				if(f(5));//9544
				else if(g(3));//9443
				else if(g(2));//9442
				else assert(0);
			}
			//3,1
			else if(f(8));//8444
			//3,2
			else if(a[6]&&(a[5]||a[3]||a[2])){
				f(6);
				if(f(5));//6544
				else if(g(3));//6443
				else if(g(2));//6442
				else assert(0);
			}
			//3,3
			else if(f(5))f(5),f(5);//5554
			else if(g(3))g(3),g(3);//4333
			else if(g(2))g(2),g(2);//4222
			else assert(0);
		}
		for(int i=0;i<n/4;i++)putchar('4');
	}else if(a[5]||a[3]||a[2]){
		//532???
		if(n%5==1){
			//1,1
			if(f(9));//95555
			else if(f(6));//65555
			//6,3
			else if(f(8))f(8),f(8);//8885
			else assert(0);
		}else if(n%5==2){
			//2,2
			if(n>=12&&f(9))f(9);//995
			//2,1
			else if(f(8));//855
			//2,2
			else if(f(6))f(6);//665
			else assert(0);
		}else if(n%5==3){
			//3,3
			if(n>=18&&f(9))f(9),f(9);//999555
			//3,2
			else if(a[8]&&(a[6]||a[9])){
				if(a[9])f(9),f(8);//985555
				else if(a[6])f(8),f(6);//865555
				else assert(0);
			}
			//3,3
			else if(f(6))f(6),f(6);//666555
			//8,4
			else if(f(8))f(8),f(8),f(8);//88885
			else assert(0);
		}else if(n%5==4){
			//4,4
			if(n>=24&&f(9))f(9),f(9),f(9);//99995
			//4,2
			else if(f(8))f(8);//88555
			//4,4
			else if(f(6))f(6),f(6),f(6);//66665
			else assert(0);
		}
		for(int i=0;i<n/5;i++)putchar(a[5]?'5':a[3]?'3':'2');
	}else if(a[9]){
		while(n%6)g(8);
		for(int i=0;i<n/6;i++)putchar('9');		
	}else if(a[6]){
		while(n%6)f(8);
		for(int i=0;i<n/6;i++)putchar('6');		
	}else if(a[8]){
		for(int i=0;i<n/7;i++)putchar('8');		
	}else assert(0);
	for(int i=9;i>0;i--)while(b[i]--)putchar('0'+i);
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^