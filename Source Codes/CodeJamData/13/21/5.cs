using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static StreamReader sr = new StreamReader("input.txt");
        static StreamWriter sw = new StreamWriter("output.txt");

        static List<List<string>> tests = new List<List<string>>();
        static List<string>[] answers;

        static List<string> ReadTest()
        {
            List<string> ans = new List<string>();
            ans.Add(sr.ReadLine());
            ans.Add(sr.ReadLine());
            return ans;
        }

        static void Run(int p)
        {
            string[] parts = tests[p][0].Split(' ');
            int a = Convert.ToInt32(parts[0]);
            int n = Convert.ToInt32(parts[1]);
            parts = tests[p][1].Split(' ');
            List<int> l = new List<int>();
            for (int i = 0; i < n; ++i)
            {
                l.Add(Convert.ToInt32(parts[i]));
            }
            l.Sort();
            int ans = int.MaxValue;
            int already = 0;
            bool flag = true;
            for (int i = 0; i < n; ++i)
            {
                if (a <= l[i])
                {
                    ans = Math.Min(ans, already + n - i);
                    if (a == 1)
                    {
                        flag = false;
                        break;
                    }
                    while (a <= l[i])
                    {
                        ++already;
                        a += a - 1;
                    }
                }
                a += l[i];
            }
            if (flag)
            {
                ans = Math.Min(ans, already);
            }
            answers[p] = new List<string>();
            answers[p].Add(ans.ToString());            
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
            ParallelOptions po = new ParallelOptions();
            po.MaxDegreeOfParallelism = 8;
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
