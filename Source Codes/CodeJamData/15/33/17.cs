using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class Money
    {
        static bool[] test = new bool[31];

        static bool Possible(int[] d, int v)
        {
            for (int i = 0; i <= v; i++) test[i] = false;
            int count = 1 << d.Length;
            int sum;
            for (int i = 0; i < count; i++)
            {
                sum = 0;
                for (int j = 0; j < d.Length; j++)
                    if (((i >> j) & 1) != 0)
                        sum += d[j];
                if (sum > 0 && sum <= v)
                    test[sum] = true;
            }

            for (int i = 1; i <= v; i++)
                if (!test[i])
                    return false;
            return true;
        }

        static bool Possible(int[] d, int v, params int[] n)
        {
            return Possible(d.Union(n).ToArray(), v);
        }

        static int Test(int c, int d, int v, int[] existing)
        {
            // c == 1, v <= 30

            // worst result is 5: 1, 2, 4, 8, 16
            if (Possible(existing, v))
                return 0;

            int best = 10;

            for (int i = 1; i <= 30; i++)
            {
                if (Possible(existing, v, i)) best = Math.Min(best, 1);

                if (best > 1)
                    for (int j = i + 1; j <= 30; j++)
                    {
                        if (Possible(existing, v, i, j)) best = Math.Min(best, 2);

                        if (best > 2)
                            for (int k = j + 1; k <= 30; k++)
                            {
                                if (Possible(existing, v, i, j, k)) best = Math.Min(best, 3);

                                if (best > 3)
                                    for (int m = k + 1; m <= 30; m++)
                                    {
                                        if (Possible(existing, v, i, j, k, m)) best = Math.Min(best, 4);

                                        if (best > 4)
                                            for (int n = m + 1; n <= 30; n++)
                                            {
                                                if (Possible(existing, v, i, j, k, m, n)) best = Math.Min(best, 5);

                                            }
                                    }
                            }
                    }
            }

            return best;
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("money_in.txt");
            int t = int.Parse(lines[0]);
            string[] res = new string[t]; 
            for (int i = 0; i < t; i++)
            {
                int[] vars = lines[i * 2 + 1].Split(' ').Select(str => int.Parse(str)).ToArray();
                int[] noms = lines[i * 2 + 2].Split(' ').Take(vars[1]).Select(str => int.Parse(str)).ToArray();
                res[i] = string.Format("Case #{0}: {1}", i + 1, Test(vars[0], vars[1], vars[2], noms));
                Console.WriteLine("Test #{0} done", i + 1);
            }

            File.WriteAllLines("money_out.txt", res);
        }
    }
}
