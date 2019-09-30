using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


class Program
{
    static void Main(string[] args)
    {
        long[] n = Read.longs();
        long[] a = new long[n[0]];
        for (long i = 0; i < n[0]; i++)
        {
            a[i] = long.Parse(Console.ReadLine());
        }
        Array.Sort(a);
        if (a[n[0] - 1] - a[0] == 0)
        {
            Console.WriteLine("-1");
        }
        else
        {
            double x = n[2] / (double)(a[n[0] - 1] - a[0]);
            double a1 = n[1] - a.Sum() /(double) n[0] * x;
            Console.WriteLine("{0} {1}", x, a1);
        }
        Console.ReadLine();
    }
    public static Boolean uso() { return false; }
    public static bool IsPrime(long n)
    {
        if (n < 2) return false;
        if (n == 2) return true;

        for (long i = 2; i < n; i++)
        {
            if (n % i == 0) return false;
        }
        return true;
    }

}
public static class Read
{
    public static void outl(string n = "") { Console.WriteLine(n); return; }
    public static long Long()
    {
        return long.Parse(Console.ReadLine());
    }
    public static long[] longs()
    {
        return Console.ReadLine().Split().Select(long.Parse).ToArray();
    }
    public static string Str() { return Console.ReadLine(); }
    public static string[] Strs() { return Console.ReadLine().Split(); }
}