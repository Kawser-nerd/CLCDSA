using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Scanner
{
    private readonly char Separator = ' ';
    private int Index = 0;
    private string[] Line = new string[0];
    public string Next()
    {
        if (Index >= Line.Length)
        {
            Line = Console.ReadLine().Split(Separator);
            Index = 0;
        }
        var ret = Line[Index];
        Index++;
        return ret;
    }

    public int NextInt()
    {
        return int.Parse(Next());
    }

    public long NextLong()
    {
        return long.Parse(Next());
    }

    public string[] StringArray()
    {
        Line = Console.ReadLine().Split(Separator);
        Index = Line.Length;
        return Line;
    }

    public int[] IntArray()
    {
        var l = StringArray();
        var res = new int[l.Length];
        for (int i = 0; i < l.Length; i++)
        {
            res[i] = int.Parse(l[i]);
        }
        return res;
    }

    public long[] LongArray()
    {
        var l = StringArray();
        var res = new long[l.Length];
        for (int i = 0; i < l.Length; i++)
        {
            res[i] = long.Parse(l[i]);
        }
        return res;
    }
}

struct S
{
    public long I;
    public long Last;
    public S(long i, long last)
    {
        this.I = i;
        this.Last = last;
    }
}

class Program
{
    private int N;
    private int[] A;
    private int Cnt = 0;
    private StringBuilder Sb = new StringBuilder();
    private void Scan()
    {
        var sc = new Scanner();
        N = sc.NextInt();
        A = sc.IntArray();
    }

    public void Solve()
    {
        Scan();
        int min = int.MaxValue;
        int max = int.MinValue;
        int minInd = 0;
        int maxInd = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
                maxInd = i;
            }
            if (A[i] < min)
            {
                min = A[i];
                minInd = i;
            }
        }

        if (max >= 0)
        {
            if (min >= 0)
            {
                WritePositive();
            }
            else
            {
                if (max >= (-min))
                {
                    for (int i = 0; i < N; i++)
                    {
                        if (A[i] < 0)
                        {
                            Cnt++;
                            Sb.AppendLine($"{maxInd + 1} {i + 1}");
                        }
                    }
                    WritePositive();
                }
                else
                {
                    for (int i = 0; i < N; i++)
                    {
                        if (A[i] > 0)
                        {
                            Cnt++;
                            Sb.AppendLine($"{minInd + 1} {i + 1}");
                        }
                    }
                    WriteNegative();
                }
            }
        }
        else
        {
            WriteNegative();
        }
    }

    private void WritePositive()
    {
        for (int i = 1; i < N; i++)
        {
            Cnt++;
            Sb.AppendLine($"{i} {i + 1}");
        }
        Console.WriteLine(Cnt);
        Console.Write(Sb.ToString());
    }

    private void WriteNegative()
    {
        for (int i = N - 1; i >= 1; i--)
        {
            Cnt++;
            Sb.AppendLine($"{i + 1} {i}");
        }
        Console.WriteLine(Cnt);
        Console.Write(Sb.ToString());
    }

    static void Main(string[] args)
    {
        new Program().Solve();
    }
}