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
    private int N;
    private long[] A;
    private void Scan()
    {
        var cin = new Scanner(Console.OpenStandardInput());
        N = cin.NextInt();
        A = cin.LongArray();
    }

    public void Solve()
    {
        Scan();

        long plusCnt;
        long minusCnt;

        long plusV;
        long minV;
        if (A[0] > 0)
        {
            plusCnt = 0;
            minusCnt = A[0] + 1;
            plusV = A[0];
            minV = -1;
        }
        else if (A[0] < 0)
        {
            plusCnt = -A[0] + 1;
            minusCnt = 0;
            plusV = 1;
            minV = A[0];
        }
        else
        {
            plusCnt = 1;
            minusCnt = 1;
            plusV = 1;
            minV = -1;
        }


        for(int i = 1; i < N; i++)
        {
            long nexPV;
            long nexPC;
            //plus
            if (minV + A[i] > 0)
            {
                nexPV = A[i] + minV;
                nexPC = minusCnt;
            }
            else
            {
                nexPV = 1;
                nexPC =minusCnt+ 1 - (minV + A[i]);
            }

            long nexMV;
            long nexMC;
            //minus
            if (plusV + A[i] < 0)
            {
                nexMV = A[i] + plusV;
                nexMC = plusCnt;
            }
            else
            {
                nexMV = -1;
                nexMC = plusCnt+1 + (plusV + A[i]);
            }

            minV = nexMV; 
            minusCnt = nexMC;
            plusV = nexPV;
            plusCnt = nexPC;

        }

        Console.WriteLine(Math.Min(plusCnt, minusCnt));
    }
}