using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var line1 = Console.ReadLine().Split();
        var N = int.Parse(line1[0]);
        var X = int.Parse(line1[1]);
        var m = new int[N];
        for (int i=0; i<N; i++)
        {
            m[i] = int.Parse(Console.ReadLine());
        }
        var answer = N + ( X - m.Sum() ) / m.Min();
        Console.WriteLine(answer);
    }
}