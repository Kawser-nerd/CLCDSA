using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		int N = int.Parse(str);
		int i = 1;
		while(true){
			if(Math.Pow(i+1,2) <= N){
				i += 1;
			} else {
				break;
			}
		}
		Console.WriteLine(Math.Pow(i, 2));
	}
}