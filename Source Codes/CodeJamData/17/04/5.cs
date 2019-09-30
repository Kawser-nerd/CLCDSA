using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Numerics;
using System.Linq;


class Program
{

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");

        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            List<string> r = Solution(sr);
            sw.Write("Case #" + (i + 1).ToString() + ": ");
            foreach (var item in r)
            {
                sw.WriteLine(item);
            }
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }



    static void MakeRC(bool[,] RCc, int a, int b, int N)
    {
        for (int i = 0; i < N; i++)
        {
            RCc[a, i] = true;
            RCc[i, b] = true;
        }
    }

    static void MakeDIc(bool[,] DIc, int a, int b, int N)
    {
        for (int i = 0; i < N; i++)
        {
            if (a + i < N)
            {
                if (b + i < N)
                    DIc[a + i, b + i] = true;
                if (b - i >= 0)
                    DIc[a + i, b - i] = true;

            }
            if (a - i >= 0)
            {
                if (b + i < N)
                    DIc[a - i, b + i] = true;
                if (b - i >= 0)
                    DIc[a - i, b - i] = true;
            }
        }
    }


    static List<string> Solution(StreamReader sr)
    {
        string[] t = sr.ReadLine().Split(' ');

        int N = int.Parse(t[0]);
        int M = int.Parse(t[1]);

        bool[,] RC = new bool[N, N];
        bool[,] DI = new bool[N, N];
        bool[,] RCc = new bool[N, N];
        bool[,] DIc = new bool[N, N];

        int points = 0;

        for (int h = 0; h < M; h++)
        {
            t = sr.ReadLine().Split(' ');
            int a = int.Parse(t[1]) - 1;
            int b = int.Parse(t[2]) - 1;
            if (t[0] == "+" || t[0] == "o")
            {
                DI[a, b] = true;
                MakeDIc(DIc, a, b, N);
                points++;
            }
            if (t[0] == "x" || t[0] == "o")
            {
                RC[a, b] = true;
                MakeRC(RCc, a, b, N);
                points++;
            }
        }
        List<int> A = new List<int>();
        List<int> B = new List<int>();
        List<Tuple<int, int>> E = new List<Tuple<int, int>>();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!RCc[i, j])
                {
                    RC[i, j] = true;
                    A.Add(i); B.Add(j);
                    MakeRC(RCc, i, j, N);
                    points++;
                }
                E.Add(Tuple.Create(i, j));
            }
        }
        E.Sort((x, y) =>
        {
            return -Math.Max(Math.Abs((N ) / 2 - x.Item1), Math.Abs((N ) / 2 - x.Item2))
            + Math.Max(Math.Abs((N ) / 2 - y.Item1), Math.Abs((N ) / 2 - y.Item2));
        });
        foreach (var item in E)
        {
            if (!DIc[item.Item1, item.Item2])
            {
                DI[item.Item1, item.Item2] = true;
                A.Add(item.Item1); B.Add(item.Item2);
                MakeDIc(DIc, item.Item1, item.Item2, N);
                points++;
            }
        }

        List<string> res = new List<string>();
        res.Add("");
        for (int i = 0; i < A.Count; i++)
        {
            if (RCc[A[i], B[i]])
            {
                RCc[A[i], B[i]] = false;
                if (RC[A[i], B[i]] && DI[A[i], B[i]])
                {
                    res.Add(string.Format("o {0} {1}", A[i] + 1, B[i] + 1));
                }
                else
                if (RC[A[i], B[i]])
                {
                    res.Add(string.Format("x {0} {1}", A[i] + 1, B[i] + 1));
                }
                else
                if (DI[A[i], B[i]])
                {
                    res.Add(string.Format("+ {0} {1}", A[i] + 1, B[i] + 1));
                }
            }
        }
        res[0] = string.Format("{0} {1}", points, res.Count - 1);
        return res;
    }
}