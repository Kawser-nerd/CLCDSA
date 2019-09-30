using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2013_0
{
    class GCJ2013_1AA
    {
        const string fileName = "A-large";
        const string inputFile = fileName + ".in";
        const string outputFile = fileName + ".out";
        StreamReader reader = new StreamReader(inputFile);
        StreamWriter writer = new StreamWriter(outputFile);

        long Check(long x, long r, long t)
        {
            return (t - (x * x * 2 + x * (r * 2 - 1)));
        }

        long Solve(long r, long t)
        {
            long x = 1;
            while (Check(x, r, t) > 0) x *= 2;
            long left, right, mid, check;
            left = x / 2;
            right = x;
            while (right > left)
            {
                mid = (left + right) / 2;
                check = Check(mid, r, t);
                if (check == 0) return mid;
                else if (check > 0) left = mid + 1;
                else right = mid;
            }
            if (Check(left, r, t) == 0) return left;
            else return left - 1;
        }

        public GCJ2013_1AA()
        {
            char[] sep = { ' ' };
            int T = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] s = reader.ReadLine().Split(sep);
                long r, t;
                r = Int64.Parse(s[0]);
                t = Int64.Parse(s[1]);
                writer.WriteLine(String.Format("Case #{0}: {1}", (i + 1), Solve(r,t)));
            }

            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            new GCJ2013_1AA();
        }
    }
}
