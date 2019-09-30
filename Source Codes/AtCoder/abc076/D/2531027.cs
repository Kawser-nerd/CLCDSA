using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var ti = Array.ConvertAll(line, int.Parse);
        line = Console.ReadLine().Trim().Split(' ');
        var ve = Array.ConvertAll(line, int.Parse);
        var vmax = setData(ti, ve, ti.Sum() * 2 + 1);
        getAns(vmax);
        Console.WriteLine(vmax.Sum()/2);
    }
    public static void getAns(double[] v)
    {
        for (int i = 1; i < v.Length - 1; i++)
            v[i] = Math.Min(v[i], v[i - 1] + 0.5);
        for (int i = v.Length - 2; i >= 1; i--)
            v[i] = Math.Min(v[i], v[i + 1] + 0.5);
    }
    public static double[] setData(int[] ti, int[] ve, int vL)
    {
        var n = ti.Length;
        var ret = new double[vL];
        var p = 0;
        for (int i = 0; i < n; i++)
            foreach (var x in Enumerable.Repeat(ve[i], ti[i] * 2))
                ret[p++] = x;
        ret[0] = 0;
        var wp = 0;
        for (int i = 0; i < n-1; i++)
        {
            wp += ti[i] * 2;
            ret[wp] = Math.Min(ve[i], ve[i + 1]);
        }
        return ret;
    }
}