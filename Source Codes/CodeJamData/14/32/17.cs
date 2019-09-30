using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B1
{
    class Program
    {
        static void Main(string[] args)
        {
            int T, t;
            int N;
            string[] sets;
            int count;
            int[] use;
            int[] perm;

            using (StreamReader sr = new StreamReader("B-small-attempt0.in"))
            {
                using (StreamWriter sw = new StreamWriter("B-small-attempt0.out"))
                {
                    T = Convert.ToInt32(sr.ReadLine());

                    for (t = 1; t <= T; t++)
                    {
                        N = Convert.ToInt32(sr.ReadLine());
                        sets = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                        count = 0;
                        use = new int[N];
                        perm = new int[N];
                        Calc(sets, N, use, 0, perm, ref count);

                        sw.WriteLine(String.Format("Case #{0}: {1}", t, count));
                    }

                    sw.Flush();
                    sw.Close();
                }

                sr.Close();
            }
        }

        static void Calc(string[] sets, int N, int[] use, int n, int[] perm, ref int count)
        {
            if (n == N)
            {
                if (Check(sets, perm))
                    count++;
                return;
            }

            for (int i = 0; i < N; i++)
            {
                if (use[i] == 0)
                {
                    use[i] = 1;
                    perm[n] = i;
                    Calc(sets, N, use, n + 1, perm, ref count);
                    use[i] = 0;
                }
            }
        }

        static bool Check(string[] sets, int[] perm)
        {
            int[] letters = new int[26];

            char prev = sets[perm[0]][0];
            letters[prev - 'a'] = 1;

            for (int i = 0; i < perm.Length; i++)
            {
                for (int j = 0; j < sets[perm[i]].Length; j++)
                {
                    if (prev != sets[perm[i]][j])
                    {
                        prev = sets[perm[i]][j];
                        if (letters[prev - 'a'] != 0)
                            return false;

                        letters[prev - 'a'] = 1;
                    }
                }
            }

            return true;
        }
    }
}
