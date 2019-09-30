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
    static void Main(string[]args)
    {
        Magatro m = new Magatro();
        m.Scan();
        m.Solve();
    }
}

public class Scanner
{
    private StreamReader Sr;
    private string[] S;
    private int Index;

    private const char Separator=' ';

    public Scanner()
    {
        Index = 0;
        S = new string[0];
        Sr = new StreamReader(Console.OpenStandardInput());
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
    public long[]LongArray(int index = 0)
    {
        return StringArray(index).Select(long.Parse).ToArray();
    }

    public bool ScanToEnd(ref string s)
    {
        if (Sr.EndOfStream)
        {
            return false;
        }
        else
        {
            s = Sr.ReadLine();
            return true;
        }
    }
}

public class Magatro
{
    private long N;
    private long A, B;

    private long[] X;

    public void Scan()
    {
        Scanner sc = new Scanner();
        N = sc.NextInt();
        A = sc.NextInt();
        B = sc.NextInt();
        X = sc.LongArray();
    }

    public void Solve()
    {
        long ans = 0;
        for (int i = 0; i < N-1; i++)
        {
            ans += Math.Min(B, (X[i+1] - X[i]) * A);
        }

        Console.WriteLine(ans);
    }
}