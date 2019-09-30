using System;

class Program
{
    static void Main(string[] args)
    {
        var x = int.Parse(Console.ReadLine());

        var d = new int[x + 1];
        d[0] = 0;
        for (int i = 1; i < d.Length; i++)
        {
            d[i] = d[i - 1] + 1;

            var n = 6;
            while (0 <= i - n)
            {
                d[i] = Math.Min(d[i], d[i - n] + 1);
                n *= 6;
            }

            n = 9;
            while (0 <= i - n)
            {
                d[i] = Math.Min(d[i], d[i - n] + 1);
                n *= 9;
            }
        }

        Console.WriteLine(d[x]);
    }
}