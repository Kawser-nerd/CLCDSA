using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

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
            Console.SetIn(new StreamReader("B-small-attempt0.in"));
            Console.SetOut(new StreamWriter("OUT-B.out"));

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
            Console.ReadLine();
#endif
        }

        private static void Do()
        {
            int x, y;
            GetInts(out x, out y);
            string dx = x < 0 ? "EW" : "WE";
            string dy = y < 0 ? "NS" : "SN";

            var ans = new StringBuilder();

            for (int i = 0; i < Math.Abs(x); ++i)
                ans.Append(dx);

            for (int i = 0; i < Math.Abs(y); ++i)
                ans.Append(dy);

            W(ans);
        }

        #region Utils
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