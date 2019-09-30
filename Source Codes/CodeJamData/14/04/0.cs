using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Globalization.NumberFormatInfo provider = new System.Globalization.NumberFormatInfo() { NumberDecimalSeparator = "." };
            int t;
            string[] lines = System.IO.File.ReadAllLines("input.txt");
            t = Convert.ToInt32(lines[0]);
            string[] answers = new string[t];
            Parallel.For(0, t, new ParallelOptions() { MaxDegreeOfParallelism = 1 }, (num) =>
            {
                int n = Convert.ToInt32(lines[3 * num + 1]);
                List<double> alice = new List<double>();
                List<double> bob = new List<double>();
                foreach (string s in lines[3 * num + 2].Split(' '))
                {
                    alice.Add(Convert.ToDouble(s, provider));
                }
                foreach (string s in lines[3 * num + 3].Split(' '))
                {
                    bob.Add(Convert.ToDouble(s, provider));
                }
                alice.Sort();
                bob.Sort();
                List<bool> bob_used = new List<bool>();
                for (int i = 0; i < n; ++i)
                {
                    bob_used.Add(false);
                }

                int z = 0;
                for (int i = 0; i < n; ++i)
                {
                    int best_b = 0;
                    for (int j = 1; j < n; ++j)
                    {
                        if (bob_used[best_b] || (!bob_used[j] && bob[j] > alice[i] && bob[best_b] < alice[i]))
                        {
                            best_b = j;
                        }
                    }
                    bob_used[best_b] = true;
                    if (alice[i] > bob[best_b])
                    {
                        ++z;
                    }
                }

                int y = 0;
                int p2 = n - 1;
                for (int i = n - 1; i >= 0; --i)
                {
                    if (bob[i] < alice[p2])
                    {
                        ++y;
                        --p2;
                    }
                }
                answers[num] = string.Format("Case #{0}: {1} {2}", num + 1, y, z);
            });
            System.IO.File.WriteAllLines("output.txt", answers);
        }
    }
}
