using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

using static System.Console;
using static AtCoder.Util;
using static AtCoder.Cin;
using static System.Math;

namespace AtCoder {
    class Program {

        struct RangeEnd : IComparable<RangeEnd> {
            public int Place;
            public int T;

            public RangeEnd(int place, int t) {
                Place = place;
                T = t;
            }
            public int CompareTo(RangeEnd other) => 
                this.Place.CompareTo(other.Place);
        }

        static void Main() {
            var sa = ReadString().ToCharArray().Select(c=> c - 'a').ToList();
            var sb = ReadString().ToCharArray().Select(c=> c - 'a').ToList();
            var sc = ReadString().ToCharArray().Select(c=> c - 'a').ToList();
            var s = new List<Queue<int>> {new Queue<int>(sa), new Queue<int>(sb), new Queue<int>(sc)};
            var player = 0;
            while (true) {
                if (s[player].isEmpty()) {
                    WriteLine((char)('A' + player));
                    return;
                }
                player = s[player].Dequeue();
            }
        }
    }
}
/* ***************** Following Contents are my common library ******** */

namespace AtCoder {
    static class Util {
        public const long MODCONST = 1000000007;

        public static T debug<T>(this T value) {
            Console.Error.WriteLine($"debug:{value}");
            return value;
        }

        public static long ToLong(this String s) => long.Parse(s);
        public static long ToLong(this char c) => c - '0';
        public static int ToInt(this String s) => int.Parse(s);
        public static int ToInt(this char c) => c - '0';
        public static void Times(this int n, Action action) {
            for (int i = 0; i < n; i++) action();
        }
        public static void Times(this long n, Action action) {
            for (long i = 0; i < n; i++) action();
        }
        public static void Call<T>(this T t, Action<T> action) => action(t);
        public static bool In<T>(this T t, IEnumerable<T> range) =>
            range.Contains(t);
        public static void WriteLine<T>(this T t) => Console.WriteLine(t);
        public static T Call<S, T>(this S s, Func<S, T> func) => func(s);
        public static void Each<T>(this IEnumerable<T> e, Action<T> action) {
            foreach (var v in e) action(v);
        }

        public static VectorInt2 ReadVectorInt2() => 
            new VectorInt2(ReadInt(), ReadInt());

        public static string ReplaceX(this string input, string pattern, string replace) =>
            Regex.Replace(input, pattern, replace);

        public static IEnumerable<int> Range(int i, int j) => Enumerable.Range(i, j);
        public static void Swap<T>(this IList<T> enumerable, int i, int j) {
            var buf = enumerable[i];
            enumerable[i] = enumerable[j];
            enumerable[j] = buf;

        }
        public static void ReverseRange<T>(this IList<T> enumerable, int i, int j) {
            int half = (j - i) / 2;
            for (int k = 0; k <= half; k++) enumerable.Swap(i + k, j - k);
        }
        
        public static bool isEmpty<T>(this IEnumerable<T> enumerable) => !enumerable.Any();
    }

    static class Cin {
        private static Queue<string> tokens;
        static Cin () {
            string line;
            tokens = new Queue<string> ();
            while ((line = Console.ReadLine ()) != null) {
                foreach (var token in line.Split (' ')) {
                    tokens.Enqueue (token);
                }
            }
        }

        static public int ReadInt() => int.Parse(tokens.Dequeue());
        static public IEnumerable<int> ReadInt(long n) {
            var list = new List<int>();
            for (int i = 0; i < n; i++) list.Add(ReadInt());
            return list;
        }
        static public long ReadLong() => long.Parse(tokens.Dequeue());
        static public IEnumerable<long> ReadLong(long n) {
            for (int i = 0; i < n; i++) yield return ReadLong();
        }
        static public string ReadString() => tokens.Dequeue();
        static public IEnumerable<string> ReadString(long n) {
            for (int i = 0; i < n; i++) yield return ReadString();
        }
    }

    struct VectorInt2 {
        public int X { get; set; }
        public int Y { get; set; }

        public VectorInt2(int x, int y) {
            X = x; Y = y;
        }

        static public VectorInt2 operator+ (VectorInt2 v1, VectorInt2 v2) =>
            new VectorInt2(v1.X + v2.X, v1.Y + v2.Y);
        static public VectorInt2 operator- (VectorInt2 v1, VectorInt2 v2) =>
            new VectorInt2(v1.X - v2.X, v1.Y - v2.Y);
        static public VectorInt2 operator* (VectorInt2 v1, VectorInt2 v2) =>
            new VectorInt2(v1.X * v2.X, v1.Y * v2.Y);
        static public VectorInt2 operator* (VectorInt2 v1, int i) =>
            new VectorInt2(v1.X * i, v1.Y * i);
        static public VectorInt2 operator* (int i, VectorInt2 v2) =>
            new VectorInt2(i * v2.X, i * v2.Y);
        static public VectorInt2 operator/ (VectorInt2 v1, int i) =>
            new VectorInt2(v1.X / i, v1.Y / i);
    }

    class Maxer<T> where T:IComparable<T> {
        public T Value;

        public Maxer(T t) {
            Value = t;
        }

        public void Max(T other) {
            if (Value.CompareTo(other) < 0) Value = other;
        }
    }
}