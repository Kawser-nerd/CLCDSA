using System;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long a = long.Parse(input[1]);
		long b = long.Parse(input[2]);
		Console.WriteLine(((a+b) % 2 == 0) ? "Alice" : "Borys");
	}
}