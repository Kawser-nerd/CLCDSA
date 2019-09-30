using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace D
{
    class Program
    {
        static int[] data;
        static int K;
        static string s;
        static int best;
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("D-small.in"))
            {
                using (StreamWriter sw = new StreamWriter("D-small.out"))
                {
                    int N = int.Parse(sr.ReadLine());
                    for (int z = 1; z <= N; z++)
                    {
                        K = int.Parse(sr.ReadLine());
                        s = sr.ReadLine();

                        data = new int[K];
                        temp = new int[K];
                        used = new bool[K];
                        for (int i = 0; i < K; i++)
                        {
                            data[i] = i;
                            used[i] = false;
                        }

                        best = s.Length;
                        permute(0);
                        sw.WriteLine("Case #{0}: {1}", z, best);
                    }
                    sw.Close(); sr.Close();
                }
            }
        }

        static int[] temp;
        static bool[] used;
        private static void permute(int idx)
        {
            if (idx == K)
            {
                char[] res = new char[s.Length];
                for (int i = 0, lim = s.Length; i < lim; i += K)
                {
                    for (int j = 0; j < K; j++)
                    {
                        res[i + j] = s[i + temp[j]];
                    }
                }

                int temp2=1;
                char last = res[0];
                for (int i = 1, lim = res.Length; i < lim; i++)
                {
                    if (res[i] != last)
                    {
                        temp2++;
                        last = res[i];
                    }
                }

                best = Math.Min(best, temp2);
            }
            else
            {

                for (int i = 0; i < K; i++)
                {
                    if (!used[i])
                    {
                        used[i] = true;
                        temp[idx] = i;
                        permute(idx + 1);
                        used[i] = false;
                    }
                }
            }
        }
    }
}
