using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		int N = int.Parse(str);
		int[] A = new int[100000];
		int[] B = new int[100000];
		for(var i=1;i<100000;i=i+2){
			if(IsPrime(i) && IsPrime((i+1)/2)){
				A[i] = 1;
			}
		}
		int ct = 0;
		for(var i=0;i<100000;i++){
			if(A[i] == 1){
				ct += 1;				
			}
			B[i] = ct;
		}
		for(var i=0;i<N;i++){
			string[] str2 = Console.ReadLine().Split();
			int a1 = int.Parse(str2[0]);
			int a2 = int.Parse(str2[1]);
			int ans = B[a2] - B[a1-1];
			Console.WriteLine(ans);
		}
	}
	
	public static bool IsPrime(int num)
	{
		if (num < 2) return false;
		else if (num == 2) return true;
		else if (num % 2 == 0) return false;

		double sqrtNum = Math.Sqrt(num);
		for (int i = 3; i <= sqrtNum; i += 2){
			if (num % i == 0) return false;
		}
		return true;
	}
}