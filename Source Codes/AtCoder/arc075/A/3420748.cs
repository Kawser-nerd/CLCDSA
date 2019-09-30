using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{

    public static void Main()
    {
        int N = intRead();
        bool[] dp = new bool[10100];
        for (int i = 0; i < 10010; i++) dp[i] = false;
        dp[0] = true;
        int box;
        for (int i = 0; i < N; i++)
        {
            box = intRead();
            //????????????????
            for (int j = 10000; j != -1; j--) { if (dp[j]) dp[j + box] = true; }
        }
        for (int i = 10000; i != -1; i--)
        {
            if (i % 10 == 0) continue;
            else if (dp[i])
            {
                Console.WriteLine(i);
                return;
            }
        }
        Console.WriteLine(0);
    }
}


public class Atcoder
{
    static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static long LCM(long a, long b)
    {
        long c = a * b;
        if (a < b) Swap(ref a, ref b);
        long d = a % b;
        while (d != 0)
        {
            a = b;
            b = d;
            d = a % b;
        }
        return c / b;
    }
    public static string strReverce(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static int intRead()
    {
        return int.Parse(Console.ReadLine());
    }
    public static bool IsPrime(int n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        //double sqrtNum = Math.Sqrt(n);
        for (int i = 3; i < n; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
    public static string[] SpRead(char c)
    {
        return Console.ReadLine().Split(c);
    }
    public static int[] SpIntRead(char c)
    {
        return Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
    }
    public static string ToConvertBit(int N, int e)
    {
        string ret = "";
        int r = 0;
        while (N != 0)
        {
            r = N % e;
            ret += r.ToString();
            N -= r;
            N /= e;
        }
        ret = strReverce(ret);
        return ret;
    }

}