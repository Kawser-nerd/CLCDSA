using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using static System.Console;
using static System.Math;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Xml;
using static MyIO.Cin;

class Program
{
    static int MOD = (int)1e9 + 7;
    static List<long> Fa;

    static int N;
    static long[,] dp;
    static void Solve()
    {
        N = NI();
        int K = NI();

        if (N > K)
        {
            dp = new long[N + 1, K + 1];
            Fill(dp, -1);
            Console.WriteLine(dfs(0, K));
        }
        else
        {
            Console.WriteLine(MNcr(N, K % N));
        }
    }
    static long dfs(int k, int can)
    {
        if (k == N - 1) return 1;
        if (dp[k, can] >= 0) return dp[k, can];
        long res = 0;
        for (int c = 0; c <= can; c++)
        {
            res = MSum(res, dfs(k + 1, c));
        }
        return dp[k, can] = res;

    }
    static void Fill<T>(T[,] a, T b)
    {
        for (int i = 0; i < a.GetLength(0); i++)
        {
            for (int j = 0; j < a.GetLength(1); j++)
            {
                a[i, j] = b;
            }
        }
    }
    static void Swap(ref int a, ref int b)
    {
        int ta = a;
        a = b;
        b = ta;
    }
    static long Factorial(int n)
    {
        if (Fa == null || Fa.Count <= n)
        {
            if (Fa == null) Fa = new List<long> { 1, 1 };
            for (int i = Fa.Count; i <= n; i++)
            {
                Fa.Add((Fa[i - 1] * i) % MOD);
            }
        }
        return Fa[n];
    }
    static long MSum(params long[] a)
    {
        long res = 0;
        foreach (var v in a)
        {
            res = (res + v % MOD) % MOD;
        }
        return (res + MOD) % MOD;
    }
    static long MDiff(params long[] a)
    {
        long res = a[0] % MOD;
        for (int i = 1; i < a.Length; i++)
        {
            res = (res - a[i] % MOD) % MOD;
        }
        return (res + MOD) % MOD;
    }
    static long MDiv(params long[] a)
    {
        long res = a[0] % MOD;
        for (int i = 1; i < a.Length; i++)
        {
            res = MMul(res, MInverse(a[i]));
        }
        return (res + MOD) % MOD;
    }
    static long MMul(params long[] a)
    {
        long res = 1;
        foreach (var v in a)
        {
            res = (res * v % MOD) % MOD;
        }
        return (res + MOD) % MOD;
    }
    static long MPow(long a, long b)
    {
        long res = 1;
        long mul = a;
        while (b > 0)
        {
            if (b % 2 == 1) res = MMul(res, mul);
            mul = MMul(mul, mul);
            b /= 2;
        }
        return res;
    }
    static long MInverse(long a)
    {
        return MPow(a, MOD - 2);
    }
    static long MNcr(int n, int r)
    {
        long res = Factorial(n);
        res = MDiv(res, Factorial(n - r));
        res = MDiv(res, Factorial(r));
        return res;
    }

    static int Gcd(int a, int b)
    {
        return b == 0 ? a : Gcd(b, a % b);
    }
    static long Gcd(long a, long b)
    {
        return b == 0 ? a : Gcd(b, a % b);
    }
    static int Ceil(int a, int b)
    {
        return (a + b - 1) / b;
    }
    static long Ceil(long a, long b)
    {
        return (a + b - 1) / b;
    }
    static void Main(string[] args)
    {
        var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        Console.SetOut(sw);
        Solve();
        Console.Out.Flush();
    }

}


namespace MyIO
{
    using System;
    using System.Text;
    using System.Globalization;

    public static class Cin
    {
        public static string NextToken()
        {
            StringBuilder tokenChars = new StringBuilder();
            bool tokenFinished = false;
            bool skipWhiteSpaceMode = true;
            while (!tokenFinished)
            {
                int nextChar = Console.Read();
                if (nextChar == -1)
                {
                    tokenFinished = true;
                }
                else
                {
                    char ch = (char)nextChar;
                    if (char.IsWhiteSpace(ch))
                    {
                        if (!skipWhiteSpaceMode)
                        {
                            tokenFinished = true;
                            if (ch == '\r' && (Environment.NewLine == "\r\n"))
                            {
                                Console.Read();
                            }
                        }
                    }
                    else
                    {
                        skipWhiteSpaceMode = false;
                        tokenChars.Append(ch);
                    }
                }
            }

            string token = tokenChars.ToString();
            return token;
        }

        public static int NI()
        {
            string token = Cin.NextToken();
            return int.Parse(token);
        }
        public static long NL()
        {
            string token = Cin.NextToken();
            return long.Parse(token);
        }
        public static double ND(bool acceptAnyDecimalSeparator = true)
        {
            string token = Cin.NextToken();
            if (acceptAnyDecimalSeparator)
            {
                token = token.Replace(',', '.');
                double result = double.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else
            {
                double result = double.Parse(token);
                return result;
            }
        }
        public static decimal NextDecimal(bool acceptAnyDecimalSeparator = true)
        {
            string token = Cin.NextToken();
            if (acceptAnyDecimalSeparator)
            {
                token = token.Replace(',', '.');
                decimal result = decimal.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else
            {
                decimal result = decimal.Parse(token);
                return result;
            }
        }
        public static int[] NIA(int N)
        {
            int[] a = new int[N];
            for (int i = 0; i < N; i++)
                a[i] = NI();
            return a;
        }

    }
}