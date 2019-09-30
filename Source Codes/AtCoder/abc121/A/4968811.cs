using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;


public class A
{
	public static void Main()
	{
		string[] args;

		args = Console.ReadLine().Split(' ');
		int H = Int32.Parse(args[0]);
		int W = Int32.Parse(args[1]);
		
		args = Console.ReadLine().Split(' ');
		int h = Int32.Parse(args[0]);
		int w = Int32.Parse(args[1]);
		
		Console.WriteLine((H - h) * (W - w));
	}	
}