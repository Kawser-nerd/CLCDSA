using System;
using System.Linq;

public class Test
{
	public static void Main(){
var p = Console.ReadLine();
Console.WriteLine(int.Parse(p)%p.ToCharArray().Sum(c=>c-'0')==0?"Yes":"No");
}
}