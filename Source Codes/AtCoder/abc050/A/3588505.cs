using System;
using System.Collections;
using System.Linq;


public class Test
{	public static void Main()
	{
		string[] line = Console.ReadLine().Split(' ');

		if(line[1] == "+")
		{
			Console.WriteLine(int.Parse(line[0]) + int.Parse(line[2]));
		}
		else
		{
			Console.WriteLine(int.Parse(line[0]) - int.Parse(line[2]));
		}
	}
}