using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Solver
        {
            private int[] tmp = new int[100];
            private int[] num;
            private string a;
            private string b;

            private bool GreaterOrEqual(string a, string b)
            {
                if (a.Length == b.Length)
                {
                    for (int i = 0; i < a.Length; i++)
                    {
                        if (a[i] != b[i])
                        {
                            return a[i] > b[i];
                        }
                    }
                    return true;
                }
                else
                {
                    return a.Length > b.Length;
                }
            }

            private bool LessOrEqual(string a, string b)
            {
                if (a.Length == b.Length)
                {
                    for (int i = 0; i < a.Length; i++)
                    {
                        if (a[i] != b[i])
                        {
                            return a[i] < b[i];
                        }
                    }
                    return true;
                }
                else
                {
                    return a.Length < b.Length;
                }
            }

            private long Dfs(int index, int length, int total)
            {
                if (total > 9)
                {
                    return 0;
                }
                if (index == length)
                {
                    for (int i = 0; i < num.Length; i++)
                    {
                        tmp[i] = num[i];
                    }
                    int len = num.Length;
                    for (int i = length - 1; i >= 0; i--)
                    {
                        tmp[len++] = num[i];
                    }

                    char[] sqr = new char[2 * len - 1];
                    for (int i = 0; i < len; i++)
                    {
                        if (tmp[i] > 0)
                        {
                            for (int j = 0; j < len; j++)
                            {
                                sqr[i + j] += (char)(tmp[i] * tmp[j]);
                            }
                        }
                    }
                    for (int i = 0; i < sqr.Length; i++)
                    {
                        sqr[i] += '0';
                    }
                    string n = new String(sqr);
                    if (GreaterOrEqual(n, a) && LessOrEqual(n, b))
                    {
                        return 1;
                    }
                    return 0;
                }
                else
                {
                    long res = 0;
                    for (int i = 0; i <= 2; i++)
                    {
                        num[index] = i;
                        res += Dfs(index + 1, length, total + i * i * 2);
                    }
                    return res;
                }
            }

            private long Count(int len, string a, string b)
            {
                this.a = a;
                this.b = b;
                long res = 0;
                if (len == 1)
                {
                    if (GreaterOrEqual("1", a) && LessOrEqual("1", b))
                        res += 1;
                    if (GreaterOrEqual("4", a) && LessOrEqual("4", b))
                        res += 1;
                    if (GreaterOrEqual("9", a) && LessOrEqual("9", b))
                        res += 1;
                }
                else if (len % 2 == 0)
                {
                    this.num = new int[len / 2];
                    for (int i = 1; i <= 2; i++)
                    {
                        num[0] = i;
                        res += Dfs(1, num.Length, i * i * 2);
                    }
                }
                else
                {
                    this.num = new int[len / 2 + 1];
                    for (int i = 1; i <= 2; i++)
                    {
                        for (int j = 0; j <= 2; j++)
                        {
                            num[0] = i;
                            num[num.Length - 1] = j;
                            res += Dfs(1, num.Length - 1, i * i * 2 + j * j);
                        }
                    }
                }
                return res;
            }

            public string Solve(string a, string b)
            {
                if (a[0] == '0' || b[0] == '0')
                {
                    throw new Exception();
                }

                long res = 0;
                for (int i = 1; i <= 50; i++)
                {
                    res += Count(i, a, b);
                }

                return res.ToString();
            }
        }

        static void Main(string[] args)
        {
            //string filename = "sample";
            //string filename = "C-small-attempt0";
            string filename = "C-large-2";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < T; i++)
                    {
                        string[] tmp = reader.ReadLine().Split();
                        writer.WriteLine("Case #" + (i + 1) + ": " + solver.Solve(tmp[0], tmp[1]));
                    }
                }
            }
        }
    }
}
