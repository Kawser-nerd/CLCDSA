using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
	public static void Main(string[] args)
	{
		var param = System.Console.ReadLine().Split(' ').Select((x) => int.Parse(x)).ToList();

		int A = param[0];
		int B = param[1];
		int C = 0;

		if (1 <= A && 20 >= A && 1 <= B && 20 >= B)
		{
			if (A <= B)
			{
				if (B % A == 0)
				{
					C = A + B;
				}
				else
				{
					C = B - A;
				}
			}
		}
		System.Console.WriteLine(C);
	}
}