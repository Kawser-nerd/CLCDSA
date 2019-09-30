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
    private Dictionary<char, string> Map;
    private int N;
    private string[] S;
    private void Scan()
    {
        N = cin.NextInt();
        S = cin.StringArray();
    }

    private void MapInit()
    {
        Map = new Dictionary<char, string>();
        for (char c = 'a'; c <= 'z'; c++)
        {
            Map.Add(c, "");
        }
        for (char c = 'A'; c <= 'Z'; c++)
        {
            Map.Add(c, "");
        }
        Map.Add('.', "");
        Map.Add(',', "");
        AddMap('b', "1");
        AddMap('c', "1");
        AddMap('d', "2");
        AddMap('w', "2");
        AddMap('t', "3");
        AddMap('j', "3");
        AddMap('f', "4");
        AddMap('q', "4");
        AddMap('l', "5");
        AddMap('v', "5");
        AddMap('s', "6");
        AddMap('x', "6");
        AddMap('p', "7");
        AddMap('m', "7");
        AddMap('h', "8");
        AddMap('k', "8");
        AddMap('n', "9");
        AddMap('g', "9");
        AddMap('z', "0");
        AddMap('r', "0");
    }

    private void AddMap(char c, string s)
    {
        Map[c] = s;
        Map[(char)(c - 'a' + 'A')] = s;
    }

    public void Solve()
    {
        Scan();
        MapInit();
        var ans = S.Select(Func).Where(s => s != "").ToArray();
        Console.WriteLine(string.Join(" ", ans));
    }

    private string Func(string s)
    {
        return string.Join("", s.ToArray().Select(c => Map[c]).ToArray());
    }
}