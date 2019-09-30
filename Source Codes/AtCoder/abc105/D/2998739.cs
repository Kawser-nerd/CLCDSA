using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		long N = long.Parse(str[0]);
		long M = long.Parse(str[1]);
		long ans = 0;
		long ct = 0;
		string[] str2 = Console.ReadLine().Split();
		var table = new Dictionary<long, long>();
		table[0] = 1;
		for(var i=0;i<N;i++){
			ct = (ct + long.Parse(str2[i])) % M;
			bool contains = table.ContainsKey(ct);
			if(contains){
				ans += table[ct];
				table[ct] += 1;
			} else {
				table[ct] = 1;
			}
		}
		Console.WriteLine(ans);
	}
}