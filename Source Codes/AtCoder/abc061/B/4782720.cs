using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);

        var d = new int[n];

        for (int i = 0; i < m; i++)
        {
            var ab = Console.ReadLine().Split(' ');
            var a = int.Parse(ab[0]);
            var b = int.Parse(ab[1]);
            d[a - 1]++;
            d[b - 1]++;
        }

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine(d[i]);
        }
    }
}