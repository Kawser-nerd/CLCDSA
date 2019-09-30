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
        var alice = new Magatro();
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
    private int X;
    public void Scan()
    {
        Scanner cin = new Scanner();
        X = cin.NextInt();
    }

    public void Solve()
    {
        int sum = 0;
        for (int i = 1; i < 100000; i++)
        {
            sum += i;
            if (X <= sum)
            {
                Console.WriteLine(i);
                return;
            }
        }
    }

}