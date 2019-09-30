using System;
using System.Linq;
class c
{
    static void Main()
    {
        var nk = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        a = a.OrderBy(f => f).ToArray();
        if (nk[0] > 1)
        {
            int gcdAll = Gcd(a[0], a[1]);
            for (int i = 2; i < a.Length; i++)
            {
                gcdAll = Gcd(gcdAll, a[i]);
            }
            Console.WriteLine((nk[1] % gcdAll == 0) && (nk[1] <= a.Last()) ? "POSSIBLE" : "IMPOSSIBLE");
        }
        else
        {
            Console.WriteLine(nk[1] == a[0] ? "POSSIBLE" : "IMPOSSIBLE");
        }
    }
    public static int Gcd(int x, int y)
    {
        if (x < y) return Gcd(y, x);
        while (y != 0)
        {
            var temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
}