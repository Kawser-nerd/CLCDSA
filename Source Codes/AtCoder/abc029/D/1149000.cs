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
    Scanner cin = new Scanner();
    private void Scan()
    {
        N = cin.NextInt();
    }

    public void Solve()
    {
        int cnt = 0;
        Scan();
        int j = 1;
        for (int i = 0; i <= 9; i++)
        {
            int p = N / (j * 10)*j;
            cnt += p;
            int ii = N % (j * 10);
            if (ii >= j)
            {

                if (ii / j == 1)
                {
                    cnt += ii % j+1;
                }
                else if (ii / j != 0)
                { 
                    cnt += j;
                }
            }
            j *= 10;
        }
        Console.WriteLine(cnt);
    }
}