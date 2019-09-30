using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		long L = long.Parse(str[0]);
		int N = int.Parse(str[1]);
		long[]A = new long[N];
		for(var i=0;i<N;i++){
			string str2 = Console.ReadLine();
			A[i] = long.Parse(str2);
		}
		long[]B = new long[N+1];
		long sum = 0;
		for(var i=0;i<N;i++){
			sum += A[i];
			B[i+1] = sum;
		}
		long ans = A[0];
		int na = 0;
		int na2 = N;
		while(true){
			na2--;
			if(na==na2){
				break;
			}
			ans += A[na]+(L-A[na2]);
			na++;
			if(na==na2){
				break;
			}
			ans += A[na]+(L-A[na2]);
		}
		long ansmax = ans;
		for(var i=1;i<N;i++){
			ans += A[(i+N-1)/2]-A[i-1]-A[i-1];
			ans -= L-A[(i+N)/2];
			ansmax = Math.Max(ans,ansmax);
		}
		ans = L-A[N-1];
		na = -1;
		na2 = N-1;
		while(true){
			na++;
			if(na==na2){
				break;
			}
			ans += A[na]+(L-A[na2]);
			na2--;
			if(na==na2){
				break;
			}
			ans += A[na]+(L-A[na2]);
		}
		ansmax = Math.Max(ans,ansmax);
		for(var i=N-2;i>=0;i--){
			ans += A[i+1]-A[(i+0+1)/2]-(L-A[i+1]);
			ans -= A[(i+0)/2];
			ansmax = Math.Max(ans,ansmax);
		}
		Console.WriteLine(ansmax);
	}
}