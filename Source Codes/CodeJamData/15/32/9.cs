using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines(@"../../B-large.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                var digits = inputs[x * 3 + 1].Split(' ').Select(int.Parse).ToArray();
                int K = digits[0];
                int L = digits[1];
                int S = digits[2];
                string keys = inputs[x * 3 + 2];
                string target = inputs[x * 3 + 3];
                if (IsPossible(keys, target))
                {
                    double worst = WorstCase(target, S, L);
                    double ave = Average(target, keys, S, L, K);
                    outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, worst - ave));
                }
                else
                {
                    outputs.AppendLine(string.Format("Case #{0}: 0", x + 1));
                }
            }

            File.WriteAllText(@"../../large.out", outputs.ToString());
        }

        static bool IsPossible(string keys, string target)
        {
            var k = keys.ToCharArray().Distinct();
            var t = target.ToCharArray().Distinct();
            var rem = t.Except(k);
            return !rem.Any();
        }

        static int Overlap(string target)
        {
            var t = target.ToCharArray();
            int count = 0;
            for (int i = 1; i < t.Length; i++)
            {
                bool overlap = true;
                for (int j = 0; j < t.Length - i; j++)
                {
                    if (t[j] != t[j + i])
                    {
                        overlap = false;
                        break;
                    }
                }
                if (overlap)
                {
                    count = t.Length - i;
                    break;  
                }
            }
            return count;
        }

        static double WorstCase(string target, int S, int L)
        {
            int overlap = Overlap(target);
            int banana = (S - L) / (L - overlap) + 1;
            return (double)banana;
        }

        static Dictionary<char, int> Histogram(string keys)
        {
            var h = new Dictionary<char, int>();
            foreach (var k in keys)
            {
                if (h.ContainsKey(k))
                {
                    h[k] = h[k] + 1;
                }
                else
                {
                    h[k] = 1;
                }
            }
            return h;
        }

        static double Average(string target, string keys, int S, int L, int K)
        {
            var h = Histogram(keys);
            double initial = 1;
            foreach (var k in target)
            {
                initial *= h[k];
                initial /= K;
            }
            var cache = new double[Math.Max(2, S - L + 1)];
            cache[0] = initial;
            cache[1] = initial * 2;
            for (int i = 2; i < cache.Length; i++)
            {
                cache[i] = 2 * cache[i - 1] - cache[i - 2];
            }
            return cache[S - L];
        }
    }
}
