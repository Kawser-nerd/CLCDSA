using System;


public class A
{
	public static void Main()
	{
		string[] args = Console.ReadLine().Split(' ');
		double T = Double.Parse(args[0]);
		double X = Double.Parse(args[1]);
			
		Console.WriteLine(T/X);
	}	
}