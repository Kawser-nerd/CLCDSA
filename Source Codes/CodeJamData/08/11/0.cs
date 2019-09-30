using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        const double EPS = 1e-9;

        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            for (int casen = 1; casen <= total; casen++)
            {
                int n = int.Parse(Console.ReadLine());
                List<long> a = new List<long>();
                string[] buf = Split(Console.ReadLine(), ' ');
                foreach (string s in buf) a.Add(long.Parse(s));
                List<long> b = new List<long>();
                buf = Split(Console.ReadLine(), ' ');
                foreach (string s in buf) b.Add(long.Parse(s));

                long result = Calc(a, b);
                Console.WriteLine("Case #{0}: {1}", casen, result);
            }
        }

        static long Calc(List<long> a, List<long> b)
        {
            a.Sort();
            b.Sort();
            b.Reverse();
            long sum = 0;
            for (int i = 0; i < a.Count; i++)
                sum += a[i] * b[i];
            return sum;
        }

        static string[] Split(string str, char ch)
        {
            string[] buf = str.Split(ch);
            List<string> list = new List<string>();
            foreach (string s in buf)
                if (!string.IsNullOrEmpty(s)) list.Add(s);
            return list.ToArray();
        }
    }
}
