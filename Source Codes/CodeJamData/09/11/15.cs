using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using gcj;

namespace GoogleCodeJam
{
    class Round1AQ1 : Round
    {
        public void Solve(string filePath)
        {
            string source = File.ReadAllText(filePath);
            string[] lines = source.Split(new char[] {'\r', '\n'}, StringSplitOptions.RemoveEmptyEntries);

            StringBuilder sb = new StringBuilder();
            StringWriter sw = new StringWriter(sb);

            for (int i = 1; i < lines.Length; ++i)
            {
                string[] words = lines[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int[] bases = new int[words.Length];
                for (int j = 0; j < bases.Length; ++j)
                    bases[j] = Convert.ToInt32(words[j]);

                long test = 2;
                while (!isHappy(test, bases))
                    test++;

                sw.WriteLine(string.Format("Case #{0}: {1}", i, test));
            }

            using (StreamWriter writer = new StreamWriter(File.OpenWrite("out.txt")))
                writer.Write(sb.ToString());
        }

        private bool isHappy(long n, int[] bs)
        {
            foreach (int b in bs)
                if (!isHappy(n, b, n, new List<long>(), true))
                    return false;

            return true;
        }

        private bool isHappy(long n, int b, long ori, List<long> repeat, bool isFirst)
        {
            if (n == ori && !isFirst)
                return false;

            long m = 0;

            while (n > 0)
            {
                long tmp = n < b ? n : n - n / b * b;
                n = n / b;
                m += tmp * tmp;
            }

            if (m == 1)
                return true;
            else if (repeat.Contains(m))
                return false;
            else
            {
                repeat.Add(m);
                return isHappy(m, b, ori, repeat, false);
            }
        }
    }
}
