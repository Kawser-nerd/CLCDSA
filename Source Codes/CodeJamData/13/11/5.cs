using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class BullsEye
    {
        static void Main(string[] args)
        {
            new BullsEye().Solve();
        }

        void Solve()
        {
            Stopwatch sw = Stopwatch.StartNew();
            using (StreamReader sc = new StreamReader("A-large.in"))
            using (StreamWriter sout = new StreamWriter("A-large.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    long r = sc.Next<long>();
                    long t = sc.Next<long>();
                    long paint1 = 2*r + 1;

                    BigInteger a = 2;
                    BigInteger b = paint1 - 2;
                    BigInteger c = 0 - t;

                    string ans = (((0 - b) + Sqrt(b*b - 4*a*c))/(2*a)).ToString();

                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
            Console.WriteLine(string.Format("Took {0} ms ", sw.ElapsedMilliseconds));
        }

        private BigInteger Sqrt(BigInteger sq)
        {
            BigInteger lw = 0;
            BigInteger high = sq;

            while(lw <= high)
            {
                BigInteger mid = (lw + high)/2;
                BigInteger m1 = mid + 1;
                if (mid * mid <= sq)
                {
                    if (m1 * m1 > sq) return mid;
                    else lw = mid + 1;
                }
                else high = mid - 1;

            }
            throw new Exception("Root not found");
        }
    }

    public static class Extensions
    {
        public static string Next(this StreamReader sr)
        {
            if (sr.EndOfStream) return null;
            StringBuilder sb = new StringBuilder();
            char ch;
            while (!Char.IsWhiteSpace(ch = (char)sr.Read()))
            {
                sb.Append(ch);
            }
            if (sb.Length == 0) return sr.Next();
            return sb.ToString();
        }

        public static T Next<T>(this StreamReader sr) where T : IConvertible
        {
            string s = sr.Next();
            if (s == null) throw new EndOfStreamException();
            return (T)Convert.ChangeType(s, typeof(T));
        }

        public static string[] nextStrings(this StreamReader sr)
        {
            return sr.ReadLine().Split();
        }

        public static List<T> NextList<T>(this StreamReader sr) where T : IConvertible
        {
            string[] st = sr.ReadLine().Split();
            List<T> ret = new List<T>();
            foreach (string s in st)
                ret.Add((T)Convert.ChangeType(s, typeof(T)));
            return ret;
        }
    }
}
