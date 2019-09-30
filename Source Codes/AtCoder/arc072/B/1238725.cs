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
    public string[] StringArray()
    {
        Next();
        Index = S.Length;
        return S.ToArray();
    }
    public int[] IntArray()
    {
        return StringArray().Select(int.Parse).ToArray();
    }
    public long[] LongArray()
    {
        return StringArray().Select(long.Parse).ToArray();
    }
    public bool EndOfStream
    {
        get { return Sr.EndOfStream; }
    }
}

class Magatro
{
    private long X, Y;
    private void Scan()
    {
        var cin = new Scanner(Console.OpenStandardInput());
        X = cin.NextLong();
        Y = cin.NextLong();
    }

    public void Solve()
    {
        Scan();
        Console.WriteLine(Math.Abs(X - Y) <= 1 ? "Brown" : "Alice");
    }

    private void swap()
    {
        X ^= Y;
        Y ^= X;
        X ^= Y;
    }
}