using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
        string a = Console.ReadLine();
        int[] ret = new int[26];
        for (int j = 0; j <= 'z' - 'a'; j++)
        {
            int i = j + 'a';
            int maxvalue = 0, KOushin = 0;
            for (int k = 0; k < a.Length; k++)
            {
                if (a[k] == (char)i) { maxvalue = Math.Max(maxvalue, KOushin);/*maxvalue < KOushin ? KOushin : maxvalue;*/ KOushin = 0; }
                else { KOushin++; }
            }maxvalue = Math.Max(maxvalue, KOushin);
            ret[j] = maxvalue;
        }
        Array.Sort(ret);
        Console.WriteLine(ret[0]);
    }
    public static Boolean uso() { return false; }
    public static long gcd(long a, long b)
    {
        while (true)
        {
            if (a == 0) { return b; }
            if (b == 0) { return a; }
            if (a > b) { a -= b; }
            else { b -= a; }
        }
    }
    public static long lcm(long a, long b)
    {
        return a * b / gcd(a, b);
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