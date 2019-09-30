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
    private int N;
    private int a;
    private string k;
    private int[] b;
    Scanner cin = new Scanner();
    private void Scan()
    {
        N = cin.NextInt();
        a = cin.NextInt();
        k = cin.Next();
        b = cin.IntArray();
    }

    public void Solve()
    {
       
        Scan();

        if (k.Length < 7)
        {
            anser(a,int.Parse(k));
        }
        else
        {
            int next = a;
            var count = (new int[N]).Select(i => -1).ToArray();
            count[a-1] = 0;
            int t=0, l=0;
            for (int i = 1; i <= N; i++)
            {
                next = b[next - 1];
                if (count[next-1] != -1)
                {
                    l = i - count[next-1];
                    t = count[next - 1];
                    break;
                }
                else
                {
                    count[next-1] = i;
                }
            }
            int ll = Mod(k, l);
            while (ll < t)
            {
                ll += l;
            }
            anser(a, ll);
        }
    }

    public void anser(int start,int n)
    {
        int next = start;
        for (int i = 0; i < n; i++)
        {
            next = b[next - 1];
        }
        Console.WriteLine(next);
    }

    public int Mod(string s,int mod)
    {
        int result = 0;

        for (int i = 0; i < s.Length; i++)
        {
            result = (result*10 + s[i] - '0') % mod;
        }

        return result;
    }
}