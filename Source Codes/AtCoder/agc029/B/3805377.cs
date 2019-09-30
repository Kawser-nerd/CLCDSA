using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		string[] str = Console.ReadLine().Split();
		int[] A = new int[N];
		var dic = new Dictionary<int,int>();
		int ans = 0;
		for(var i=0;i<N;i++){
			A[i] = int.Parse(str[i]);
			if(dic.ContainsKey(A[i])){
				dic[A[i]] += 1;
			} else {
				dic[A[i]] = 1;
			}
		}
		Array.Sort(A);
		for(var i=N-1;i>=0;i--){
			for(var j=31;j>=1;j--){
				int a = (int)Math.Pow(2,j);
				if(dic.ContainsKey(a-A[i]) && dic[a-A[i]] > 0 && dic.ContainsKey(A[i]) && dic[A[i]] > 0){
					if(a==A[i]*2){
						if(dic[A[i]] >= 2){
							ans += 1;
							dic[A[i]] -= 2;
						}
					} else {
						ans += 1;
						dic[A[i]] -= 1;
						dic[a-A[i]] -= 1;
					}
					break;
				}
			}
		}
		Console.WriteLine(ans);
	}
}