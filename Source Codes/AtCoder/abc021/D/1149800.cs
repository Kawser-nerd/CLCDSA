using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;
using System.ComponentModel;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

public class Scanner
{
    private StreamReader Sr;
    private string[] S;
    private int Index;
    private const char Separator = ' ';

    public Scanner() : this(Console.OpenStandardInput())
    {
        Index = 0;
        S = new string[0];
    }
    public Scanner(Stream source)
    {
        Sr = new StreamReader(source);
    }

    private string[] Line()
    {
        return Sr.ReadLine().Split(Separator);
    }

    public string Next()
    {
        string result;
        if (Index >= S.Length)
        {
            S = Line();
            Index = 0;
        }
        result = S[Index];
        Index++;
        return result;
    }
    public T Next<T>()
    {
        var converter = TypeDescriptor.GetConverter(typeof(T));
        return (T)converter.ConvertFromString(Next());

    }
    public int NextInt()
    {
        return int.Parse(Next());
    }
    public double NextDouble()
    {
        return double.Parse(Next());
    }
    public long NextLong()
    {
        return long.Parse(Next());
    }
    public decimal NextDecimal()
    {
        return decimal.Parse(Next());
    }
    public string[] StringArray(int index = 0)
    {
        Next();
        Index = S.Length;
        return S.Skip(index).ToArray();
    }
    public int[] IntArray(int index = 0)
    {
        return StringArray(index).Select(int.Parse).ToArray();
    }
    public long[] LongArray(int index = 0)
    {
        return StringArray(index).Select(long.Parse).ToArray();
    }
    public bool EndOfStream
    {
        get { return Sr.EndOfStream; }
    }
}

public class Magatro
{
    Scanner cin = new Scanner();
    private int N;
    private int K;
    private void Scan()
    {
        N = cin.NextInt();
        K = cin.NextInt();
    }

    public void Solve()
    {
        Scan();
        Console.WriteLine(MyMath.Homogeneous(N, K, (int)(1e9 + 7)));
    }

}
static class MyMath
{
    /// <summary>
    /// a?b?
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <param name="mod"></param>
    /// <returns></returns>
    static public long MyPower(long a, long b, long mod)
    {
        long result = 1;
        while (b > 0)
        {
            if (b % 2 == 1)
            {
                result *= a;
                result %= mod;
            }
            a *= a;
            a %= mod;
            b /= 2;
        }
        return result;
    }
    /// <summary>
    /// ??
    /// </summary>
    /// <param name="l"></param>
    /// <param name="mod"></param>
    /// <returns></returns>
    static public long Factorial(long l, long mod)
    {
        if (l < 1e4)
        {
            if (l == 0) return 1;
            return (Factorial(l - 1, mod) * l) % mod;
        }
        else
        {
            long result = 1;
            for (int i = 1; i <= l; i++)
            {
                result *= i;
                result %= mod;
            }
            return result;
        }
    }
    /// <summary>
    /// s?mod??????
    /// </summary>
    /// <param name="s"></param>
    /// <param name="mod"></param>
    /// <returns></returns>
    static public int Mod(string s, int mod)
    {
        int result = 0;

        for (int i = 0; i < s.Length; i++)
        {
            result = (result * 10 + s[i] - '0') % mod;
        }

        return result;
    }
    /// <summary>
    /// ?????
    /// </summary>
    /// <param name="n"></param>
    /// <param name="k"></param>
    /// <param name="mod"></param>
    /// <returns></returns>
    static public long Combination(long n, long k, long mod)
    {
        long bunsi = Factorial(n, mod);
        long bunbo = (Factorial(k, mod) * Factorial(n - k, mod)) % mod;

        long gyakugenn = MyPower(bunbo, mod - 2, mod);

        return (bunsi * gyakugenn) % mod;
    }
    /// <summary>
    /// ???????
    /// </summary>
    /// <param name="n"></param>
    /// <param name="k"></param>
    /// <param name="mod"></param>
    /// <returns></returns>
    static public long Homogeneous(long n,long k,long mod)
    {
        return Combination(n + k - 1, k, mod);
    }
}