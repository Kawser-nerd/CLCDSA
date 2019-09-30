using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class A
{
    static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            int N = ReadInt();
            int[] ds = new int[N], ls = new int[N];
            for (int i = 0; i < N; i++)
            {
                int[] tmp = ReadInts();
                ds[i] = tmp[0];
                ls[i] = tmp[1];
            }
            int D = ReadInt();
            Console.WriteLine("Case #{0}: {1}", t, cando(ds, ls, D) ? "YES" : "NO");
        }
    }

    static bool cando(int[] ds, int[] ls, int D)
    {
        int N = ds.Length;
        int[] ml = new int[N];
        ml[0] = Math.Min(ds[0], ls[0]);
        for (int i = 0; i < N; i++)
        {
            if (ds[i] + ml[i] >= D) return true;
            for (int j = i + 1; j < N; j++)
            {
                if (ds[i] + ml[i] >= ds[j])
                {
                    ml[j] = Math.Max(ml[j], Math.Min(ls[j], ds[j] - ds[i]));
                }
                else
                {
                    break;
                }
            }
        }
        return false;
    }

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }
}
