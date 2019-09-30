using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		long[] S = new long[str.Length];
		long t = 1;
		long At = 0;
		long Bt = 0;
		long Ct = 0;
		for(var i=0;i<str.Length;i++){
			if(str.Substring(i,1)=="A"){
				At = At + t;
			}
			else if(str.Substring(i,1)=="B"){
				Bt = Bt + At;
			}
			else if(str.Substring(i,1)=="C"){
				Ct = Ct + Bt;
			}
			else {
				Ct = Ct * 3 + Bt;
				Bt = Bt * 3 + At;
				At = At * 3 + t;
				t = t * 3;
			}
			t = t % 1000000007;
			At = At % 1000000007;
			Bt = Bt % 1000000007;
			Ct = Ct % 1000000007;
		}
		Console.WriteLine(Ct % 1000000007);
	}
}