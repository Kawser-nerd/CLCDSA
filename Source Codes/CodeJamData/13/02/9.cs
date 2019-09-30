using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"B-large.in");

            int cases = Int32.Parse(lines[0]);
            var sb = new StringBuilder();

            for (int c = 0, j = 1; c < cases; c++)
            {
                var str = lines[j].Split(new char[] { ' ' });
                int N = int.Parse(str[0]), M = int.Parse(str[1]);

                j++;
                int[,] expected = new int[N, M];
                int[,] actual = new int[N, M];

                for (int i = 0; i < N; i++)
                {
                    var s = lines[j].Split(new char[] { ' ' });

                    for (int i0 = 0; i0 < s.Length; i0++)
                    {
                        expected[i, i0] = Int32.Parse(s[i0]);
                    }

                    j++;
                }

                for (int i = 0; i < N; i++)
                {
                    for (int i0 = 0; i0 < M; i0++)
                    {
                        actual[i, i0] = 100;
                    }
                }

                // rows
                for (int i = 0; i < N; i++)
                {
                    int max = expected[i, 0];

                    for (int i0 = 0; i0 < M; i0++)
                    {
                        if (max < expected[i, i0]) max = expected[i, i0];
                    }

                    for (int i0 = 0; i0 < M; i0++)
                    {
                        actual[i, i0] = max;
                    }
                }

                // columns
                for (int i = 0; i < M; i++)
                {
                    int max = expected[0, i];

                    for (int i0 = 0; i0 < N; i0++)
                    {
                        if (max < expected[i0, i]) max = expected[i0, i];
                    }

                    for (int i0 = 0; i0 < N; i0++)
                    {
                        if (actual[i0, i] > max)
                        {
                            actual[i0, i] = max;
                        }
                    }
                }

                bool ok = true;

                for (int i = 0; i < N; i++)
                {
                    for (int i0 = 0; i0 < M; i0++)
                    {
                        if (expected[i, i0] != actual[i, i0])
                        {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok)
                {
                    string str1 = string.Format("Case #{0}: YES", c + 1);
                    Console.WriteLine(str1);
                    sb.AppendLine(str1);
                }
                else
                {
                    string str1 = string.Format("Case #{0}: NO", c + 1);
                    Console.WriteLine(str1);
                    sb.AppendLine(str1);
                }
            }
            //StringBuilder sb = new StringBuilder();

            //for (int i = 0, j = 1; i < cases; i++)
            //{
            //}

            string result = sb.ToString();
            Console.ReadLine();
        }
    }
}