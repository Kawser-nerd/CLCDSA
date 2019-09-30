using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

using static System.Console;
using static AtCoder.Util;
using static AtCoder.Cin;
using static System.Math;

namespace AtCoder {
    class Program {
        static void Main() {
            var n = ReadInt();
            var s = n.Times(ReadString).ToMultiSet().AsDict();
            var m = ReadInt();
            var t = m.Times(ReadString).ToMultiSet();
            s.Select(pair => pair.Value - t[pair.Key]).Max().Max(0).WriteLine();
        }
    }
}

/* ***************** Following Contents are my common library ******** */

namespace AtCoder {
    static class Util {

        public static MultiSet<T> ToMultiSet<T>(this IEnumerable<T> t) => new MultiSet<T>(t);

        public static int Max(this int i, int j) => i > j ? i : j;

        public static bool IsPalindrome(string s) {
            for (int i = 0; i < s.Length / 2; i++) {
                if (s[i] != s[s.Length - 1 - i]) return false;
            }
            return true;
        }
        public readonly static VectorInt2[] Dir8 = {
            new VectorInt2(-1, -1),
            new VectorInt2(-1, 0),
            new VectorInt2(-1, 1),
            new VectorInt2(0, -1),
            new VectorInt2(0, 1),
            new VectorInt2(1, -1),
            new VectorInt2(1, 0),
            new VectorInt2(1, 1)
        };

        public const long MODCONST = 1000000007;

        public static T debug<T>(this T value) {
            Console.Error.WriteLine($"debug:{value}");
            return value;
        }

        public static T Id<T>(T t) => t;
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

        public static IEnumerable<T> Times<T>(this int n, Func<T> func) {
            for (long i = 0; i < n; i++) yield return func();
        }
        public static IEnumerable<T> Times<T>(this long n, Func<T> func) {
            for (long i = 0; i < n; i++) yield return func();
        }

        public static void Call<T>(this T t, Action<T> action) => action(t);
        public static bool In<T>(this T t, IEnumerable<T> range) =>
            range.Contains(t);
        public static void WriteLine<T>(this T t) => Console.WriteLine(t);
        public static T Call<S, T>(this S s, Func<S, T> func) => func(s);
        public static void Each<T>(this IEnumerable<T> e, Action<T> action) {
            foreach (var v in e) action(v);
        }

        public static IEnumerable<int> FromTo(int a, int b) => Range(a, b - a + 1);
        public static IEnumerable<T> Repeat<T>(T t) {
            while (true) yield return t;
        }
        public static IEnumerable<T> Replicate<T>(int n, T t) => Repeat(t).Take(n);

        public static IEnumerable<T> Cycle<T>(IEnumerable<T> e) {
            while (true)
                foreach (var v in e) yield return v;
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
        static Cin() {
        string line;
        tokens = new Queue<string>();
        while ((line = Console.ReadLine()) != null) {
        foreach (var token in line.Split(' ')) {
        tokens.Enqueue(token);
                }
            }
        }

        static public int ReadInt() => int.Parse(tokens.Dequeue());
        static public IList<int> ReadInt(long n) {
            var list = new List<int>();
            n.Times(() => list.Add(ReadInt()));
            return list;
        }
        static public long ReadLong() => long.Parse(tokens.Dequeue());
        static public IList<long> ReadLong(long n) {
            var list = new List<long>();
            n.Times(() => list.Add(ReadLong()));
            return list;
        }
        static public string ReadString() => tokens.Dequeue();
        static public IList<string> ReadString(long n) {
            var list = new List<string>();
            n.Times(() => list.Add(ReadString()));
            return list;
        }
    }

    struct VectorInt2 {
        public int X { get; set; }
        public int Y { get; set; }

        public VectorInt2(int x, int y) {
            X = x;
            Y = y;
        }

        static public VectorInt2 operator +(VectorInt2 v1, VectorInt2 v2) =>
            new VectorInt2(v1.X + v2.X, v1.Y + v2.Y);
        static public VectorInt2 operator -(VectorInt2 v1, VectorInt2 v2) =>
            new VectorInt2(v1.X - v2.X, v1.Y - v2.Y);
        static public VectorInt2 operator *(VectorInt2 v1, VectorInt2 v2) =>
            new VectorInt2(v1.X * v2.X, v1.Y * v2.Y);
        static public VectorInt2 operator *(VectorInt2 v1, int i) =>
            new VectorInt2(v1.X * i, v1.Y * i);
        static public VectorInt2 operator *(int i, VectorInt2 v2) =>
            new VectorInt2(i * v2.X, i * v2.Y);
        static public VectorInt2 operator /(VectorInt2 v1, int i) =>
            new VectorInt2(v1.X / i, v1.Y / i);
    }

    class Maxer<T> where T : IComparable<T> {
        public T Value;

        public Maxer(T t) {
            Value = t;
        }

        public void Max(T other) {
            if (Value.CompareTo(other) < 0) Value = other;
        }
    }

    class MultiSet<T> : IEnumerable<KeyValuePair<T, int>> {
        Dictionary<T, int> dictionary = new Dictionary<T, int>();

        public MultiSet(IEnumerable<T> data) {
            foreach (var datum in data) {
                if (dictionary.ContainsKey(datum)) {
                    dictionary[datum]++;
                } else {
                    dictionary[datum] = 1;
                }
            }
        }

        public int this [T key] {
            get {
                return dictionary.ContainsKey(key) ? dictionary[key] : 0;
            }
        }
        public MultiSet() {}

        public Dictionary<T, int> AsDict() => dictionary;

        public IEnumerator<KeyValuePair<T, int>> GetEnumerator() => dictionary.GetEnumerator();
        IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();
    }
}