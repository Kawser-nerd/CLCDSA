using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

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

    public Scanner(Stream source)
    {
        Index = 0;
        S = new string[0];
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

public class UnionFind
{
    private int[] Par;
    private int[] Rank;
    public int Cnt;

    public UnionFind(int n)
    {
        Par = (new int[n]).Select((i, index) => index).ToArray();
        Rank = new int[n];
        Cnt = n;
    }

    public int Root(int a)
    {
        if (Par[a] == a) return a;
        else return Root(Par[a]);
    }

    public bool Same(int a, int b)
    {
        return Root(a) == Root(b);
    }

    public void Union(int a, int b)
    {
        a = Root(a);
        b = Root(b);
        if (a != b)
        {
            Cnt--;
            if (Rank[a] < Rank[b])
            {
                Par[a] = b;
            }
            else
            {
                Par[b] = a;
                if (Rank[a] == Rank[b])
                {
                    Rank[a]++;
                }
            }
        }
    }
}

class Magatro
{
    private int N, M;

    public void Solve()
    {
        Scanner scanner = new Scanner(Console.OpenStandardInput());
        N = scanner.NextInt();
        M = scanner.NextInt();

        UnionFind unionfind = new UnionFind(N);

        for (int i = 0; i < M; i++)
        {
            int x = scanner.NextInt() - 1;
            int y = scanner.NextInt() - 1;

            unionfind.Union(x, y);
        }

        Console.WriteLine(unionfind.Cnt - 1);
    }
}