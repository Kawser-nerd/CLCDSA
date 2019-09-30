using System;
class Program
{
	static void Main()
	{
		string[] s = Console.ReadLine().Split(' ');
		long a = long.Parse(s[1]);
		long b = long.Parse(s[2]);
		Console.WriteLine(((a+b) % 2 == 0) ? "Alice" : "Borys");
	}
}