using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		long mod = 1000000007;
		if(N==3){
			Console.WriteLine("61");
		} else {
		long[,]A = new long[N,256];
		long[,]B = new long[N,256];
		for(var i=0;i<256;i++){
			A[3,i] = 1;
		}
		for(var i=0;i<=3;i++){
			B[3,24+i] = 1;
			A[3,24+i] = 0;
			B[3,64*i+6] = 1;
			A[3,64*i+6] = 0;
			B[3,36+i] = 1;
			A[3,36+i] = 0;
			B[3,64*i+9] = 1;
			A[3,64*i+9] = 0;
			B[3,72+i] = 1;
			A[3,72+i] = 0;
			B[3,64*i+18] = 1;
			A[3,64*i+18] = 0;
			B[3,16*i+6] = 1;
			A[3,16*i+6] = 0;
			B[3,4*i+18] = 1;
			A[3,4*i+18] = 0;
		}
		int[]C = new int[32]{24,25,26,27,6,70,134,198,36,37,38,39,9,73,137,201,72,73,74,75,18,82,146,210,6,22,38,54,18,22,26,30};
		for(var i=4;i<N;i++){
			for(var j=0;j<=255;j++){
				if(C.Contains(j)){
					B[i,j] += A[i-1,j/4]+A[i-1,j/4+64]+A[i-1,j/4+128]+A[i-1,j/4+192];
					B[i,j] %= mod;
				} else {
					A[i,j] = A[i-1,j/4]+A[i-1,j/4+64]+A[i-1,j/4+128]+A[i-1,j/4+192];
					A[i,j] %= mod;
				}
			}
			for(var j=0;j<=255;j++){
				B[i,j] += B[i-1,j/4]+B[i-1,j/4+64]+B[i-1,j/4+128]+B[i-1,j/4+192];
				B[i,j] %= mod;
			}
		}
		long ans = 1;
		for(var j=0;j<N;j++){
			ans = ans * 4 % mod;
		}
		long ans2 = 0;
		for(var j=0;j<256;j++){
			ans2 = (ans2 + B[N-1,j]) % mod;
		}
		ans = ans + mod - ans2;
		Console.WriteLine(ans%mod);
		}
	}
}