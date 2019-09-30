using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Net;
using System.Text;
using static System.Math;
// ReSharper disable MemberCanBeMadeStatic.Local
// ReSharper disable PossibleNullReferenceException
// ReSharper disable UnusedMember.Global
// ReSharper disable UnusedMember.Local
// ReSharper disable ArrangeTypeMemberModifiers
// ReSharper disable SuggestVarOrType_BuiltInTypes
// ReSharper disable SuggestVarOrType_Elsewhere
// ReSharper disable InvertIf
// ReSharper disable InconsistentNaming
// ReSharper disable ConvertIfStatementToSwitchStatement

namespace Solve
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
            Console.Read();
        }


        private void Solve()
        {
            var s = cin.Str;

            var ans = "";
            foreach (var c in s)
            {
                if (c == '0' || c == '1') ans += c;
                else if (ans.Any()) ans = ans.Substring(0, ans.Length - 1);
            }

            Console.WriteLine(ans);
        }


        static long Gcd(long a, long b)
        {
            while (true) {
                if (a < b) {
                    var a1 = a;
                    a = b;
                    b = a1;
                    continue;
                }

                if (b > 0) {
                    var a1 = a;
                    a = b;
                    b = a1 % b;
                    continue;
                }
                return a;
            }
        }

        static long Lcm(long a, long b)
        {
            return a / Gcd(a, b) * b;
        }
        
    }

    public struct Point
    {
        public Point(int t, int x, int y)
        {
            X = x;
            Y = y;
            T = t;
        }

        public int X;
        public int Y;
        public int T;
    }


#pragma warning disable IDE1006 // ??????
    public static class cin
#pragma warning restore IDE1006 // ??????
    {
        private const char _separator = ' ';
        private static readonly Queue<string> _input = new Queue<string>();


        public static string ReadLine => Console.ReadLine();

        public static string Str => Read;
        public static string Read
        {
            get {
                if (_input.Count != 0) return _input.Dequeue();

                // ReSharper disable once PossibleNullReferenceException
                var tmp = Console.ReadLine().Split(_separator);
                foreach (var val in tmp) {
                    _input.Enqueue(val);
                }

                return _input.Dequeue();
            }
        }

        public static int Int => int.Parse(Read);

        public static long Long => long.Parse(Read);

        public static double Double => double.Parse(Read);

        public static string[] StrArray(long n)
        {
            var ret = new string[n];
            for (long i = 0; i < n; ++i) ret[i] = Read;
            return ret;
        }

        public static int[] IntArray(long n)
        {
            var ret = new int[n];
            for (long i = 0; i < n; ++i) ret[i] = Int;
            return ret;
        }

        public static long[] LongArray(long n)
        {
            var ret = new long[n];
            for (long i = 0; i < n; ++i) ret[i] = Long;
            return ret;
        }

        static bool TypeEquals<T, U>() => typeof(T) == typeof(U);
        static T ChangeType<T, U>(U a) => (T)System.Convert.ChangeType(a, typeof(T));
        static T Convert<T>(string s) => TypeEquals<T, int>() ? ChangeType<T, int>(int.Parse(s))
            : TypeEquals<T, long>() ? ChangeType<T, long>(long.Parse(s))
            : TypeEquals<T, double>() ? ChangeType<T, double>(double.Parse(s))
            : TypeEquals<T, char>() ? ChangeType<T, char>(s[0])
            : ChangeType<T, string>(s);

        static void Multi<T>(out T a) => a = Convert<T>(Str);
        static void Multi<T, U>(out T a, out U b)
        {
            var ar = StrArray(2); a = Convert<T>(ar[0]); b = Convert<U>(ar[1]);
        }
        static void Multi<T, U, V>(out T a, out U b, out V c)
        {
            var ar = StrArray(3); a = Convert<T>(ar[0]); b = Convert<U>(ar[1]); c = Convert<V>(ar[2]);
        }
    }
}