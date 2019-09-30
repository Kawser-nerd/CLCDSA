using System.Linq;
using System;

public class Hello
{
    public const long INF = 999999999999999;
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = long.Parse(line[0]);
        var x = long.Parse(line[1]);
        line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, long.Parse);
        var ans = getAns(a, x);
        Console.WriteLine(ans);
    }
    public static long getAns(long[] a, long x)
    {
        var n = a.Length;
        var mina = new long[n];
        for (int i = 0; i < n; i++) mina[i] = a[i];
        var finret = mina.Sum();
        for (int i = 1; i < n; i++)
        {
            var ret = 0L;
            for (int j = 0; j < n; j++)
            {
                var ni = (j - i + n) % n;
                mina[j] = Math.Min(mina[j], a[ni]);
                ret += mina[j];
            }
            ret += i * x;
            finret = Math.Min(ret, finret);
        }
        return finret;
    }
}