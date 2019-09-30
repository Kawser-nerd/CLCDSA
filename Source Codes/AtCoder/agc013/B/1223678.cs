using System;
using System.Collections.Generic;
using System.Linq;
using System.Collections;
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

    public Scanner(Stream stream)
    {
        Index = 0;
        S = new string[0];
        Sr = new StreamReader(stream);
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
    private int N, M;
    private List<int>[] Con;
    bool[] b;
    private void Scan()
    {
        Scanner scanner = new Scanner(Console.OpenStandardInput());
        N = scanner.NextInt();
        M = scanner.NextInt();
        Con = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            Con[i] = new List<int>();
        }
        for (int i = 0; i < M; i++)
        {
            int a = scanner.NextInt();
            int b = scanner.NextInt();
            Con[a - 1].Add(b - 1);
            Con[b - 1].Add(a - 1);
        }
    }

    public void Solve()
    {
        Scan();
        b = new bool[N];
        b[0] = true;
        var one = F();
        var two = F();
        two.Reverse();
        for(int i = 1; i < one.Count; i++)
        {
            two.Add(one[i]);
        }
        Console.WriteLine(two.Count);
        Console.WriteLine(string.Join(" ", two.Select(i=>i+1).ToArray()));
    }

    private List<int> F()
    {
        List<int> res = new List<int>();
        res.Add(0);
        int pos = 0;
        while (true)
        {
            bool flag = false;
            foreach(int i in Con[pos])
            {
                if (!b[i])
                {
                    pos = i;
                    res.Add(i);
                    b[i] = true;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        return res;
    }
}