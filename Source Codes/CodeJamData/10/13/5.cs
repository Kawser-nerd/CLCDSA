using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;

struct Point : IEquatable<Point>
{
    public int X; public int Y;
    public Point(int x, int y) { X = x; Y = y; }
    public bool Equals(Point p) { return p.X == X && p.Y == Y; }
    public override int GetHashCode() { return (int)(X * 3137 + Y); }
}

class Problem
{
    const string inFile = "..\\..\\csmall.in";
    const string outFile = "..\\..\\csmall.out";

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++)
                {
                    int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                    int A1 = ss[0];
                    int A2 = ss[1];
                    int B1 = ss[2];
                    int B2 = ss[3];

                    string res = Solve(A1, A2, B1, B2);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }

                //int[,] state = calc(50);
                //for (int i = 1; i < 50; i++)
                //{
                //    for (int j = i; j < 50; j++)
                //    {
                //        sw.WriteLine("{0} {1} = {2}", i, j, state[i, j]);
                //    }
                //    sw.WriteLine();
                //}
            }
        }
    }

    Dictionary<Point, bool> f;

    bool calc(int A, int B)
    {
        if (A == B) return false;

        if (A < B)
        {
            int temp = A;
            A = B;
            B = temp;
        }

        Point p = new Point(A, B);
        if (f.ContainsKey(p)) return f[p];

        bool hasLose = false;
        int T = A / B;
        for (int k = 1; k <= T; ++k)
        {
            int C = A - k * B;
            if (C > 0)
            {
                bool temp = calc(C, B);
                if (temp == false)
                {
                    hasLose = true;
                }
            }
        }

        return f[p] = hasLose;
    }

    private string Solve(int A1, int A2, int B1, int B2)
    {
        f = new Dictionary<Point,bool>();

        int T = Math.Max(B2, A2);
        T = Math.Max(T, 10);

        int[] max = new int[T + 1];
        max[1] = 1;
        max[2] = 3;
        for (int i = 3; i <= T; i++)
        {
            int k = max[i - 1]+1;
            while (true)
            {
                k = k + 1;

                int C = k - i;
                if (max[C] >= i) break;
            }
            max[i] = k-1;
        }

        int res = 0;
        for (int i = A1; i <= A2; i++)
        {
            int C = max[i];
            if (C < B2)
            {
                res += (B2 - C) - Math.Max(0, B1 - 1 - C);
            }
        }


        int res2 = 0;
        for (int i = B1; i <= B2; i++)
        {
            int C = max[i];
            if (C < A2)
            {
                res += (A2 - C) - Math.Max(0, A1 - 1 - C);
            }
        }
        return (res + res2).ToString();
    }

    private int[,] calc(int n)
    {
        int[,] state = new int[n, n];

        for (int i = 1; i < n; i++)
        {
            state[i, i] = -1;
        }

        bool gotNew = false;
        while (true)
        {
            gotNew = false;
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (state[i, j] == 0)
                    {
                        bool gotWin = false, gotLose = false, gotUnknown = false;
                        if (i > j)
                        {
                            for (int k = 1; k <= i / j; k++)
                            {
                                int c = i - k * j;
                                if (c == 0) continue;
                                if (state[c, j] == 1)
                                {
                                    gotWin = true;
                                }
                                else if (state[c, j] == -1)
                                {
                                    gotLose = true;
                                }
                                else
                                {
                                    gotUnknown = true;
                                }
                            }
                        }
                        else if (i < j)
                        {
                            for (int k = 1; k <= j / i; k++)
                            {
                                int c = j - k * i;
                                if (c == 0) continue;
                                if (state[i, c] == 1)
                                {
                                    gotWin = true;
                                }
                                else if (state[i, c] == -1)
                                {
                                    gotLose = true;
                                }
                                else
                                {
                                    gotUnknown = true;
                                }
                            }
                        }

                        if (!gotUnknown)
                        {
                            if (gotLose)
                            {
                                state[i, j] = 1;
                            }
                            else
                            {
                                state[i, j] = -1;
                            }
                            gotNew = true;
                        }
                    }
                }
            }
            if (!gotNew) break;
        }

        return state;
    }

   

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}