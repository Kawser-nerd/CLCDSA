using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        var c = new int[n - 1];
        var s = new int[n - 1];
        var f = new int[n - 1];

        for (int i = 0; i < n - 1; i++)
        {
            var csf = Console.ReadLine().Split(' ');
            c[i] = int.Parse(csf[0]);
            s[i] = int.Parse(csf[1]);
            f[i] = int.Parse(csf[2]);
        }

        for (int i = 0; i < n; i++)
        {
            var x = 0;
            for (int j = i; j < n - 1; j++)
            {
                x = Math.Max(ceil(x, f[j]), s[j]) + c[j];
            }
            Console.WriteLine(x);
        }
    }

    static int ceil(int x, int y)
    {
        if (0 < x % y)
        {
            return (x / y + 1) * y;
        }
        else
        {
            return x;
        }
    }
}