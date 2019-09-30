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
    private int H, W;
    private int[][] a;
    private const int Mod = 1000000007;
    private int[] Dp;
    private void Scan()
    {
        Scanner cin = new Scanner();
        H = cin.NextInt();
        W = cin.NextInt();
        a = new int[H][];
        for (int i = 0; i < H; i++)
        {
            a[i] = cin.IntArray();
        }
    }

    public int Function(int y, int x)
    {
        if (Dp[Convert(y, x)] != -1)
        {
            return Dp[Convert(y, x)];
        }
        int result = 1;
        if (y > 0)
        {
            if (a[y][x] < a[y - 1][x])
            {
                result += Function(y - 1, x);
                result %= Mod;
            }
        }
        if (x > 0)
        {
            if (a[y][x] < a[y][x - 1])
            {
                result += Function(y, x - 1);
                result %= Mod;
            }
        }
        if (y + 1 < H)
        {
            if (a[y][x] < a[y + 1][x])
            {
                result += Function(y + 1, x);
                result %= Mod;
            }
        }
        if (x + 1 < W)
        {
            if (a[y][x] < a[y][x + 1])
            {
                result += Function(y, x + 1);
                result %= Mod;
            }
        }

        Dp[Convert(y, x)] = result;
        return result;
    }

    private int Convert(int y, int x)
    {
        return y * W + x;
    }

    public void Solve()
    {
        Scan();
        Dp = (new int[H * W]).Select(i => -1).ToArray();
        int ans = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                ans += Function(i, j);
                ans %= Mod;
            }
        }
        Console.WriteLine(ans);
    }

}