using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		long N = long.Parse(str[0]);
		long X = long.Parse(str[1]);
		long[] C = new long[N];
		string[] str2 = Console.ReadLine().Split();
		long suma = 0;
		long[] D = new long[N];
		for(var i=0;i<N;i++){
			C[i] = long.Parse(str2[i]);
			suma += C[i];
			D[i] = suma;
		}
		long min = -1;
		for(var i=1;i<=N;i++){
			long sumt = 0;
			long aat = N-1;
			long at = 1;
			long ak = 5;
			while(true){
				if(at>=3){
					ak = at*2+1;
				}
				if(aat-i<0){
					sumt += ak * D[aat];
					break;
				} else {
					sumt += ak * (D[aat] - D[aat - i]);
				}
				if(sumt >= Math.Pow(10,17)){
					break;
				}
				aat -= i;
				at += 1;
			}
			sumt += X * i;
			if(min == -1){
				min = sumt;
			} else {
				min = Math.Min(min,sumt);
			}
		}
		min += N * X;
		Console.WriteLine(min);
	}
}