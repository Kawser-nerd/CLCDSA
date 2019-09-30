using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace AcmSolution
{
    internal class Program
    {
        private static void Main(string[] args)
        {
#if !ACM_HOME
            Do();
#else
            var tmp = Console.In;
            Console.SetIn(new StreamReader("A-large (1).in"));
            Console.SetOut(new StreamWriter("A-LARGE-OUT.out"));

            var tests = GetInt();

            for (int i = 1; i <= tests; ++i)
            {
                W(string.Format("Case #{0}: ", i));
                Do();
                if (i != tests) WL("");
            }

            //while (Console.In.Peek() > 0)
            //{
            //    Do();
            //    //WL("Answer: " + GetStr());
            //}
            Console.In.Close();
            Console.Out.Close();
            Console.SetIn(tmp);
            //Console.ReadLine();
#endif
        }

        private static void Do()
        {
            var aa = GetStrs();
            var s = aa[0];
            int n = int.Parse(aa[1]);
            
            var a = new List<Pair>();

            int cnt = 0;
            int first = 0;
            for (int j = 0; j < s.Length; ++j)
            {
                bool con = (s[j] != 'a' && s[j] != 'e' && s[j] != 'o' && s[j] != 'i' && s[j] != 'u');

                if (con)
                    cnt++;
               
                if ((!con || j == s.Length - 1) && cnt >= n)
                    a.Add(new Pair(first, cnt));

                if (!con)
                {
                    first = j + 1;
                    cnt = 0;
                }
            }

            long ans = 0;

            long left = 0;
            long right = 0;
            long max = s.Length;
            long last = 0;
            for (int i = 0; i < a.Count; ++i)
            {
                left = a[i].first - last;
                right = max - a[i].first - a[i].cnt;

                long a1 = left * right;

                long t = a[i].cnt - n + 1;
                long a2 = (t + 1) * t / 2;

                long a3 = left * (a[i].cnt - n + 1);
                long a4 = right * (a[i].cnt - n + 1); 

                ans += a1 + a2 + a3 + a4;
                
                last = a[i].first + a[i].cnt - n + 1;
            }

            W(ans);// + " " + a.Count);
        }

        #region Utils
        struct Pair
        {
            public long first, cnt;
            public Pair(long b, long i) { first = b; cnt = i; }

            public override string ToString()
            {
                return first + " -- " + cnt;
            }
        };

        private const double Epsilon = 0.00000001;

        private static string GetStr()
        {
            return Console.ReadLine();
        }

        private static string[] GetStrs()
        {
            return GetStr().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] GetStrs(int cnt)
        {
            var s = new string[cnt];
            for (var i = 0; i < cnt; ++i)
                s[i] = GetStr();
            return s;
        }

        private static int GetInt()
        {
            return int.Parse(GetStr());
        }

        private static void GetInts(out int a, out int b)
        {
            var q = GetInts();
            a = q[0];
            b = q[1];
        }

        private static void GetLongs(out long a, out long b)
        {
            var q = GetLongs();
            a = q[0];
            b = q[1];
        }

        private static void GetInts(out int a, out int b, out int c)
        {
            var q = GetInts();
            a = q[0];
            b = q[1];
            c = q[2];
        }

        private static int[] GetInts()
        {
            var s = GetStrs();
            var a = new int[s.Length];
            for (var i = 0; i < s.Length; ++i)
                a[i] = int.Parse(s[i]);
            return a;
        }

        private static long GetLong()
        {
            return long.Parse(GetStr());
        }

        private static long[] GetLongs()
        {
            return GetStrs().Select(long.Parse).ToArray();
        }

        private static void WriteDouble<T>(T d)
        {
            Console.WriteLine(string.Format("{0:0.000000000}", d).Replace(',', '.'));
        }

        private static void WL<T>(T s)
        {
            Console.WriteLine(s);
        }

        private static void W<T>(T s)
        {
            Console.Write(s);
        }

        private static void Assert(bool b)
        {
            if (!b) throw new Exception();
        }

        private static void Swap<T>(ref T a, ref T b)
        {
            var temp = a;
            a = b;
            b = temp;
        }

        #endregion
    }
}