using System;
using System.Linq;

public class Test
{
	public static void Main()=>Console.WriteLine(Console.ReadLine().ToCharArray().Count(c=>c=='+')*2-4);
}