using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int H = int.Parse(str[0]);
		int W = int.Parse(str[1]);
		string[] str2 = Console.ReadLine().Split();
		int h = int.Parse(str2[0]);
		int w = int.Parse(str2[1]);
		Console.WriteLine((H-h)*(W-w));
	}
}