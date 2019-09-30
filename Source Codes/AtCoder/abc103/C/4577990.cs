using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        Console.ReadLine();
        var d = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var ans = 0;
        for (int i = 0; i < d.Length; i++)
        {
            ans += d[i] - 1;
        }
        Console.WriteLine(ans);
    }
}