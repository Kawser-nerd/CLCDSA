using System;

public class B
{
    public long h0 { get; set; }
    public long s { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var n = long.Parse(Console.ReadLine().Trim());
        var bs = new B[n];
        var hmax = 0L; var hmin = 0L;
        for (long i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            var h = long.Parse(line[0]);
            var s = long.Parse(line[1]);
            bs[i] = new B { h0 = h, s = s };
            hmax = Math.Max(hmax, (n - 1) * s + h);
            hmin = Math.Max(hmin, h);
        }
        var ret = goBin(bs, hmax, hmin);
        Console.WriteLine(ret);
    }
    public static long goBin(B[] bs, long hmax, long hmin)
    {
        while (true)
        {
            var t = (hmax + hmin) / 2L;
            if (canShoot(bs, t)) hmax = t;
            else hmin = t;
            if (hmax == hmin) return getNumSame(bs, hmax);
            else if (hmax - hmin == 1) return getNumDef1(bs, hmax);
        }
    }
    public static long getNumSame(B[] bs, long t)
    {
        if (canShoot(bs, t + 2) && !canShoot(bs, t + 1)) return t + 2;
        else if (canShoot(bs, t + 1) && !canShoot(bs, t)) return t + 1;
        else if (canShoot(bs, t) && !canShoot(bs, t - 1)) return t;
        else if (canShoot(bs, t - 1) && !canShoot(bs, t - 2)) return t - 1;
        else return t - 2;
    }
    public static long getNumDef1(B[] bs, long t)
    {
        if (canShoot(bs, t + 2) && !canShoot(bs, t + 1)) return t + 2;
        else if (canShoot(bs, t + 1) && !canShoot(bs, t)) return t + 1;
        else if (canShoot(bs, t) && !canShoot(bs, t - 1)) return t;
        else if (canShoot(bs, t - 1) && !canShoot(bs, t - 2)) return t - 1;
        return t - 2;
    }
    public static bool canShoot(B[] bs, long h)
    {
        var n = bs.Length;
        var a = new double[n];
        for (long i = 0; i < n; i++) a[i] = (double)(h - bs[i].h0) / bs[i].s;
        Array.Sort(a);
        for (long i = 0; i < n; i++)
            if (i > a[i]) return false;
        return true;
    }
}