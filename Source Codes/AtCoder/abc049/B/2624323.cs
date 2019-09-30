using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int H = int.Parse(str[0]);
		int W = int.Parse(str[1]);
		string[] c = new string[H];
		for(var i=0;i<H;i++){
			c[i] = Console.ReadLine();
		}
		for(var i=0;i<H;i++){
			Console.WriteLine(c[i]);
			Console.WriteLine(c[i]);
		}
	}
}