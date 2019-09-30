using System;
class Program
{
	static void Main(string[] args)
	{
		string s = Console.ReadLine();
		int num = s.Length - 2;
		Console.WriteLine(s[0] + num.ToString() + s[s.Length - 1]);
	}
}