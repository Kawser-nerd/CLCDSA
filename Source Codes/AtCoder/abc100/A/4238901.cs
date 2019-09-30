using System;
using System.Linq;

public class Test
{
	public static void Main()=>
Console.WriteLine(Console.ReadLine().Split(' ').Select(i=>int.Parse(i)).Count(i=>i>8)==0?"Yay!":":(");
}