using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class B
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] p = Console.ReadLine().Split();
			int X = int.Parse(p[0]);
			int Y = int.Parse(p[1]);
			Console.Write("Case #" + CASE + ": ");
			// Do X
			while (X != 0)
			{
				if (X < 0)
				{
					Console.Write("EW");
					X++;
				}
				else
				{
					Console.Write("WE");
					X--;
				}
			}
			// Do X
			while (Y != 0)
			{
				if (Y < 0)
				{
					Console.Write("NS");
					Y++;
				}
				else
				{
					Console.Write("SN");
					Y--;
				}
			}
			Console.WriteLine();
		}
	}
}
