using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		Console.WriteLine(Math.Abs(s[0]-s[1])<2?"Brown":"Alice");
	}
}