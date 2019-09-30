using System;
using System.Collections.Generic;


public class A
{
	public static void Main()
	{
		string[] args = Console.ReadLine().Split(' ');
		long A = Int64.Parse(args[0]);
		long B = Int64.Parse(args[1]);
			
		Console.WriteLine(((B % A) == 0) ? A+B : B-A);
	}	
}