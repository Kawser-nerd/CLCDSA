using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    public static long mod = (long)(Math.Pow(10, 9) + 7);
    public static bool f = false, t = true;
    static void Main(string[] args)
    {
        int[] a = new int[1000005];
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
            a[s[0]]++;
            a[s[1] + 1]--;

        }
        for (int i = 1; i < a.Length; i++)
        {
            a[i] += a[i - 1];

        }
        
        Array.Sort(a);
        Console.WriteLine(a[a.Length - 1]);
        Console.ReadLine();
    }
    public static long gcd(long a, long b)
    {
        if (b == 0) { return a; }
        return gcd(b, a % b);
    }
    public static long lcm(long a, long b) { return a / gcd(a, b) * b; }
    public static string Reverse(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static bool IsPrime(int num)
    {
        if (num < 2) return false;
        else if (num == 2) return true;
        else if (num % 2 == 0) return false; // ??????????

        double sqrtNum = Math.Sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2)
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