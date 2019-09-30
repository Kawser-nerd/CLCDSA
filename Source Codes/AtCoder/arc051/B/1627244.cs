using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    public static bool f = false, t = true;
    static void Main(string[] args)
    {
        long[] a = new long[100];
        a[1] = 1;
        a[0] = 1;
        for (int i = 2; i <100; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        long j = long.Parse(Console.ReadLine());
        Console.WriteLine(a[j-1]+" "+a[j]);
    }

    public static long gcd(long []a)
    {
        long sec = 0;
        while (true)
        {
            if (a[0] == 0) { return sec; }
            a[1] %= a[0];
            Array.Sort(a);
            sec++;
        }
    }
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
    public static int Int()
    {
        return int.Parse(Console.ReadLine());
    }
    public static int[] ints()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }
    public static string Str() { return Console.ReadLine(); }
    public static string[] Strs() { return Console.ReadLine().Split(); }
}