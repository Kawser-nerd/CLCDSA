using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		int[,]A = new int[N,2];
		int[][]B = new int[N*2][];
		for(var i=0;i<N;i++){
			string[] str = Console.ReadLine().Split();
			A[i,0] = int.Parse(str[0]);
			A[i,1] = int.Parse(str[1]);
			B[i*2] = new int[3];
			B[i*2][0] = A[i,0];
			B[i*2][1] = i;
			B[i*2][2] = 0;
			B[i*2+1] = new int[3];
			B[i*2+1][0] = A[i,1];
			B[i*2+1][1] = i;
			B[i*2+1][2] = 1;
		}
		Array.Sort(B, (x,y) => x[0] - y[0]);
		int[,]C = new int[N,2];
		int cta = 0;
		int ctb = 0;
		long ct = 0;
		for(var i=0;i<N;i++){
			ct += B[i][0];
			C[B[i][1],B[i][2]] += 1;
			if(B[i][2] == 0){
				cta += 1;
			} else {
				ctb += 1;
			}
		}
		if(cta < N && ctb < N){
			int fct = 0;
			for(var i=0;i<N;i++){
				if(C[i,0] == 1 && C[i,1] == 1){
					fct += 1;
				}
			}
			if(fct == 0){
				ct -= B[N-1][0];
				ct += B[N][0];
				if(B[N-1][1] == B[N][1]){
					long ct1 = ct;
					ct1 -= B[N][0];
					ct1 += B[N+1][0];
					long ct2 = ct;
					ct2 -= B[N-2][0];
					ct2 += B[N-1][0];
					ct = Math.Min(ct1,ct2);
				}
			}
		}
		Console.WriteLine(ct);
	}
}