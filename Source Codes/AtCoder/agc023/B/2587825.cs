using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		int N = int.Parse(str);
		string[,] S = new string[N,N];
		for(var i=0;i<N;i++){
			string t = Console.ReadLine();
			for(var j=0;j<N;j++){
				S[i,j] = t.Substring(j,1);
			}
		}
		string[,] S2 = new string[N,N];
		int count = 0;
		int A = 0;
		int B = N-1;
		while(A<N){
			int f = 1;
			for(var i=0;i<N;i++){
				for(var j=i;j<N;j++){
					if(S[(i+A)%N,(j+B)%N] != S[(j+A)%N,(i+B)%N]){
						f = 0;
						break;
					}
				}
				if(f==0){
					break;
				}
			}
			if(f==1){
				count += N-Math.Abs(A-B);
			}
			if(B > 0){
				B -= 1;
			} else {
				A += 1;
			}
		}
		Console.WriteLine(count);
	}
}