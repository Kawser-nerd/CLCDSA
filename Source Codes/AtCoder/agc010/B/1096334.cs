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
        Magatro alice = new Magatro();
        alice.Scan();
        alice.Solve();
    }
}

public class Scanner
{
    private StreamReader Sr;
    private string[] S;
    private int Index;
    private const char Separator = ' ';
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
    private long N;
    private long[] A;
    public void Scan()
    {
        Scanner sc = new Scanner();
        N = sc.NextLong();
        A = sc.LongArray();
    }

    public void Solve()
    {
        long k;
        long w = (N + 1) * N / 2;
        long sum = A.Sum();
        if (sum % w != 0)
        {
            Console.WriteLine("NO");
            return;
        }
        k = sum / w;
        long[] d = new long[N];
        for(int i = 0; i < N; i++)
        {
            d[i] = A[i] - A[(i+1)%N];
        }
        
        d = d.Select(i => i + k).ToArray();
        if (d.Any(i => i < 0))
        {
            Console.WriteLine("NO");
            return;
        }
            long cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (d[i] % N != 0)
            {
                Console.WriteLine("NO");
                return;
            }
            cnt += d[i] / N;
        }
        if (cnt != k)
        {
            Console.WriteLine("NO");
        }
        else
        {
            Console.WriteLine("YES");
        }
    }
}