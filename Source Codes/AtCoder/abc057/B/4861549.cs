using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split();
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);

        var a = new int[n];
        var b = new int[n];
        for (int i = 0; i < n; i++)
        {
            var ab = Console.ReadLine().Split();
            a[i] = int.Parse(ab[0]);
            b[i] = int.Parse(ab[1]);
        }

        var c = new int[m];
        var d = new int[m];
        for (int i = 0; i < m; i++)
        {
            var cd = Console.ReadLine().Split();
            c[i] = int.Parse(cd[0]);
            d[i] = int.Parse(cd[1]);
        }

        for (int i = 0; i < n; i++)
        {
            var min = int.MaxValue;
            var min_j = 0;
            for (int j = 0; j < m; j++)
            {
                var distance = Math.Abs(a[i] - c[j]) + Math.Abs(b[i] - d[j]);
                if (distance < min)
                {
                    min_j = j;
                    min = distance;
                }
            }
            Console.WriteLine(min_j + 1);
        }
    }
}