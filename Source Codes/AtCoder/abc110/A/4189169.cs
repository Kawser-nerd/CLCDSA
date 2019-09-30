using System;
using System.Linq;

public class Test
{
	public static void Main()
	{
		var p = Console.ReadLine().Split(' ').Select(v=>int.Parse(v));
Console.WriteLine(p.Max() *9+p.Sum());
	}
}