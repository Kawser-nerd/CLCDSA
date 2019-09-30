using System;

class Program {
	static void Main(string[] args){
		int M = 52;
		int N = 2503;
		long[,,] tb = new long[M,M,N];
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++){
				for(int k=0;k<N;k++){
					tb[i,j,k] = 0;
				}
			}
		}
		string[] str = Console.ReadLine().Split(' ');
		int  n = int.Parse(str[0]);
		long  a = long.Parse(str[1]);
		long[] x = new long[n];
		str = Console.ReadLine().Split(' ');
		for(int i=0;i<n;i++){
			x[i] = long.Parse(str[i]);
		}
		
		long ans = 0;
		for(int j=0;j<n+1;j++){
			for(int k=0;k<N;k++){
				tb[0,j,k] = 0;
			}
		}
		tb[0,0,0] = 1;
		for(int i=1;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				for(int k=0;k<N;k++){
					tb[i,j,k] = tb[i-1,j,k];
					if(k-x[i-1]>=0 && j>0) tb[i,j,k] += tb[i-1,j-1,k-x[i-1]];
				}
			}
		}
		for(int i=1;i<n+1;i++) ans += tb[n,i,i*a];
		Console.WriteLine(ans);
	}
}