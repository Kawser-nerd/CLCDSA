using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    public static bool f = false, t = true;
    static void Main(string[] args)
    {
        long n = long.Parse(Read.Str());
        
        long ans = 1;
        for (long i1 = 2; i1 <= n; i1++)
        {
            if (IsPrime(i1))
            {
                long ans1 = 1;
                for (long i = i1; i <= n; i += i1)
                {
                    long y = i;
                    while (y % i1 == 0)
                    {
                        y /= i1;

                        ans1++;
                  //      if (y % i1 != 0) { break; }
                    }
                }
                ans %= (long)(Math.Pow(10,9)+7);
                ans *= ans1;
            }
        }
        ans %= (long)(Math.Pow(10, 9) + 7); Console.WriteLine(ans);
        Console.ReadLine();
    }
    public static long gcd(long a, long b)
    {
        while (true)
        {
            if (a == 0) { return b; }
            if (b == 0) { return a; }
            if (a > b) { a %= b; }
            else { b %= a; }
        }
    }
    public static long lcm(long a, long b) { return a / gcd(a, b) * b; }
    public static string Reverse(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static bool IsPrime(long num)
    {
        if (num < 2) return false;
        else if (num == 2) return true;
        else if (num % 2 == 0) return false; // ??????????

       for (long i = 3; i*i <= num; i += 2)
        {
            if (num % i == 0)
            {
                // ??????
                return false;
            }
        }

        // ?????
        return true;
    }
}
public static class Read
{
    public static void outl(string n = "") { Console.WriteLine(n); return; }
    public static long Long() { return long.Parse(Console.ReadLine()); }
    public static long[] longs() { return Console.ReadLine().Split().Select(long.Parse).ToArray(); }
    public static int Int() { return int.Parse(Console.ReadLine()); }
    public static int[] ints() { return Console.ReadLine().Split().Select(int.Parse).ToArray(); }
    public static string Str() { return Console.ReadLine(); }
    public static string[] Strs() { return Console.ReadLine().Split(); }
}