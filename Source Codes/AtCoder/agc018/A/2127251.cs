using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nk = Console.ReadLine().Split().Select(int.Parse).ToArray();

        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int agcd = a[0];
        for (int i = 0; i < a.Length; i++)
        {
            agcd = gcd(agcd, a[i]);
        }
        int modk = nk[1] % agcd;
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] % agcd == modk && nk[1] <= a[i])
            {
                Console.WriteLine("POSSIBLE");
                return;
            }
        }
        Console.WriteLine("IMPOSSIBLE");
    }
    public static int gcd(int a, int b)
    {
        if (a < b) return gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
}