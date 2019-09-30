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
    private Scanner Cin;
    private int Ax, Ay, Bx, By;
    private int N;
    private int[] x, y;
    private void Scan()
    {
        Cin = new Scanner();
        Ax = Cin.NextInt();
        Ay = Cin.NextInt();
        Bx = Cin.NextInt();
        By = Cin.NextInt();
        N = Cin.NextInt();
        x = new int[N];
        y = new int[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = Cin.NextInt();
            y[i] = Cin.NextInt();
        }
    }

    public void Solve()
    {
        Scan();
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (kousa(Ax, Ay, Bx, By, x[i], y[i], x[(i + 1) % N], y[(i + 1) % N])) count++;
        }
        Console.WriteLine(count / 2 + 1);
    }

    private bool kousa(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
    {
        double ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
        double tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
        double tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
        double td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
        return tc * td < 0 && ta * tb < 0;
    }
}