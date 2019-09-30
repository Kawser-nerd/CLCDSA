using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class ManyPrizes
    {
        static void Main(string[] args)
        {
            new ManyPrizes().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("B-large.in"))
            using (StreamWriter sout = new StreamWriter("B-large.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    long ans = 0;
                    long ans2 = 0;
                    int n = sc.Next<int>();
                    long p = sc.Next<long>();
                    long size = ((long)1) << n;

                    if (p == size)
                    {
                        ans = p - 1;
                        ans2 = p - 1;
                    }
                    else
                    {
                        {
                            long prizeLeft = p;
                            long nextChunk = 2;
                            long increment = size / 2;
                            while (prizeLeft > 1)
                            {
                                prizeLeft -= nextChunk;
                                nextChunk *= 2;
                                ans += increment;
                                increment /= 2;
                                if (ans < 0) throw new Exception("Negative ans");
                                if (nextChunk < 0) throw new Exception("Negative nextChunk");
                            }
                        }
                        {
                            long prizeLeft = p;
                            long nextChunk = size/2;
                            long increment = 2 ;
                            prizeLeft -= nextChunk;
                            while (prizeLeft > 0)
                            {
                                nextChunk /= 2;
                                prizeLeft -= nextChunk;
                                ans2 += increment;
                                increment *= 2;
                                if (ans2 < 0) throw new Exception("Negative ans2");
                                if (nextChunk < 0) throw new Exception("Negative nextChunk");
                            }
                        }
                    }
                    

                    sout.WriteLine("Case #" + (zz) + ": " + ans2 + " " + ans);
                }
            }
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
