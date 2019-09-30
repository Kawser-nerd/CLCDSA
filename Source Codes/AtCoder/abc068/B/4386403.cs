using System;

class Challenge
{
    static void Main()
    {
        var N = int.Parse(Console.ReadLine());
      	var n = 1;
      	while( n*2 <= N ) { n *= 2; }
      	Console.WriteLine(n);
    }
}