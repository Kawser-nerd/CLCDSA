using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G3_D
    {
        public static void Main(String[] args)
        {
            string input = @"../../D.in";
            string output = @"../../D.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        sw.WriteLine("Case #{0}: {1}", tc, ls(sr));
                    }
                }
            }
        }

        private static string ls(StreamReader sr)
        {
            string s = sr.ReadLine();            
            int q = 0;
            List<long> idx = new List<long>();
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '?')
                {
                    idx.Add(i);
                    q++;
                }
            }
            long v = 1L << q;
            for (long i = 0; i < v; i++)
            {
                char[] c = s.ToArray();
                for (int j = 0; j < q; j++)
                {
                    c[idx[j]] = ((i & (1 << j)) != 0) ? '1' : '0';
                }
                long r = 0;
                for (long j = 0; j < c.Length; j++)
                {
                    r <<= 1;
                    r += c[j] - '0';
                }
                long p = (long)Math.Sqrt(r + 0.1);
                if (p * p == r)
                    return new string(c);
            }
            return s;
        }

        static void assert(bool v)
        {
            if (!v)
            {
                throw new Exception();
            }
        }
    }
}
