using System;

using System.Linq;
class A
{
    static void Main()
    {
        long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
        if (a[1] == a[0]) { Console.WriteLine(1);return; }
        long s = a[1];
        a[1] %= a[0];
        var ncr = new long[500,500];
        ncr[0, 0] = 1;
        for (long i = 1; i <= 320; i++)
        {
            ncr[i, 0] = 1;
            for (long j = 1; j <= i; j++) { ncr[i, j] = ncr[i - 1, j] % 1000000007 + ncr[i - 1, j - 1] % 1000000007; }
        }
        if (a[0] < s)
        {
            Console.WriteLine(ncr[a[0], a[1]] % 1000000007);
        }
        else
        {
            Console.WriteLine(ncr[a[0]+a[1]-1,a[1]]% 1000000007);
        }
        Console.ReadLine();
    }
}