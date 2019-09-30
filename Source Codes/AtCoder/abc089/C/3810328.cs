using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

//using static System.Linq.Enumerable;
using static System.Console;
using static AtCoder.Util;
using static AtCoder.Cin;
using static System.Math;
using static AtCoder.MyMath;
using static AtCoder.StreamExtensions;
using static AtCoder.Matrix;

namespace AtCoder {
    using VI = VectorInt2;

    static class Program {
        static void Main() {
            var n = ReadInt();
            var people = ReadString(n).Select(x => x[0]).ToMultiSet();
            (
                people['R'] * people['C'] * people['H']
                + people['A'] * people['C'] * people['H']
                + people['A'] * people['R'] * people['H']
                + people['A'] * people['R'] * people['C']
                + people['M'] * people['C'] * people['H']
                + people['M'] * people['R'] * people['H']
                + people['M'] * people['R'] * people['C']
                + people['M'] * people['A'] * people['H']
                + people['M'] * people['A'] * people['C']
                + people['M'] * people['A'] * people['R']
            ).WriteLine();

        }
    }
}
/* ***************** Following Contents are my common library ******** */

namespace AtCoder {
    static class Algorithm {

        public static LongRange BinSearch(LongRange range, Func<long, bool> isBigger, long width) => BinSearch(range, isBigger, x => range.Right - range.Left < width);
        public static LongRange BinSearch(LongRange range, Func<long, bool> isBigger, Func<LongRange, bool> stopCondition) {
            if (stopCondition(range)) return range;
            var middle = range.Left + (range.Right - range.Left) / 2;
            return isBigger(middle) ? BinSearch(new LongRange(range.Left, middle), isBigger, stopCondition)
                : BinSearch(new LongRange(middle, range.Right), isBigger, stopCondition);

        }
    }

    static class MyMath {

        public static long GCD(long a, long b) =>
            a < b ? GCD(b, a)
            : b > 0 ? GCD(b, a % b)
            : a;
        public static long GCD(this IEnumerable<long> source) => source.Aggregate(GCD);

        public static long LCM(long a, long b) {
            var g = GCD(a, b);
            var a1 = a / g;
            var b1 = b / g;
            return g * a1 * b1;
        }
        public static long LCM(this IEnumerable<long> source) => source.Aggregate(LCM);

        public static long Factorial(this long n) => Range(1, n).Aggregate(1L, Multiply);
        public static long nPr(int n, int r) => r < 0 || r > n ? 0 : FromTo(n - r + 1, n).Select(x => (long) x).Aggregate(1L, Multiply);
        public static long nCr(int n, int r) => nPr(n, r) / Factorial(r);

        public static long Inc(long i) => i + 1;
        public static long Dec(long i) => i - 1;
        public static long Plus(long i, long j) => i + j;
        public static Func<long, long> Plus(long j) => i => i + j;
        public static long Minus(long i, long j) => i - j;
        public static Func<long, long> Minus(long j) => i => i - j;
        public static long Multiply(long i, long j) => i * j;
        public static Func<long, long> Multiply(long j) => i => i * j;
        public static long Divide(long i, long j) => j / j;
        public static Func<long, long> Divide(long j) => i => i * j;
        public static long Mod(long i, long j) => i % j;
        public static Func<long, long> Mod(long j) => i => i % j;

        public static long Max(params long[] ns) => ns.Max();

        public static long LowerBound(this long m, long lbound) => Max(m, lbound);
        public static long UpperBound(this long m, long ubound) => Min(m, ubound);
        public static long Bound(this long m, long lowerBound, long UpperBound) => m.LowerBound(lowerBound).UpperBound(UpperBound);

        public static long LowerBound(this int m, long lbound) => Max(m, lbound);
        public static long UpperBound(this int m, long ubound) => Min(m, ubound);
        public static long Bound(this int m, long lowerBound, long UpperBound) => m.LowerBound(lowerBound).UpperBound(UpperBound);

        public static bool InRange(this long x, long min, long max) => min <= x && x <= max;
        public static bool IsEven(this int x) => x % 2 == 0;
        public static bool IsOdd(this int x) => x % 2 != 0;
        public static bool IsEven(this long x) => x % 2 == 0;
        public static bool IsOdd(this long x) => x % 2 != 0;

