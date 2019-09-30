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
    private int N, M, Q;
    private Road[] Roads;
    private Human[] Humans;

    private int[] Par;
    private int[] Size;
    private int[] Anser;
    private void Scan()
    {
        Scanner cin = new Scanner();
        N = cin.Next<int>();
        M = cin.Next<int>();
        Roads = new Road[M];
        for (int i = 0; i < M; i++)
        {
            Roads[i] = new Road(cin.NextInt() - 1, cin.NextInt() - 1, cin.NextInt());
        }
        Q = cin.Next<int>();
        Humans = new Human[Q];
        for (int i = 0; i < Q; i++)
        {
            Humans[i] = new Human(cin.NextInt()-1, cin.NextInt(),i);
        }
    }
    private int Root(int x)
    {
        if (Par[x] == x)
        {
            return x;
        }
        else
        {
            Par[x] = Root(Par[x]);
            return Par[x];
        }
    }

    private bool Same(int x,int y)
    {
        return Root(x) == Root(y);
    }
    private void ParInit()
    {
        Par = new int[N];
        for (int i = 0; i < N; i++)
        {
            Par[i] = i;
        }
    }
    void Union(int x,int y)
    {
        x = Root(x);
        y = Root(y);
        if (x == y) return;
        Par[x] = y;
        int sum = Size[x] + Size[y];
        Size[x] = sum;
        Size[y] = sum;
    }

    public void Solve()
    {
        Scan();
        Array.Sort(Humans, (a, b) => -a.Year.CompareTo(b.Year));
        Array.Sort(Roads, (a, b) => -a.Year.CompareTo(b.Year));
        Anser = new int[Q];
        Size = (new int[N]).Select(a=>1).ToArray();
        ParInit();
        int j = 0;
        for (int i = 0; i < Q; i++)
        {
            for (;j<M&& Roads[j].Year > Humans[i].Year; j++)
            {
                
                Union(Roads[j].X, Roads[j].Y);
            }
            Anser[Humans[i].Index] = Size[Root(Humans[i].City)];
        }
        Console.WriteLine(string.Join("\n", Anser));
    }

}

struct Human
{
    public int Index;
    public int City;
    public int Year;
    public Human(int city,int year,int index)
    {
        City = city;
        Year = year;
        Index = index;
    }
}

struct Road
{
    public int X, Y, Year;
    public Road(int x,int y,int year)
    {
        X = x;
        Y = y;
        Year = year;
    }
}