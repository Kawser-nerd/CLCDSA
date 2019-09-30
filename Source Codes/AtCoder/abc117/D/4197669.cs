using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		long K = long.Parse(str[1]);
		string[] str2 = Console.ReadLine().Split();
		long[]A = new long[N];
		for(var i=0;i<N;i++){
			A[i] = long.Parse(str2[i]);
		}
		int[]B1 = new int[40];
		int[]B2 = new int[40];
		for(var i=0;i<N;i++){
			long t = 1;
			for(var j=0;j<40;j++){
				long x = A[i]/t%2;
				if(x==0){
					B1[j]++;
				} else {
					B2[j]++;
				}
				t *= 2;
			}
		}
		long t2 = (long)Math.Pow(2,39);
		long[]D1 = new long[40];
		long[]D2 = new long[40];
		long ansf = 0;
		long ans = 0;
		bool flag = false;
		for(var i=39;i>=0;i--){
			if(flag){
				if(B1[i] > B2[i]){
					D1[i] = D1[i+1] + B1[i] * t2;
					if(K >= t2+ansf){
						ansf += t2;
						ans += B1[i] * t2;
					} else {
						ans += B2[i] * t2;
					}
				} else {
					D1[i] = D1[i+1] + B2[i] * t2;
					ans += B2[i] * t2;
				}
				D2[i] = ans;
			} else if(K >= t2){
				D1[i] = ans + B2[i] * t2;
				flag = true;
				if(B1[i] > B2[i]){
					ansf += t2;
					ans += B1[i] * t2;
				} else {
					ans += B2[i] * t2;
				}
				D2[i] = ans;
			} else {
				ans += B2[i] * t2;
				D2[i] = ans;
			}
			t2 /= 2;
		}
		Console.WriteLine(Math.Max(D1[0],ans));
	}
}