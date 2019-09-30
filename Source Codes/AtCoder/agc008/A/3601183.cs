using System;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');
		long x = long.Parse(input[0]);
		long y = long.Parse(input[1]);
    long a = Math.Abs(Math.Abs(x)-Math.Abs(y));

    if(x<y && y<=0 || 0<=x && x<y) a += 0;
    else if(y<x && x<0 || 0<y && y<x) a += 2;
    else a += 1;
		Console.WriteLine(a);
	}
}