using System;
using System.Collections.Generic;
using System.Linq;

//Paiza//AtCoder??Template
public class Program
{
	public static void Main(string[] args)
	{
		int C = 0;
		//A = int.Parse(Console.ReadLine());
		//B = int.Parse(Console.ReadLine());

		var param = System.Console.ReadLine().Split(' ').Select((x) => int.Parse(x)).ToList();

		int A = param[0];
		int B = param[1];

		if (1 <= A && A <= 20 && 1 <= B && B <= 20)
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
			Console.WriteLine(C);
		}
	}
}