        public static IEnumerable<int> ToDigits(this long n) =>
            n.ToString().Select(x => x.ToInt());
        public static IEnumerable<int> ToDigits(this int n) => ((long) n).ToDigits();

        public static IEnumerable<int> Factors(this int n) {
            for (int i = 1; i <= n; i++)
                if (n % i == 0) yield return i;
        }

        public static IEnumerable<long> Factors(this long n) {
            for (long i = 1; i <= n; i++)
                if (n % i == 0) yield return i;
        }

        public static IEnumerable<int> Natural() {
            for (int i = 0;; i++) yield return i;
        }
        public static IEnumerable<int> Positive() => Natural().Skip(1);

        public static long Pow(this long i, long exp) => (exp == 0) ? 1 : i * Pow(i, exp - 1);
        public static long Pow(this int i, long exp) => (exp == 0) ? 1 : i * Pow(i, exp - 1);

        public static int IntLog(this long n, long baseNum) {
            int count = 0;
            while (n > 1) {
                n /= baseNum;
                count++;
            }
            return count;
        }

    }

    static class Util {
        public static InvalidOperationException UnreachableException = new InvalidOperationException("unreachable.");

        public static string Show(this IEnumerable<char> source) => new string(source.ToArray());
        public static HashSet<T> ToHashSet<T>(this IEnumerable<T> source) => new HashSet<T>(source);

        public static MultiSet<T> ToMultiSet<T>(this IEnumerable<T> t) => new MultiSet<T>(t);

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

        public static VectorInt2 ReadVectorInt2() =>
            new VectorInt2(ReadInt(), ReadInt());

        public static VectorDouble2 ReadVectorDouble2() =>
            new VectorDouble2(ReadInt(), ReadInt());

        public static string ReplaceX(this string input, string pattern, string replace) =>
            Regex.Replace(input, pattern, replace);

        public static IEnumerable<int> Range(int i, int j) => Enumerable.Range(i, j);
        public static IEnumerable<long> Range(long i, long j) {
            for (long k = i; k < i + j; k++) yield return k;

        }
        public static void Swap<T>(this IList<T> enumerable, int i, int j) {
            var buf = enumerable[i];
            enumerable[i] = enumerable[j];
            enumerable[j] = buf;

        }

        public static bool In<T>(this T t, IEnumerable<T> range) => range.Contains(t);

    }

    static class ParametricExtensions {
        public static Func<S, U> Then<S, T, U>(this Func<S, T> f, Func<T, U> g) => x => g(f(x));
        public static Func<S, U> Compose<S, T, U>(this Func<T, U> f, Func<S, T> g) => x => f(g(x));

        public static void Call<T>(this T t, Action<T> action) => action(t);
        public static void WriteLine<T>(this T t) => Console.WriteLine(t);
        public static void Write<T>(this T t) => Console.Write(t);
        public static T Call<S, T>(this S s, Func<S, T> func) => func(s);

        public static S Call<S>(this S s, Func<S, S> func, int times) => times == 0 ? s : Call(func(s), func, times - 1);

    }

    static class StreamExtensions {

        public static void ReverseRange<T>(this IList<T> enumerable, int i, int j) {
            int half = (j - i) / 2;
            for (int k = 0; k <= half; k++) enumerable.Swap(i + k, j - k);
        }

        public static bool isEmpty<T>(this IEnumerable<T> enumerable) => !enumerable.Any();
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

        public static void ForEach<T>(this IEnumerable<T> e, Action<T> action) {
            foreach (var v in e) action(v);
        }
        public static long Prod(this IEnumerable<long> source) => source.Aggregate(Multiply);

        public static IEnumerable<int> FromTo(int a, int b) => Range(a, Max(b - a + 1, 0));
        public static IEnumerable<T> Repeat<T>(T t) {
            while (true) yield return t;
        }
        public static IEnumerable<T> Replicate<T>(int n, T t) => Repeat(t).Take(n);

        public static IEnumerable<T> Cycle<T>(this IEnumerable<T> e) {
            while (true)
                foreach (var v in e) yield return v;
        }

        public static IEnumerable<T> Scan<S, T>(this IEnumerable<S> source, T init, Func<T, S, T> accumulator) {
            var result = init;
            foreach (var item in source) {
                result = accumulator(result, item);
                yield return result;
            }
        }

