using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.IO;
using System.Linq;
using static System.Math;
using static AtCoder.cin;
// ReSharper disable LoopCanBeConvertedToQuery
// ReSharper disable JoinDeclarationAndInitializer
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
// ReSharper disable UseObjectOrCollectionInitializer
// ReSharper disable TailRecursiveCall
// ReSharper disable RedundantUsingDirective
// ReSharper disable InlineOutVariableDeclaration
#pragma warning disable

namespace AtCoder
{
    public class Program
    {
        private int N;

        private int ans;
        //?????
        void dfs(List<int> people, int at = 0)
        {
            if (N == at)
            {
                //???????????????????
                for (var i = 0; i < people.Count; i++)
                {
                    for (var j = i + 1; j < people.Count; j++)
                    {
                        if (!kankei[people[i]][people[j]])
                            return;
                    }
                }

                ans = Max(people.Count, ans);
                return;
            }

            var people2 = new List<int>(people);
            var people3 = new List<int>(people);
            people3.Add(at);

            at++;
            dfs(people2, at);
            dfs(people3, at);
        }
        
        private bool[][] kankei;

        private void Solve()
        {
            N = cin.ReadInt;
            var M = cin.ReadInt;
            
            kankei = new bool[N][];
            for (int i = 0; i < N; i++)
            {
                kankei[i] = new bool[N];
            }
            for (int i = 0; i < M; i++)
            {
                var x = ReadInt;
                var y = ReadInt;
                x--;
                y--;
                kankei[x][y] = kankei[y][x] = true;
            }
            dfs(new List<int>());
            Console.WriteLine(ans);
        }

        /// <summary>a?b???????</summary>
        static void Swap<T>(ref T a, ref T b) where T : struct
        {
            var tmp = b;
            b = a;
            a = tmp;
        }

        /// <summary>a?b??????????</summary>
        static long Gcd(long a, long b)
        {
            if (a < b) Swap(ref a, ref b);
            return a % b == 0 ? b : Gcd(b, a % b);
        }

        /// <summary>a?b??????????</summary>
        static long Lcm(long a, long b) => a / Gcd(a, b) * b;

        public static void Main(string[] args)
        {
            new Program().Solve();
            Console.Read();
        }

        public static void Print(params object[] args)
        {
            foreach (var s in args)
            {
                Console.WriteLine(s);
            }
        }
    }

    public static class cin
    {
        private const char _separator = ' ';
        private static readonly Queue<string> _input = new Queue<string>();
        private static readonly StreamReader sr =
#if LOCAL
            new StreamReader("in.txt");
#else
            new StreamReader(Console.OpenStandardInput());
#endif

        public static string ReadLine => sr.ReadLine();

        public static string ReadStr => Read;

        public static string Read
        {
            get {
                if (_input.Count != 0) return _input.Dequeue();

                // ReSharper disable once PossibleNullReferenceException
                var tmp = sr.ReadLine().Split(_separator);
                foreach (var val in tmp)
                {
                    _input.Enqueue(val);
                }

                return _input.Dequeue();
            }
        }

        public static int ReadInt => int.Parse(Read);

        public static long ReadLong => long.Parse(Read);

        public static double ReadDouble => double.Parse(Read);

        public static string[] StrArray() => ReadLine.Split(' ');

        public static int[] IntArray() => ReadLine.Split(' ').Select(int.Parse).ToArray();

        public static long[] LongArray() => ReadLine.Split(' ').Select(long.Parse).ToArray();

        public static string[] StrArray(long n)
        {
            var ret = new string[n];
            for (long i = 0; i < n; ++i) ret[i] = Read;
            return ret;
        }

        public static int[] IntArray(long n) => StrArray(n).Select(int.Parse).ToArray();

        public static long[] LongArray(long n) => StrArray(n).Select(long.Parse).ToArray();

        static bool TypeEquals<T, U>() => typeof(T) == typeof(U);
        static T ChangeType<T, U>(U a) => (T)System.Convert.ChangeType(a, typeof(T));

        static T Convert<T>(string s) => TypeEquals<T, int>() ? ChangeType<T, int>(int.Parse(s))
            : TypeEquals<T, long>() ? ChangeType<T, long>(long.Parse(s))
            : TypeEquals<T, double>() ? ChangeType<T, double>(double.Parse(s))
            : TypeEquals<T, char>() ? ChangeType<T, char>(s[0])
            : ChangeType<T, string>(s);

        public static void Multi<T>(out T a) => a = Convert<T>(ReadStr);

        public static void Multi<T, U>(out T a, out U b)
        {
            var ar = StrArray(2);
            a = Convert<T>(ar[0]);
            b = Convert<U>(ar[1]);
        }

        public static void Multi<T, U, V>(out T a, out U b, out V c)
        {
            var ar = StrArray(3);
            a = Convert<T>(ar[0]);
            b = Convert<U>(ar[1]);
            c = Convert<V>(ar[2]);
        }
    }
}