using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int[] inp = IntLine();
        int N = inp[0], D = inp[1], K = inp[2];
        int[,] LR = new int[D, 2];
        int[,] ST = new int[K, 3];
        for (int i = 0; i < D; i++)
        {
            inp = IntLine();
            LR[i, 0] = inp[0];
            LR[i, 1] = inp[1];
        }
        for (int i = 0; i < K; i++)
        {
            inp = IntLine();
            ST[i, 0] = inp[0];
            ST[i, 1] = inp[1];
            ST[i, 2] = 0;
        }

        for (int i = 0; i < K; i++)
        {
            //Console.WriteLine(i + "??");
            for (int d = 0; d < D; d++)
            {
                if (LR[d, 0] <= ST[i, 0] && ST[i, 0] <= LR[d, 1])
                {
                    //???????
                    if (ST[i, 1] - ST[i, 0] > 0)
                    {
                        //????
                        var possible = Math.Min(Math.Abs(LR[d, 1] - ST[i, 0]), Math.Abs(ST[i, 1] - ST[i, 0]));
                        ST[i, 0] += possible;
                        ST[i, 2] = (d + 1);
                        //Console.WriteLine("  " + (d + 1) + "????");
                    }
                    else if (ST[i, 1] - ST[i, 0] < 0)
                    {
                        //????
                        var possible = Math.Min(Math.Abs(LR[d, 0] - ST[i, 0]), Math.Abs(ST[i, 0] - ST[i, 1]));
                        ST[i, 0] -= possible;
                        ST[i, 2] = (d + 1);
                        //Console.WriteLine("  " + (d + 1) + "????");
                    }
                    else { }//?????
                }
            }
            Console.WriteLine(ST[i, 2]);
        }
    }
}

public class Atcoder
{
    public static void Swap<T>(ref T a, ref T b)
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
    public static int IntRead()
    {
        return int.Parse(Console.ReadLine());
    }
    public static long LongRead()
    {
        return long.Parse(Console.ReadLine());
    }
    public static long[] LongLine()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
    public static int[] IntLine()
    {
        return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }
}