        public static T[] ToArray<T>(params T[] ns) => ns;
        public static List<T> ToList<T>(params T[] ns) => ns.ToList();

        public static Dictionary<T1, T2> ToDictionary<T1, T2>(this IEnumerable<KeyValuePair<T1, T2>> source) {
            var dict = new Dictionary<T1, T2>();
            source.ForEach(x => dict.Add(x.Key, x.Value));
            return dict;
        }
        public static SortedDictionary<T1, T2> ToSortedDictionary<T1, T2>(this IEnumerable<KeyValuePair<T1, T2>> source) => new SortedDictionary<T1, T2>(source.ToDictionary());
        public static MultiSet<T> ToMultiSet<T>(this IEnumerable<KeyValuePair<T, long>> source) => new MultiSet<T>(source);
        public static SortedMultiSet<T> ToSortedMultiSet<T>(this IEnumerable<KeyValuePair<T, long>> source) => new SortedMultiSet<T>(source);

        public static IEnumerable<T> Scan0<S, T>(this IEnumerable<S> source, T init, Func<T, S, T> accumulator) {
            yield return init;
            foreach (var item in Scan(source, init, accumulator)) yield return item;
        }

        public static IEnumerable<Tuple<T1, T2>> Cartesian<T1, T2>(IEnumerable<T1> s1, IEnumerable<T2> s2) =>
            from v1 in s1 from v2 in s2 select new Tuple<T1, T2>(v1, v2);

        public static IEnumerable<Tuple<T1, T2, T3>> Cartesian<T1, T2, T3>(IEnumerable<T1> s1, IEnumerable<T2> s2, IEnumerable<T3> s3) =>
            from v1 in s1 from v2 in s2 from v3 in s3 select new Tuple<T1, T2, T3>(v1, v2, v3);

        public static IEnumerable<Tuple<T1, T2, T3, T4>> Cartesian<T1, T2, T3, T4>(IEnumerable<T1> s1, IEnumerable<T2> s2, IEnumerable<T3> s3, IEnumerable<T4> s4) =>
            from v1 in s1 from v2 in s2 from v3 in s3 from v4 in s4 select new Tuple<T1, T2, T3, T4>(v1, v2, v3, v4);

        public static IEnumerable<List<T>> Buffer<T>(this IEnumerable<T> source, int length) {
            while (source.Any()) {
                yield return source.Take(length).ToList();
                source = source.Skip(length);
            }
        }

        public static T MaxBy<T>(this IEnumerable<T> source, Func<T, long> selector) {
            T max = source.First();
            foreach (var item in source)
                if (selector(item) > selector(max)) max = item;
            return max;
        }

        public static T MinBy<T>(this IEnumerable<T> source, Func<T, long> selector) {
            T min = source.First();
            foreach (var item in source)
                if (selector(item) < selector(min)) min = item;
            return min;
        }

        public static int IndexOf<T>(this IList<T> source, Func<T, bool> condition) {
            for (int i = 0; i < source.Count; i++)
                if (condition(source[i]))
                    return i;

            return -1;
        }
        public static IEnumerable<List<T>> ChunkBy<T>(this IEnumerable<T> source) => ChunkBy(source, Id, EqualityComparer<T>.Default);
        public static IEnumerable<List<T>> ChunkBy<S, T>(this IEnumerable<T> source, Func<T, S> selector) => ChunkBy(source, selector, EqualityComparer<S>.Default);
        public static IEnumerable<List<T>> ChunkBy<S, T>(this IEnumerable<T> source, Func<T, S> selector, IEqualityComparer<S> comparer) {
            while (source.Any()) {
                var v = selector(source.First());
                var l = source.TakeWhile(x => comparer.Equals(selector(x), v)).ToList();
                yield return l;
                source = source.Skip(l.Count());
            }
        }
    }

    static class Matrix {
        public static List<List<T>> Transpose<T>(this List<List<T>> source) =>
            Range(0, source[0].Count).Select(i => source.Select(x => x[i]).ToList()).ToList();

        public static void WriteMatrix(this IEnumerable<IEnumerable<char>> source) {
            foreach (var line in source) line.Show().WriteLine();
        }

        public static List<List<long>> ReadLongMatrix(int h, int w) => h.Times(() => ReadLong(w)).ToList();

