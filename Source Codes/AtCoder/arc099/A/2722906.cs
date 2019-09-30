using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();;
		int N = int.Parse(str[0]);
		int K = int.Parse(str[1]);
		string[] str2 = Console.ReadLine().Split();
		int[] A = new int[N];
		for(var i=0;i<N;i++){
			A[i] = int.Parse(str2[i]);
		}
		int ans = 0;
		int ia = N-1;
		while(ia>0){
			ans += 1;
			ia -= K-1;
		}
		Console.WriteLine(ans);
	}
}