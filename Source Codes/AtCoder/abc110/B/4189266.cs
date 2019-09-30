using System;
using  System.Linq;

public class Test
{
	public static void Main()
	{
		var p = Console.ReadLine().Split(' ').Select(i=>int.Parse(i)).ToArray();
		var a = Console.ReadLine().Split(' ').Select(i=>int.Parse(i)).Concat( new int[1]{p[2]}).Max();
		var b = Console.ReadLine().Split(' ').Select(i=>int.Parse(i)).Concat( new int[1]{p[3]}).Min();
Console.WriteLine((a<b?"No ":"") + "War");
	}
}