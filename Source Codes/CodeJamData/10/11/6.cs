using System;
using System.IO;

namespace Rotate
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"A-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int K = int.Parse(s[1]);

            char[,] t = new char[N,N];

            for (int i = 0; i < N; i++)
            {
                string ss = reader.ReadLine();
                ss = ss.Replace(".", "");

                for (int j = 0; j < N; j++)
                {
                    if (j == ss.Length)
                        break;

                    t[i, N - 1 - j] = ss[ss.Length - j - 1];
                }
            }

            string rfind = new string('R', K);
            string bfind = new string('B', K);

            bool fr = false;
            bool fb = false;

            for (int i = 0; i < N; i++)
            {
                char[] sl1 = new char[N];
                char[] sl2 = new char[N];
                for (int j = 0; j < N; j++)
                {
                    sl1[j] = t[i, j];
                    sl2[j] = t[j, i];
                }

                string s1 = new string(sl1);
                string s2 = new string(sl2);

                if (!fr && s1.IndexOf(rfind) != -1)
                    fr = true;

                if (!fr && s2.IndexOf(rfind) != -1)
                    fr = true;

                if (!fb && s1.IndexOf(bfind) != -1)
                    fb = true;

                if (!fb && s2.IndexOf(bfind) != -1)
                    fb = true;

                if (fr && fb)
                    break;
            }

            if (fr && fb)
            {
            }
            else
            {
                for (int i = K - 1; i < 2*N - K; i++)
                {
                    char[] sl1 = new char[Math.Min(i + 1, 2*N - i - 1)];
                    char[] sl2 = new char[Math.Min(i + 1, 2*N - i - 1)];

                    int x1b = Math.Min(i, N - 1);
                    int x2b = Math.Max(0, N - i - 1);
                    int dy = x2b==0? -N + i + 1 :0;

                    for (int j = 0; j < sl1.Length; j++)
                    {
                        sl1[j] = t[x1b - j, i - x1b + j];
                        sl2[j] = t[x2b + j, j + dy];
                    }

                    string s1 = new string(sl1);
                    string s2 = new string(sl2);

                    if (!fr && s1.IndexOf(rfind) != -1)
                        fr = true;

                    if (!fr && s2.IndexOf(rfind) != -1)
                        fr = true;

                    if (!fb && s1.IndexOf(bfind) != -1)
                        fb = true;

                    if (!fb && s2.IndexOf(bfind) != -1)
                        fb = true;

                    if (fr && fb)
                        break;
                }
            }


            Console.WriteLine("Case #{0}: {1}", C, (fr && fb) ? "Both" : (fr ? "Red" : (fb ? "Blue" : "Neither")));
            writer.WriteLine("Case #{0}: {1}", C, (fr && fb) ? "Both" : (fr ? "Red" : (fb ? "Blue" : "Neither")));
        }
    }
}