using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoroSort
{
    class Program
    {
        String[] input;
        int p = 0;

        double GetDouble()
        {
            return double.Parse(GetString());
        }

        int GetInt()
        {
            return int.Parse(GetString());
        }

        string GetString()
        {
            return input[p++];
        }


        static void Main(string[] args)
        {
            new Program().Run();
        }

        private void Run()
        {
            using (StreamReader sr = new StreamReader("..\\..\\D-large.in"))
            {
                input = sr.ReadToEnd().Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
            }

            using (StreamWriter sw = new StreamWriter("..\\..\\output.txt"))
            {

                int T = GetInt();

                for (int t = 1; t <= T; t++)
                {
                    int N = GetInt();
                    List<int> A = new List<int>(N);
                    while (N-- > 0)
                    {
                        int i = GetInt();
                        A.Add(i);
                    }
                    int ans = Solve(A);
                    sw.WriteLine("Case #{0}: {1:F6}", t, ans);
                }
            }
        }

        private int Solve(List<int> A)
        {
            List<int> B = new List<int>(A);
            B.Sort();
            int N = A.Count, cur = 0, total = 0;
            int[] C = new int[N];
            for (int i = 0; i < N; i++)
            {
                C[i] = B.IndexOf(A[i]);
            }
            bool[] v = new bool[N];
            for (int i = 0; i < N; i++)
            {
                if (!v[i])
                {
                    int j = i;
                    while (!v[j])
                    {
                        v[j] = true;
                        j = C[j];
                        cur++;
                    }
                    total += cur > 1 ? cur : 0;
                    cur = 0;
                }
            }
            return total;
        }
    }
}
