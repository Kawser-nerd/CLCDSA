using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int M = int.Parse(str[1]);
		int C = int.Parse(str[2]);
		string[] str2 = Console.ReadLine().Split();
		int[]B = new int[M];
		for(var i=0;i<M;i++){
			B[i] = int.Parse(str2[i]);
		}
		int[,]A = new int[N,M];
		int ans = 0;
		for(var i=0;i<N;i++){
			string[] str3 = Console.ReadLine().Split();
			int ct = 0;
			for(var j=0;j<M;j++){
				A[i,j] = int.Parse(str3[j]);
				ct += A[i,j]*B[j];
			}
			ct += C;
			if(ct>0){
				ans++;
			}
		}
		Console.WriteLine(ans);
	}
}