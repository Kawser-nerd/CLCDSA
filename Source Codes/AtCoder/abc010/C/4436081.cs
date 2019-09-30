using System;
class c
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int xa = inp[0], ya = inp[1], xb = inp[2], yb = inp[3], t = inp[4], v = inp[5];
        int L = t * v;
        int n = int.Parse(Console.ReadLine());
        bool judge = false;
        for (int i = 0; i < n; i++)
        {
            var girl = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
            double gx = girl[0], gy = girl[1];
            double Lg = Math.Sqrt((gx - xa) * (gx - xa) + (gy - ya) * (gy - ya)) + Math.Sqrt((xb - gx) * (xb - gx) + (yb - gy) * (yb - gy));
            if (Lg <= L) judge = true;
        }
        Console.WriteLine(judge ? "YES" : "NO");
    }
}