        public static List<List<T>> SelectMatrix<S, T>(this List<List<S>> source, Func<S, T> f) => source.Select(x => x.Select(f).ToList()).ToList();
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
        static public List<int> ReadInt(long n) {
            var list = new List<int>();
            n.Times(() => list.Add(ReadInt()));
            return list;
        }
        static public long ReadLong() => long.Parse(tokens.Dequeue());
        static public List<long> ReadLong(long n) {
            var list = new List<long>();
            n.Times(() => list.Add(ReadLong()));
            return list;
        }
        static public string ReadString() => tokens.Dequeue();
        static public List<string> ReadString(long n) {
            var list = new List<string>();
            n.Times(() => list.Add(ReadString()));
            return list;
        }

        static public void SayYesNo(this bool b) => (b ? "Yes" : "No").WriteLine();
        static public void SayYESNO(this bool b) => (b ? "YES" : "NO").WriteLine();

    }

    public struct VectorInt2 {
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

        public override string ToString() => $"({X}, {Y})";
    }

    struct VectorDouble2 {
        public double X { get; set; }
        public double Y { get; set; }

        public VectorDouble2(double x, double y) {
            X = x;
            Y = y;
        }

        static public VectorDouble2 operator +(VectorDouble2 v1, VectorDouble2 v2) =>
            new VectorDouble2(v1.X + v2.X, v1.Y + v2.Y);
        static public VectorDouble2 operator -(VectorDouble2 v1, VectorDouble2 v2) =>
            new VectorDouble2(v1.X - v2.X, v1.Y - v2.Y);
        static public VectorDouble2 operator *(VectorDouble2 v1, VectorDouble2 v2) =>
            new VectorDouble2(v1.X * v2.X, v1.Y * v2.Y);
        static public VectorDouble2 operator *(VectorDouble2 v1, int i) =>
            new VectorDouble2(v1.X * i, v1.Y * i);
        static public VectorDouble2 operator *(int i, VectorDouble2 v2) =>
            new VectorDouble2(i * v2.X, i * v2.Y);
        static public VectorDouble2 operator /(VectorDouble2 v1, double i) =>
            new VectorDouble2(v1.X / i, v1.Y / i);

        public override string ToString() => $"({X}, {Y})";

        public VectorDouble2 Turn(double radian) => new VectorDouble2(X * Cos(radian) - Y * Sin(radian), X * Sin(radian) + Y * Cos(radian));
    }

    public struct LongRange {
        public long Left;
        public long Right;

        public LongRange(long left, long right) {
            Left = left;
            Right = right;
        }
    }

    public struct LongFromToVector {
        public VectorInt2 Start;
        public VectorInt2 End;
        public LongFromToVector(VectorInt2 start, VectorInt2 end) {
            Start = start;
            End = end;
        }
    }
}

namespace AtCoder {
    using System.Collections.Generic;
    using System.Collections;
    using System.Linq;
    using System;

    class MultiSet<T> : ICollection<T> {
        // TODO: ????????????????
        Dictionary<T, long> occurrence;

        public MultiSet() { occurrence = new Dictionary<T, long>(); }
        public MultiSet(MultiSet<T> source) : this(source.occurrence) {}
        public MultiSet(Dictionary<T, long> source) {
            occurrence = new Dictionary<T, long>(source);
            Validate();
        }

        public MultiSet(IEnumerable<T> source) {
            occurrence = new Dictionary<T, long>();
            AddRange(source);
        }

        public MultiSet(IEnumerable<KeyValuePair<T, long>> source) {
            occurrence = new Dictionary<T, long>();
            foreach (var item in source) this [item.Key] += item.Value;
        }

        public void Add(T data) {
            if (!occurrence.ContainsKey(data)) {
                occurrence[data] = 1;
                return;
            }
            occurrence[data]++;
        }

        public void Clear() => occurrence.Clear();

        public void Add(T key, int value) {
            if (value <= 0) throw new ArgumentException();
            if (!occurrence.ContainsKey(key)) {
                occurrence[key] = value;
                return;
            }
            occurrence[key] += value;
        }

        public void Add(KeyValuePair<T, int> pair) => Add(pair.Key, pair.Value);

        public void AddRange(IEnumerable<T> source) =>
        source.ToList().ForEach(Add);

        public bool Remove(T data) {
            if (!occurrence.ContainsKey(data)) return false;
            occurrence[data]--;
            if (occurrence[data] == 0) occurrence.Remove(data);
            return true;
        }

