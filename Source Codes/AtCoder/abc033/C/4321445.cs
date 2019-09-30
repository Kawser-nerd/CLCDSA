using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using static System.Math;
using static AtCoder.Methods;
using static AtCoder.cin;
using Debug = System.Diagnostics.Debug;
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
// ReSharper disable FunctionRecursiveOnAllPaths
#pragma warning disable


namespace AtCoder
{
    public class Program
    {
        private void Solve()
        {
            Console.WriteLine(ReadStr.Split('+').Count(x => !x.Contains('0')));



#if DEBUG
            Solve();
#endif
        }

        private readonly string[] arr = {"dream", "dreamer", "erase", "eraser"};

        
        private readonly int[] dx = {-1, 0, 0, 1};
        private readonly int[] dy = {0, 1, -1, 0};
        private const int MOD = 1000000007;

        /// <summary>a?b???????</summary>
        private static void Swap<T>(ref T a, ref T b) where T : struct
        {
            var tmp = b;
            b = a;
            a = tmp;
        }

        /// <summary>a?b??????????</summary>
        private static long Gcd(long a, long b)
        {
            if (a < b) Swap(ref a, ref b);
            return a % b == 0 ? b : Gcd(b, a % b);
        }

        /// <summary>a?b??????????</summary>
        private static long Lcm(long a, long b) => a / Gcd(a, b) * b;

        public static void Print(params object[] args)
        {
            foreach (var s in args)
            {
                Console.WriteLine(s);
            }
        }

        private static void PrintBool(bool val, string yes = "Yes", string no = "No")
            => Console.WriteLine(val ? yes : no);

        public static void PrintDebug(params object[] args)
            => Console.Error.WriteLine(string.Join(" ", args));

        public static void Main(string[] args)
        {
            new Program().Solve();
            Console.Read();
        }
    }

    public class Pair<T1, T2>
    {
        public Pair(T1 first, T2 second)
        {
            this.first = first;
            this.second = second;
        }

        public T1 first;
        public T2 second;
    }

    public static class Methods
    {
        public static Pair<T1, T2> make_pair<T1, T2>(T1 f, T2 l) => new Pair<T1, T2>(f, l);

        public static Trans Maketrans(string a, string b) => new Trans(a, b);
        public static Trans Maketrans(string a, string b, string c) => new Trans(a, b, c);

        public static string Translate(this string str, Trans trans)
        {
            var s = str;
            for (int i = 0; i < trans.Before.Length; i++)
            {
                if (trans.Delete.Contains(trans.Before[i])) continue;
                s = s.Replace(trans.Before[i], trans.After[i]);
            }

            return s;
        }
        
        /// <summary>
        /// ???????????????????
        /// </summary>
        /// <typeparam name="T">???????</typeparam>
        /// <param name="arr">??????????????????</param>
        /// <param name="start">??????? [inclusive]</param>
        /// <param name="end">??????? [exclusive]</param>
        /// <param name="value">?????</param>
        /// <param name="comparer">????(????????)</param>
        /// <returns>????????????????</returns>
        public static int LowerBound<T>(T[] arr, int start, int end, T value, IComparer<T> comparer)
        {
            int low = start;
            int high = end;
            while (low < high)
            {
                var mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) < 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static int LowerBound<T>(T[] arr, T value) where T : IComparable
        {
            return LowerBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }

        /// <summary>
        /// ?????????????????????
        /// </summary>
        /// <typeparam name="T">???????</typeparam>
        /// <param name="arr">??????????????????</param>
        /// <param name="start">??????? [inclusive]</param>
        /// <param name="end">??????? [exclusive]</param>
        /// <param name="value">?????</param>
        /// <param name="comparer">????(????????)</param>
        /// <returns>??????????????????</returns>
        public static int UpperBound<T>(T[] arr, int start, int end, T value, IComparer<T> comparer)
        {
            int low = start;
            int high = end;
            while (low < high)
            {
                var mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) <= 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static int UpperBound<T>(T[] arr, T value)
        {
            return UpperBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }

        public class Trans
        {

            public Trans(string a, string b)
            {
                if (a.Length != b.Length)
                    throw new ArgumentException($"?? {nameof(a)}?{nameof(b)}????????????????");
                
                Before = a.ToCharArray();
                After = b.ToCharArray();
                Delete = new char[0];
            }

            public Trans(string a, string b, string c) : this(a, b)
            {
                Delete = c.ToCharArray();
            }

            public char[] Before { get; }
            public char[] After { get; }
            public char[] Delete { get; }
        }
    }

    public static class cin
    {
        private const char _separator = ' ';
        private static readonly Queue<string> _input = new Queue<string>();
        private static readonly StreamReader sr =
#if FILE
            new StreamReader("in.txt");
#else
            new StreamReader(Console.OpenStandardInput());
#endif

        public static string ReadLine => sr.ReadLine();

        public static string ReadStr => Read;

        public static string Read
        {
            get
            {
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
        static T ChangeType<T, U>(U a) => (T) System.Convert.ChangeType(a, typeof(T));

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