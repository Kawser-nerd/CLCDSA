using System;


public class A
{
	public static void Main()
	{
		string[] args = Console.ReadLine().Split(' ');
		long ab = Int64.Parse(args[0]);
		long bc = Int64.Parse(args[1]);
			
		Console.WriteLine((ab*bc)/2);
	}	
}