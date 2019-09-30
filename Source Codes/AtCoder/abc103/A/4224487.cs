using System;
using System.Linq;

public class Test
{
	public static void Main(){
var p = Console.ReadLine().Split(' ').Select(s=>int.Parse(s));
Console.WriteLine(p.Max()-p.Min());
}
}