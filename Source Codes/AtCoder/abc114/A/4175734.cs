using System;
using System.Linq;
class Program
{
	static void Main(string[] args)=>Console.WriteLine(new int[]{3,5,7}.Contains(int.Parse(Console.ReadLine()))?"YES":"NO");
}