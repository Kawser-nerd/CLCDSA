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
        int N = IntRead();
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int[] box = SpIntRead(' ');
        //int[] box = new int[100000];
        //for (int i = 0; i < 100000; i++) box[i] = 1000000000;
        foreach (var i in box)
        {
            if (!dic.ContainsKey(i)) dic[i] = 1;
            else dic[i]++;
        }
        var sorted = dic.OrderByDescending(k => k.Key);
        int x = 0, y = 0;
        foreach (var v in sorted)
        {
            if (x == 0 &&v.Value >= 4) {
                x = y = v.Key;
                break;
            }
            else if (v.Value >= 2)
            {
                if (x == 0) x = v.Key;
                else
                {
                    y = v.Key;
                    break;
                }
            }
        }
        Console.WriteLine((long)x * y);
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
    public static string StrReverce(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static int IntRead()
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
        return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
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
        ret = StrReverce(ret);
        return ret;
    }
}