using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		string str = Console.ReadLine();
		long ans = 0;
		var table = new Dictionary<string,long>();
		string a1;
		string a2;
		for(var i=0;i<Math.Pow(2,N);i++){
			a1 = "";
			a2 = "";
			for(var j=0;j<N;j++){
				if((i/(int)Math.Pow(2,j)) % 2 == 1){
					a2 = str.Substring(j,1) + a2;
				} else {
					a1 = a1 + str.Substring(j,1);
				}
			}
			if(table.ContainsKey(a1+" "+a2)){
				table[a1+" "+a2] += 1;
			} else {
				table[a1+" "+a2] = 1;
			}
		}
		for(var i=0;i<Math.Pow(2,N);i++){
			a1 = "";
			a2 = "";
			for(var j=0;j<N;j++){
				int t = 2*N-1-j;
				if((i/(int)Math.Pow(2,j)) % 2 == 1){
					a2 = a2 + str.Substring(t,1);
				} else {
					a1 = str.Substring(t,1) + a1;
				}
			}
			if(table.ContainsKey(a2+" "+a1)){
				ans += table[a2+" "+a1];
			}
		}
		Console.WriteLine(ans);
	}
}