        // IDictionary
        public long this [T key] {
            get { return occurrence.ContainsKey(key) ? occurrence[key] : 0; }
            set {
                if (value <= 0) throw new ArgumentException();
                occurrence[key] = value;
            }
        }

        public ICollection<T> Keys {
            get { return occurrence.Keys; }
        }
        public ICollection<long> Values {
            get { return occurrence.Values; }
        }

        public bool ContainsKey(T key) => occurrence.ContainsKey(key);
        public bool Contains(T key) => ContainsKey(key);
        public bool TryGetValue(T key, out long value) {
            value = this [key];
            return true;
        }
        // /IDictionary

        public long LongCount() => occurrence.Values.Sum();
        public int Count => (int) occurrence.Values.Sum();
        public bool IsReadOnly => false;
        public void CopyTo(T[] array, int index) {
            foreach (var pair in occurrence) {
                for (int i = 0; i < pair.Value; i++) {
                    array[index] = pair.Key;
                    index++;
                }
            }
        }

        public IEnumerator<T> GetEnumerator() {
            foreach (var pair in occurrence)
                for (int i = 0; i < pair.Value; i++) yield return pair.Key;

        }

        IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();

        public void Validate() {
            if (occurrence.Values.Any(x => x <= 0)) throw new ArgumentException();
        }
    }

    class SortedMultiSet<T> : ICollection<T> {
        // TODO: ????????????????
        SortedDictionary<T, long> occurrence;

        public SortedMultiSet() { occurrence = new SortedDictionary<T, long>(); }
        public SortedMultiSet(SortedMultiSet<T> source) : this(source.occurrence) {}
        public SortedMultiSet(SortedDictionary<T, long> source) {
            occurrence = new SortedDictionary<T, long>(source);
            Validate();
        }

        public SortedMultiSet(IEnumerable<T> source) {
            occurrence = new SortedDictionary<T, long>();
            AddRange(source);
        }

        public SortedMultiSet(IEnumerable<KeyValuePair<T, long>> source) {
            occurrence = new SortedDictionary<T, long>();
            foreach (var item in source) this [item.Key] += item.Value;
        }

        public void Add(T data) {
            if (!occurrence.ContainsKey(data)) {
                occurrence[data] = 1;
                return;
            }
            occurrence[data]++;
        }

        public void Clear() => occurrence.Clear();

        public void Add(T key, int value) {
            if (value <= 0) throw new ArgumentException();
            if (!occurrence.ContainsKey(key)) {
                occurrence[key] = value;
                return;
            }
            occurrence[key] += value;
        }

        public long LongCount() => occurrence.Values.Sum();
        public int Count => (int) occurrence.Values.Sum();

        public void Add(KeyValuePair<T, int> pair) => Add(pair.Key, pair.Value);

        public void AddRange(IEnumerable<T> source) =>
        source.ToList().ForEach(Add);

        public bool Remove(T data) {
            if (!occurrence.ContainsKey(data)) return false;
            occurrence[data]--;
            if (occurrence[data] == 0) occurrence.Remove(data);
            return true;
        }

        // IDictionary
        public long this [T key] {
            get {
                return occurrence.ContainsKey(key) ? occurrence[key] : 0;
            }
            set {
                if (value <= 0) throw new ArgumentException();
                occurrence[key] = value;
            }
        }

        public ICollection<T> Keys => occurrence.Keys;
        public ICollection<long> Values => occurrence.Values;

        public bool ContainsKey(T key) => occurrence.ContainsKey(key);
        public bool Contains(T key) => ContainsKey(key);
        public bool TryGetValue(T key, out long value) {
            value = this [key];
            return true;
        }
        // /IDictionary

        public bool IsReadOnly => false;
        public void CopyTo(T[] array, int index) {
            foreach (var pair in occurrence) {
                for (int i = 0; i < pair.Value; i++) {
                    array[index] = pair.Key;
                    index++;
                }
            }
        }

        public IEnumerator<T> GetEnumerator() {
            foreach (var pair in occurrence)
                for (int i = 0; i < pair.Value; i++) yield return pair.Key;

        }

        IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();

        public void Validate() {
            if (occurrence.Values.Any(x => x <= 0)) throw new ArgumentException();
        }
    }
}