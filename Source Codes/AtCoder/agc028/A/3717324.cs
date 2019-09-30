using System;
using System.Linq;
class c
{
    static void Main()
    {
        var nm = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var s = Console.ReadLine();
        var t = Console.ReadLine();
        if (nm[0] > nm[1])
        {
            nm = nm.OrderBy(_ => _).ToArray();
            var temp = s;
            s = t;
            t = temp;
        }
        long n = nm[0];
        long m = nm[1];
        int now = nm[1] % nm[0];
        while (now != 0)
        {
            nm[1] = nm[0];
            nm[0] = now;
            now = nm[1] % nm[0];
        }
        long gcd = nm[0];
        long lcm = n * m / gcd;
        bool judge = true;
        for (int i = 0; i < gcd; i++)
        {
            if (s[(int)(i * lcm / m)] != t[(int)(i * lcm / n)]) judge = false;
        }
        Console.WriteLine(judge ? lcm : -1);
    }
}