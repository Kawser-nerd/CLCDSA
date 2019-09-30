using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


class Program
{
    static void Main(string[] args)
    {
        int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = new int[n[0]];
        for(int i = 0; i < n[1]; i++)
        {
            int[] s = Read.Ints();
            a[s[0]-1]++;
            a[s[1]-1]++;
        }
        bool f = true;
        for(int i = 0; i < n[0]; i++)
        {
            if (a[i] % 2 != 0)
            {
                f = false;break;
            }
        }
        Console.WriteLine(f?"YES":"NO");
    }
    public static Boolean uso() { return false; }
    public static bool IsPrime(long n)
    {
        if (n < 2) return false;
        if (n == 2) return true;

        for (int i = 2; i < n; i++)
        {
            if (n % i == 0) return false;
        }
        return true;
    }

}
public static class Read
{
    public static void outl(string n = "") { Console.WriteLine(n); return; }
    public static int Int()
    {
        return int.Parse(Console.ReadLine());
    }
    public static int[] Ints()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }
    public static string Str() { return Console.ReadLine(); }
    public static string[] Strs() { return Console.ReadLine().Split(); }
}