using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        private static int Max(int L, int S, string target)
        {
            if (target.All(c => c == target[0]))
            {
                return S - L + 1;
            }
            else
            {
                int i = L / 2;
                while (i > 0)
                {
                    if (target.Substring(0, i) == target.Substring(L - i)) { break; }
                    --i;
                }
                int j = L - i * 2;
                return (S - i) / (i + j);
            }
        }
        private static double Solve(int K, int L, int S, string keyboard, string target)
        {
            if (target.Any(c => !keyboard.Contains(c))) { return 0; }
            double[] probs = new double[26];
            foreach (char c in keyboard) { probs[c - 'A'] += 1.0; }
            for (int i = 0; i < 26; ++i) { probs[i] /= K; }
            double expectation = 1.0;
            foreach (char c in target) { expectation *= probs[c - 'A']; }
            expectation *= S - L + 1;
            return Max(L, S, target) - expectation;
        }
        static void Main(string[] args)
        {
            string filename = "../B-large";
            var sr = new StreamReader(filename + ".in");
            var sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                var values = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
                string keyboard = sr.ReadLine();
                string target = sr.ReadLine();
                double result = Solve(values[0], values[1], values[2], keyboard, target);
                sw.WriteLine("Case #{0}: {1}", i + 1, result);
                Console.WriteLine("Case #{0}: Done", i + 1);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
