using System;
using System.Globalization;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static StreamReader sr = new StreamReader("input.txt");
        static StreamWriter sw = new StreamWriter("output.txt");

        static NumberFormatInfo provider = new NumberFormatInfo() { NumberDecimalSeparator = "."};

        static List<List<string>> tests = new List<List<string>>();
        static List<string>[] answers;

        static List<string> ReadTest()
        {
            List<string> ans = new List<string>();
            ans.Add(sr.ReadLine());
            return ans;
        }

        static void Run(int p)
        {
            string[] parts = tests[p][0].Split(' ');
            int n = Convert.ToInt32(parts[0]);
            int x = Convert.ToInt32(parts[1]);
            int y = Convert.ToInt32(parts[2]);
            if (x < 0)
            {
                x = -x;
            }
            int num_line = (x + y) / 2;
            int full = -1;
            while (((full + 2) * (full + 2) + (full + 2)) / 2 <= n)
            {
                full = full + 2;
            }
            n = n - (full * full + full) / 2;
            full = (full + 1) / 2;
            answers[p] = new List<string>();
            if (full > num_line)
            {
                answers[p].Add("1.0");
                return;
            }
            if (full < num_line)
            {
                answers[p].Add("0.0");
                return;
            }
            double[] prb = new double[full * 2 + 1];
            prb[0] = 1;
            for (int i = 0; i < n; ++i)
            {
                double[] new_prb = new double[full * 2 + 1];
                if (i - full * 2 >= 0)
                {
                    new_prb[i - full * 2 + 1] += prb[i - full * 2];
                }
                for (int j = Math.Max(0, i - full * 2 + 1); j < full * 2; ++j)
                {
                    new_prb[j] += prb[j] / 2;
                    new_prb[j + 1] += prb[j] / 2;
                }
                new_prb[full * 2] += prb[full * 2];
                prb = new_prb;
            }
            double ans = 0;
            for (int i = y + 1; i < full * 2 + 1; ++i)
            {
                ans += prb[i];
            }
            answers[p].Add(ans.ToString(provider));
        }

        static void Out(int p)
        {
            sw.WriteLine("Case #" + (p + 1).ToString() + ": " + answers[p][0]);
        }

        static void Main(string[] args)
        {
            sr.ReadLine();
            while (!sr.EndOfStream)
            {
                tests.Add(ReadTest());
            }
            answers = new List<string>[tests.Count];
            ParallelOptions po = new ParallelOptions() { MaxDegreeOfParallelism = 8 };
            Parallel.For(0, tests.Count, po, Run);
            for (int i = 0; i < answers.Count(); ++i)
            {
                Out(i);
            }
            sw.Flush();
            sw.Close();
        }
    }
}
