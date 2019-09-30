using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var a = new int[n];
        for (int i = 0; i < n; i++) a[i] = int.Parse(Console.ReadLine().Trim());
        var ret = int.MaxValue;
        var imax = (int)Math.Pow(2, n);
        for (int i = 0; i < imax; i++)
        {
            var t0 = 0; var t1 = 0;
            for (int j = 0; j < n; j++)
                if (((i >> j) & 1) == 0) t0 += a[j];
                else t1 += a[j];
            ret = Math.Min(ret, Math.Max(t0, t1));
        }
        Console.WriteLine(ret);
    }
}