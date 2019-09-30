using System;
using System.Linq;
using System.Collections;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using static System.Console;
using static System.Math;
using static AtCoder.MyMath;
using static AtCoder.MyUtility;

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
        }

        public void Solve()
        {
            var cin = new MyInputStream();
            var N = cin.ReadInt();
            var a = new List<Pair<int>>(N);
            for (var i = 0; i < N; ++i) a.Add(new Pair<int>(cin.ReadInt(), cin.ReadInt()));
            a.Sort((x, y) =>
                    {
                        if (x.First == y.First) return y.Second - x.Second;
                        else return x.First - y.First;
                    });
            var tree = new SegTree(100000);
            var ans = 0l;

            for (int i = 0; i < N; ++i)
            {
                var h = a[i].Second;
                var now = tree.getMax(0, h) + 1;
                ans = Max(ans, now);
                tree[h] = now;
            }
            WriteLine(ans);
        }
    }

    public class SegTree
    {
        public int N { get; private set; }
        private long[] tree;
        public SegTree() :this(256) {}
        public SegTree(int size)
        {
            var n = 1;
            while (n < size) n <<= 1;
            N = n;
            tree = new long[n << 1];
        }
        public long this[int i]
        {
            get
            {
                return tree[N + i];
            }
            set
            {
                i += N;
                while(i > 0)
                {
                    tree[i] = Math.Max(tree[i], value);
                    i >>= 1;
                }
            }
        }
        public long getMax(int a, int b, int i = 1, int l = 0, int r = -1)
        {
            if (r == -1) r = N;
            if (a <= l && r <= b) return tree[i];
            var ret = 0l;
            var c = (l + r) >> 1;
            if (a < c) ret = Math.Max(ret, getMax(a, b, i << 1,     l, c));
            if (c < b) ret = Math.Max(ret, getMax(a, b, i << 1 | 1, c, r));
            return ret;
        }
    }

    public class MyInputStream
    {
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(char separator = ' ')
        {
            this.separator = separator;
            inputStream = new Queue<string>();
        }

        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = Console.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; i++)
            {
                inputStream.Enqueue(tmp[i]);
            }
            return inputStream.Dequeue();
        }
        public string ReadLine() => Console.ReadLine();
        public int ReadInt() => int.Parse(Read());
        public long ReadLong() => long.Parse(Read());
        public double ReadDouble() => double.Parse(Read());
    }

    public class MyMath
    {
        // nx = x + dxy[i], ny = y + dxy[i + 1] (i = 0..3)
        public static int[] dxy = new int[] { 0, 1, 0, -1, 0 };

        /// <summary>???</summary>
        public static int INF = int.MaxValue >> 1;

        /// <summary>???????</summary>
        public static double EPS = 1e-11;

        /// <summary>??????</summary>
        public static long MOD = 1000000007;

        /// <summary>2???????????????</summary>
        public static bool EQ(double d1, double d2) => (Math.Abs(d1 - d2) < EPS);

        /// <summary>x^n % m</summary>
        public static long PowMod(long x, long n, long m)
        {
            long ans = 1;
            long mul = x;
            for (; n > 0; n >>= 1, mul = (mul * mul) % m)
            {
                if ((n & 1) == 1) ans = (ans * mul) % m;
            }
            return ans % m;
        }

        /// <summary>n! % m</summary>
        public static long FactMod(int n, long m)
        {
            long ans = 1;
            for (int i = 2; i <= n; i++)
            {
                ans *= i;
                ans %= m;
            }
            return ans;
        }

        /// <summary>n!</summary>
        public static long Fact(int n)
        {
            long ans = 1;
            for (int i = 2; i <= n; i++) ans *= i;
            return ans;
        }

        /// <summary>nCr % mod</summary>
        public static long ConbMod(int n, int r, long m)
        {
            long mul = FactMod(n, m);
            long div = (FactMod(r, m) * FactMod(n - r, m)) % m;
            long inv = PowMod(div, m - 2, m);
            return (mul * inv) % m;
        }

        /// <summary>nCr</summary>
        public static long Conb(int n, int r)
        {
            long mul = Parm(n, r);
            long div = Fact(r);
            return mul / div;
        }

        /// <summary>nPr</summary>
        public static long Parm(int n, int r)
        {
            long ans = 1;
            for (int i = n; i >= r; i--) ans *= i;
            return ans;
        }

        /// <summary>?????</summary>
        public static long Gcd(long m, long n)
        {
            if (n == 0) return m;
            if (m < n) MyUtility.Swap(ref m, ref n);
            long tmp;
            while ((tmp = m % n) != 0)
            {
                m = n;
                n = tmp;
            }
            return n;
        }

        /// <summary>?????</summary>
        public static long Lcm(long m, long n)
        {
            return m * n / Gcd(m, n);
        }

        /// <summary>?????</summary>
        public static double Dist(double x, double y)
        {
            return Math.Sqrt(x * x + y * y);
        }

        /// <summary>????</summary>
        public static bool isPrime(int n)
        {
            if (n < 2) return false;
            if ((n & 1) == 0) return n == 2 ? true : false;
            for (int i = 3; i * i <= n; i += 2)
            {
                if (n % i == 0) return false;
            }
            return true;
        }

        /// <summary>????(random)</summary>
        public static IEnumerable<int> GetPrimes(int n)
        {
            return Enumerable.Range(2, n - 1).AsParallel().Where(x => isPrime(x));
        }

        /// <summary>?????????</summary>
        public static int BitCount(uint n)
        {
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
            n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
            return (int)((n & 0x0000ffff) + ((n >> 16) & 0x0000ffff));
        }

        public static string FizzBuzz(long n)
        {
            var ret = "";
            if (n % 3 == 0) ret += "Fizz";
            if (n % 5 == 0) ret += "Buzz";
            return ret == "" ? n.ToString() : ret;
        }
    }

    public class MyUtility
    {
        /// <summary>???:????(n?????????????)</summary>
        public static double binarySearch(Func<double, double> calc, double min, double max, double target)
        {
            var mid = 0.0;
            for (int i = 0; i < 50; i++)
            {
                mid = min + (max - min) / 2.0;
                if (calc(mid) < target) min = mid;
                else max = mid;
            }
            return mid;
        }
        public static double binarySearch(Func<double, double> calc, double min, double max)
        {
            return binarySearch(calc, min, max, 0.0);
        }

        /// <summary>???:????<summary>
        public static double ternarySearch(Func<double, double> calc, double min, double max)
        {
            var left = 0.0;
            var right = 0.0;
            for (int i = 0; i < 200; i++)
            {
                left = (min * 2 + max) / 3.0;
                right = (min + max * 2) / 3.0;
                if (calc(left) < calc(right)) max = right;
                else min = left;
            }
            return (left + right) * 0.5;
        }

        /// <summary>??????</summary>
        /// calc : ?????( = 0), calcdash : calc????
        public static double newtonSearch(Func<double, double> calc, Func<double, double> calcdash)
        {
            var ans0 = 0.0;
            var ans1 = calc(ans0) / calcdash(ans0);
            for (int i = 0; i < 100; i++)
            {
                if (MyMath.EQ(ans0 - ans1, 0.0)) break;
                ans1 = ans0;
                ans0 -= calc(ans0) / calcdash(ans0);
            }
            return ans0;
        }

        public static int Coin(int[] coins, int price)
        {
            var N = coins.Length;
            var dp = new int[price + 1]; dp[0] = 0;
            for (var i = 1; i <= price; i++) dp[i] = int.MaxValue;
            for (var i = 1; i <= price; i++)
                for (var j = 0; j < N; j++)
                    if (i >= coins[j]) dp[i] = Math.Min(dp[i], dp[i - coins[j]] + 1);
                    else dp[i] = Math.Min(dp[i], dp[i - 1] + 1);
            return dp[price];
        }

        /// <summary>2???????</summary>
        public static void Swap<T>(ref T m, ref T n)
        {
            T tmp = m;
            m = n;
            n = tmp;
        }

        /// <summary>??????</summary>
        public static void Dump(params object[] data)
        {
            data.Dump();
        }
    }

#region extentions
    public static class MyExtentions
    {
        public static int CountStringOfString(this string source, string target)
        {
            int cnt = 0;
            int targetLen = target.Length;
            if (targetLen == 0) return 0;
            for (int i = 0; i <= source.Length - targetLen; i++)
            {
                int tmp = source.IndexOf(target, i);
                if (tmp != -1)
                {
                    cnt++;
                    i = Math.Max(tmp + targetLen - 1, 0);
                }
                else break;
            }
            return cnt;
        }
    }

    public static class MyEnumerableExtentions
    {
        public static string ConcatWith<T>(this IEnumerable<T> source, string separator,
                string format, IFormatProvider provider = null) where T : IFormattable
        {
            return source.Select(x => x.ToString(format, provider)).Aggregate((a, b) => a + separator + b);
        }

        public static string ConcatWith<T>(this IEnumerable<T> source, string separator)
        {
            return string.Join(separator, source);
        }

        public static void ForEach<T>(this IEnumerable<T> source, Action<T, int> func)
        {
            foreach (var item in source.Select((x, i) => new { val = x, idx = i }))
                func(item.val, item.idx);
        }

        public static void ForEach<T>(this IEnumerable<T> source, Action<T> func)
        {
            foreach (var item in source)
                func(item);
        }

        public static void Dump<T>(this IEnumerable<T> source)
        {
            Console.WriteLine("{ " + source.ConcatWith(", ") + " }");
        }

        public static IEnumerable<T> Shuffle<T>(this IEnumerable<T> source)
        {
            return source.OrderBy(x => Guid.NewGuid());
        }

        public static bool IsEmpty<T>(this IEnumerable<T> source)
        {
            return !source.Any();
        }

        public static string MaxLengthString(this IEnumerable<string> source)
        {
            return source.Aggregate("", (max, s) => s.Length > max.Length ? s : max);
        }

        public static string MinLengthString(this IEnumerable<string> source)
        {
            return source.Aggregate("", (min, s) => (s.Length < min.Length || min == "") ? s : min);
        }

        public static IEnumerable<IEnumerable<T>> Permutations<T>(this IEnumerable<T> source)
        {
            if (source.Count() != 0)
            {
                int index = 0;
                foreach (var item in source)
                {
                    var allOtherItems = source.RemoveAt(index++);
                    foreach (var permutation in allOtherItems.Permutations())
                    {
                        yield return new[] { item }.Concat(permutation);
                    }
                }
            }
            else { yield return new T[0]; }
        }

        public static IEnumerable<T> RemoveAt<T>(this IEnumerable<T> source, int indexToRemove)
        {
            int index = 0;
            foreach (T item in source)
                if (index++ != indexToRemove)
                    yield return item;
        }

        public static int MaxIndex(this IEnumerable<int> source)
        {
            return source.Select((v, i) => new { val = v, idx = i }).Aggregate((max, now) => (max.val > now.val) ? max : now).idx;
        }
        public static int MaxIndex(this IEnumerable<long> source)
        {
            return source.Select((v, i) => new { val = v, idx = i }).Aggregate((max, now) => (max.val > now.val) ? max : now).idx;
        }
        public static int MaxIndex(this IEnumerable<double> source)
        {
            return source.Select((v, i) => new { val = v, idx = i }).Aggregate((max, now) => (max.val > now.val) ? max : now).idx;
        }

        public static int MinIndex(this IEnumerable<int> source)
        {
            return source.Select((v, i) => new { val = v, idx = i }).Aggregate((min, now) => (min.val < now.val) ? min : now).idx;
        }
        public static int MinIndex(this IEnumerable<long> source)
        {
            return source.Select((v, i) => new { val = v, idx = i }).Aggregate((min, now) => (min.val < now.val) ? min : now).idx;
        }
        public static int MinIndex(this IEnumerable<double> source)
        {
            return source.Select((v, i) => new { val = v, idx = i }).Aggregate((min, now) => (min.val < now.val) ? min : now).idx;
        }
    }
#endregion

    public class Knapsack
    {
        public long N { get; set; }
        public long W { get; set; }
        private long[] _w;
        private long[] _v;
        public Knapsack(long N, long W, long[] w, long[] v)
        {
            this.N = N;
            this.W = W;
            _w = new long[N + 1];
            _v = new long[N + 1];
            w.CopyTo(_w, 0);
            v.CopyTo(_v, 0);
        }
        public Knapsack(int N, int[] w, int[] v, int W)
        {
            this.N = (long)N;
            this.W = (long)W;
            _w = new long[N + 1];
            _v = new long[N + 1];
            w.CopyTo(_w, 0);
            v.CopyTo(_v, 0);
        }

        // O(2^N)? : ???DP
        public long KnapsackN()
        {
            if (N == 0) return 0;
            var x = 0L;
            if (W >= _w[N - 1]) x = KnapsackN(N - 1, W - _w[N - 1]) + _v[N - 1];
            return Math.Max(x, KnapsackN(N - 1, W));
        }
        private long KnapsackN(long N, long W)
        {
            if (N == 0) return 0;
            var x = 0L;
            if (W >= _w[N - 1]) x = KnapsackN(N - 1, W - _w[N - 1]) + _v[N - 1];
            return Math.Max(x, KnapsackN(N - 1, W));
        }

        // O(NW) : ???DP
        public long KnapsackW()
        {
            var dp = new long[W + 1]; dp[0] = 0;
            for (var i = 0; i < N; i++)
                for (var j = W; j >= _w[i]; j--)
                    dp[j] = Math.Max(dp[j], _v[i] + dp[j - _w[i]]);
            return dp[W];
        }

        // O(NV) : ???DP
        public long KnapsackV()
        {
            var V = _v.Sum();
            var dp = new long[V + 1]; dp[0] = 0;
            for (var i = 1; i <= V; i++) dp[i] = int.MaxValue;
            for (var i = 1; i <= N; i++)
                for (var j = V; j >= _v[i - 1]; j--)
                    dp[j] = Math.Min(dp[j], dp[j - _v[i - 1]] + _w[i - 1]);
            for (var i = V; i >= 0; i--) if (dp[i] <= W) return i;
            return 0;
        }
    }

    public class Graph
    {
        private struct Edge
        {
            public int To;
            public long Cost;
            public Edge(int t, long c)
            {
                this.To = t;
                this.Cost = c;
            }
        }

        private struct Node : IComparable<Node>
        {
            public int Pos;
            public long Cost;
            public Node(int p, long c)
            {
                this.Pos = p;
                this.Cost = c;
            }
            public int CompareTo(Node obj)
            {
                return (int)(this.Cost - obj.Cost);
            }
        }

        private List<List<Edge>> g;
        private int N { get; set; }
        public Graph(int size)
        {
            N = size;
            g = new List<List<Edge>>(size);
            for (int i = 0; i < size; i++) g.Add(new List<Edge>());
        }

        public List<long> Dijkstra(int start = 0)
        {
            long Inf = (long)MyMath.INF << 16;
            var q = new PriorityQueue<Node>();
            q.Enqueue(new Node(start, 0));
            var ret = new List<long>(N);
            for (int i = 0; i < N; i++) ret.Add(Inf);

            while (q.Any())
            {
                var tmp = q.Dequeue();
                if (ret[tmp.Pos] == Inf) ret[tmp.Pos] = tmp.Cost;
                else continue;

                foreach (var e in g[tmp.Pos])
                    q.Enqueue(new Node(e.To, e.Cost + tmp.Cost));
            }

            return ret;
        }

        // If result is null, g has a negative cycle.
        public List<long> BellmanFord(int start = 0)
        {
            long Inf = (long)MyMath.INF << 16;
            var ret = new List<long>(N);
            for (int i = 0; i < N; i++) ret.Add(Inf);
            ret[start] = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < g[j].Count(); k++)
                    {
                        var e = g[j][k];
                        if (ret[j] != Inf && ret[e.To] > ret[j] + e.Cost)
                        {
                            ret[e.To] = ret[j] + e.Cost;
                            if (i == N - 1) return null;
                        }
                    }
                }
            }

            return ret;
        }

        // This method is useful if g is UnDirected-Graph only.
        public long DoubleSweet()
        {
            if (g == null || N == 0) return -1;

            var dist = Dijkstra(0);
            long fartestDist = 0;
            int  fartestPos  = 0;
            for (int i = 0; i < N; i++)
            {
                if (dist[i] > fartestDist)
                {
                    fartestDist = dist[i];
                    fartestPos  = i;
                }
            }

            dist = Dijkstra(fartestPos);
            fartestDist = 0;
            fartestPos  = 0;
            for (int i = 0; i < N; i++)
            {
                if (dist[i] > fartestDist)
                {
                    fartestDist = dist[i];
                    fartestPos = i;
                }
            }
            return fartestDist;
        }

        // This method judge g == DAG (Directed Acyclic Graph)
        // This method is useful if g is Directed-Graph only.
        public bool IsDAG()
        {
            if (g == null || N == 0) return false;

            visited = new bool[N];

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++) visited[j] = false;
                if (!IsDAGRecursion(i)) return false;
            }
            return true;
        }

        private bool[] visited;
        public bool IsDAGRecursion(int n)
        {
            if (visited[n])
                return false;

            visited[n] = true;
            for (int i = 0; i < g[n].Count; i++)
                if (!IsDAGRecursion(g[n][i].To)) return false;
            visited[n] = false;

            return true;
        }

        public void AddDirectedEdge(int from, int to, long cost)
        {
            g[from].Add(new Edge(to, cost));
        }

        public void AddUnDirectedEdge(int from, int to, int cost)
        {
            AddDirectedEdge(from, to, cost);
            AddDirectedEdge(to, from, cost);
        }
    }

#region Pair
    public class Pair<T>
    {
        public T First { get; set; }
        public T Second { get; set; }
        public Pair(T f, T s) { First = f; Second = s; }
        public override string ToString() { return "(" + First + ", " + Second + ")"; }
        public override int GetHashCode() { return First.GetHashCode() ^ Second.GetHashCode(); }
        public override bool Equals(object obj)
        {
            if (ReferenceEquals(this, obj)) return true;
            else if (obj == null) return false;
            var tmp = obj as Pair<T, T>;
            return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
        }
    }

    public class Pair<T1, T2>
    {
        public T1 First;
        public T2 Second;
        public Pair() { First = default(T1); Second = default(T2); }
        public Pair(T1 f, T2 s) { First = f; Second = s; }
        public override string ToString() { return "(" + First + ", " + Second + ")"; }
        public override int GetHashCode() { return First.GetHashCode() ^ Second.GetHashCode(); }
        public override bool Equals(object obj)
        {
            if (ReferenceEquals(this, obj)) return true;
            else if (obj == null) return false;
            var tmp = obj as Pair<T1, T2>;
            return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
        }
    }
#endregion

#region Point
    public class Point : Pair<int>
    {
        public int X { get { return First; } set { First = value; } }
        public int Y { get { return Second; } set { Second = value; } }
        public Point() : base(0, 0) { }
        public Point(int x, int y) : base(x, y) { }
        public IEnumerable<Point> Neighbors4()
        {
            for (int i = 0; i < 4; i++)
                yield return new Point(X + MyMath.dxy[i], Y + MyMath.dxy[i + 1]);
        }
        public IEnumerable<Point> Neighbors8()
        {
            yield return new Point(X - 1, Y - 1);
            yield return new Point(X - 1, Y);
            yield return new Point(X - 1, Y + 1);
            yield return new Point(X, Y - 1);
            yield return new Point(X, Y + 1);
            yield return new Point(X + 1, Y - 1);
            yield return new Point(X + 1, Y);
            yield return new Point(X + 1, Y + 1);
        }
        public static Point operator +(Point p) { return new Point(p.X, p.Y); }
        public static Point operator -(Point p) { return new Point(-p.X, -p.Y); }
        public static Point operator /(Point p, int r) { return new Point(p.X / r, p.Y / r); }
        public static Point operator *(int r, Point p) { return new Point(p.X * r, p.Y * r); }
        public static Point operator *(Point p, int r) { return new Point(p.X * r, p.Y * r); }
        public static Point operator +(Point p1, Point p2) { return new Point(p1.X + p2.X, p1.Y + p2.Y); }
        public static Point operator -(Point p1, Point p2) { return new Point(p1.X - p2.X, p1.Y - p2.Y); }
        public static bool operator ==(Point p1, Point p2) { return (p1.X == p2.X && p1.Y == p2.Y); }
        public static bool operator !=(Point p1, Point p2) { return (p1.X != p2.X || p1.Y != p2.Y); }
        public override bool Equals(object obj) { return base.Equals(obj); }
        public override int GetHashCode() { return base.GetHashCode(); }
        public static double dist(Point p1, Point p2)
        {
            var x = p1.X - p2.X;
            var y = p1.Y - p2.Y;
            return Math.Sqrt(x * x + y * y);
        }
    }
#endregion

#region HashMap
    public class HashMap<K, V> : Dictionary<K, V>
    {
        public HashMap() : base() { }
        public HashMap(int cap) : base(cap) { }
        public HashMap(IDictionary<K, V> dictionary) : base(dictionary) { }
        new public V this[K i]
        {
            get
            {
                V v;
                return TryGetValue(i, out v) ? v : base[i] = default(V);
            }
            set { base[i] = value; }
        }
    }
#endregion

#region UnionFind
    public class UnionFind
    {
        private int cap;
        private int[] parent;
        private int[] rank;
        public UnionFind(int size)
        {
            cap = size;
            parent = new int[cap];
            rank = new int[cap];
            for (var i = 0; i < cap; i++) parent[i] = i;
        }
        public int GetRoot(int x)
        {
            if (parent[x] == x) return x;
            else return parent[x] = GetRoot(parent[x]);
        }
        public void UniteCategory(int x, int y)
        {
            x = GetRoot(x);
            y = GetRoot(y);
            if (x == y) return;
            if (rank[x] < rank[y]) parent[x] = y;
            else
            {
                parent[y] = x;
                if (rank[x] == rank[y]) rank[x]++;
            }
        }
        public bool IsSameCategory(int x, int y) { return GetRoot(x) == GetRoot(y); }
    }
#endregion

#region PriorityQueue
    public class PriorityQueue<T> : IEnumerable<T>, ICollection, IEnumerable
    {
        private Comparison<T> comp;
        private List<T> list;
        private int count;
        public int Count { get { return count; } }
        public bool IsEmpty { get { return count == 0; } }
        public PriorityQueue(IComparer<T> comp) : this((x, y) => comp.Compare(x, y)) { }
        public PriorityQueue(IComparer<T> comp, int capacity) : this((x, y) => comp.Compare(x, y), capacity) { }
        public PriorityQueue(IComparer<T> comp, IEnumerable<T> source) : this((x, y) => comp.Compare(x, y), source) { }
        public PriorityQueue(IComparer<T> comp, int capacity, IEnumerable<T> source) : this((x, y) => comp.Compare(x, y), source) { list.Capacity = capacity; }
        public PriorityQueue() : this((x, y) => ((IComparable<T>)x).CompareTo(y)) { }
        public PriorityQueue(int capacity) : this((x, y) => ((IComparable<T>)x).CompareTo(y), capacity) { }
        public PriorityQueue(IEnumerable<T> source) : this((x, y) => ((IComparable<T>)x).CompareTo(y), source) { }
        public PriorityQueue(int capacity, IEnumerable<T> source) : this((x, y) => ((IComparable<T>)x).CompareTo(y), source) { list.Capacity = capacity; }
        public PriorityQueue(Comparison<T> comparison)
        {
            comp = comparison;
            list = new List<T>();
            count = 0;
        }
        public PriorityQueue(Comparison<T> comparison, IEnumerable<T> source) : this(comparison) { foreach (var x in source) Enqueue(x); }
        public PriorityQueue(Comparison<T> comparison, int capacity) : this(comparison) { list.Capacity = capacity; }
        public void Enqueue(T x) // O(log n)
        {
            var pos = count++;
            list.Add(x);
            while (pos > 0)
            {
                var p = (pos - 1) / 2;
                if (comp(list[p], x) <= 0) break;
                list[pos] = list[p];
                pos = p;
            }
            list[pos] = x;
        }
        public T Dequeue() // O(log n)
        {
            if (count == 0) throw new InvalidOperationException();
            var value = list[0];
            var x = list[--count];
            list.RemoveAt(count);
            if (count == 0) return value;
            var pos = 0;
            while (pos * 2 + 1 < count)
            {
                var a = 2 * pos + 1;
                var b = 2 * pos + 2;
                if (b < count && comp(list[b], list[a]) < 0) a = b;
                if (comp(list[a], x) >= 0) break;
                list[pos] = list[a];
                pos = a;
            }
            list[pos] = x;
            return value;
        }
        public T Peek() { return list[0]; } // O(1)
        public void Clear() { list = new List<T>(); count = 0; } // O(1)
        public void TrimExcess() { list.TrimExcess(); } // O(1)
        public bool Contains(T item) { return list.Contains(item); } // O(n)
        void CopyTo(Array array, int index)
        {
            if (array == null)
                throw new ArgumentNullException();
            if (index < 0)
                throw new ArgumentOutOfRangeException();
            var tmp = new PriorityQueue<T>(comp, list.Count);
            for (var i = 0; i < count; i++) tmp.Enqueue(list[i]);
            while (!tmp.IsEmpty) array.SetValue(tmp.Dequeue(), index++);
        }
        bool ICollection.IsSynchronized { get { return false; } }
        object ICollection.SyncRoot { get { return this; } }
        public IEnumerator<T> GetEnumerator()
        {
            var tmp = new PriorityQueue<T>(comp, list.Count);
            for (var i = 0; i < count; i++) tmp.Enqueue(list[i]);
            while (!tmp.IsEmpty) yield return tmp.Dequeue();
        }
        IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
        void ICollection.CopyTo(Array array, int index) { CopyTo(array, index); }
        int ICollection.Count { get { return count; } }
        public bool Any() { return count > 0; }
    }
#endregion

#region Deque
    // Qiita : C#????????????????????Tips -- http://qiita.com/Camypaper/items/de6d576fe5513743a50e
    public class Deque<T> : IEnumerable, IEnumerable<T>, ICollection, IDisposable
    {
        T[] buf;
        int offset, count, capacity;
        public int Count { get { return count; } }
        public Deque(int size) { buf = new T[capacity = size]; }
        public Deque() { buf = new T[capacity = 32]; }
        public T this[int index]
        {
            get { return buf[getIndex(index)]; }
            set { buf[getIndex(index)] = value; }
        }
        private int getIndex(int index)
        {
            if (index >= capacity)
                throw new IndexOutOfRangeException("Out Of Range");
            var ret = index + offset;
            if (ret >= capacity)
                ret -= capacity;
            return ret;
        }
        public void PushFront(T item)
        {
            if (count == capacity) Extend();
            if (--offset < 0) offset += buf.Length;
            buf[offset] = item;
            ++count;
        }
        public T PopFront()
        {
            if (count == 0)
                throw new InvalidOperationException("Collection is Empty");
            --count;
            var ret = buf[offset++];
            if (offset >= capacity) offset -= capacity;
            return ret;
        }
        public void PushBack(T item)
        {
            if (count == capacity) Extend();
            var id = count++ + offset;
            if (id >= capacity) id -= capacity;
            buf[id] = item;
        }
        public T PopBack()
        {
            if (count == 0)
                throw new InvalidOperationException("Collection is Empty");
            return buf[getIndex(--count)];
        }
        public void Insert(int index, T item)
        {
            if (index > count) throw new IndexOutOfRangeException();
            this.PushFront(item);
            for (int i = 0; i < index; i++)
                this[i] = this[i + 1];
            this[index] = item;
        }
        public T RemoveAt(int index)
        {
            if (index < 0 || index >= count) throw new IndexOutOfRangeException();
            var ret = this[index];
            for (int i = index; i > 0; i--)
                this[i] = this[i - 1];
            this.PopFront();
            return ret;
        }
        private void Extend()
        {
            T[] newBuffer = new T[capacity << 1];
            if (offset > capacity - count)
            {
                var len = buf.Length - offset;
                Array.Copy(buf, offset, newBuffer, 0, len);
                Array.Copy(buf, 0, newBuffer, len, count - len);
            }
            else Array.Copy(buf, offset, newBuffer, 0, count);
            buf = newBuffer;
            offset = 0;
            capacity <<= 1;
        }
        public List<T> ToList()
        {
            return Items.ToList();
        }
        public T[] Items
        {
            get
            {
                var a = new T[count];
                for (int i = 0; i < count; i++)
                    a[i] = this[i];
                return a;
            }
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            for (int i = 0; i < count; i++)
                yield return this[i];
        }
        IEnumerator<T> IEnumerable<T>.GetEnumerator()
        {
            for (int i = 0; i < count; i++)
                yield return this[i];
        }
        void CopyTo(Array array, int index)
        {
            if (array == null)
                throw new ArgumentNullException();
            if (index < 0)
                throw new ArgumentOutOfRangeException();
            foreach (T a in Items)
                array.SetValue(a, index++);
        }
        bool ICollection.IsSynchronized { get { return false; } }
        object ICollection.SyncRoot { get { return this; } }
        void ICollection.CopyTo(Array array, int index) { CopyTo(array, index); }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        protected virtual void Dispose(bool disposing)
        {
            if (disposing)
                buf = null;
        }
        ~Deque()
        {
            Dispose(false);
        }
    }
#endregion

#region AVL
    public class AVL<T> : IEnumerable<T>, ICollection<T> where T : IComparable
    {
        private int count = 0;

        private T max(T l, T r)
        {
            var ret = l.CompareTo(r);
            if (ret == 0) return l;
            else if (ret < 1) return r;
            else return l;
        }

        class Node<U> where U : IComparable
        {
            public U data { get; set; }
            public Node<U> left;
            public Node<U> right;
            public Node(U data)
            {
                this.data = data;
            }
        }
        Node<T> root;
        public AVL() { root = null; count = 0; }
        public AVL(IEnumerable<T> data)
        {
            root = null; count = 0;
            foreach (var d in data) Add(d);
        }
        public void Add(T data)
        {
            Node<T> newItem = new Node<T>(data);
            if (root == null) root = newItem;
            else root = RecursiveInsert(root, newItem);
            count++;
        }
        private Node<T> RecursiveInsert(Node<T> current, Node<T> n)
        {
            if (current == null)
            {
                current = n;
                return current;
            }
            else if (n.data.CompareTo(current.data) < 0)
            {
                current.left = RecursiveInsert(current.left, n);
                current = BalanceTree(current);
            }
            else if (n.data.CompareTo(current.data) > 0)
            {
                current.right = RecursiveInsert(current.right, n);
                current = BalanceTree(current);
            }
            return current;
        }
        private Node<T> BalanceTree(Node<T> current)
        {
            int bFactor = BalanceFactor(current);
            if (bFactor > 1)
            {
                if (BalanceFactor(current.left) > 0) current = RotateLL(current);
                else current = RotateLR(current);
            }
            else if (bFactor < -1)
            {
                if (BalanceFactor(current.right) > 0) current = RotateRL(current);
                else current = RotateRR(current);
            }
            return current;
        }
        public void Delete(T target)
        {
            if (Delete(root, target) != null) count--;
        }
        private Node<T> Find(T target, Node<T> current)
        {
            if (target.CompareTo(current.data) < 0)
            {
                if (target.CompareTo(current.data) == 0) return current;
                else return Find(target, current.left);
            }
            else
            {
                if (target.CompareTo(current.data) == 0) return current;
                else return Find(target, current.right);
            }

        }
        public void Print()
        {
            InOrderDisplayTree(root);
        }
        private void InOrderDisplayTree(Node<T> current)
        {
            if (current != null)
            {
                InOrderDisplayTree(current.left);
                Console.Write("({0}) ", current.data);
                InOrderDisplayTree(current.right);
            }
        }
        private int GetHeight(Node<T> current)
        {
            int height = 0;
            if (current != null)
            {
                int l = GetHeight(current.left);
                int r = GetHeight(current.right);
                height = Math.Max(l, r) + 1;
            }
            return height;
        }
        private int BalanceFactor(Node<T> current)
        {
            int l = GetHeight(current.left);
            int r = GetHeight(current.right);
            return l - r;
        }
        private Node<T> RotateRR(Node<T> parent)
        {
            Node<T> pivot = parent.right;
            parent.right = pivot.left;
            pivot.left = parent;
            return pivot;
        }
        private Node<T> RotateLL(Node<T> parent)
        {
            Node<T> pivot = parent.left;
            parent.left = pivot.right;
            pivot.right = parent;
            return pivot;
        }
        private Node<T> RotateLR(Node<T> parent)
        {
            Node<T> pivot = parent.left;
            parent.left = RotateRR(pivot);
            return RotateLL(parent);
        }
        private Node<T> RotateRL(Node<T> parent)
        {
            Node<T> pivot = parent.right;
            parent.right = RotateLL(pivot);
            return RotateRR(parent);
        }
        private Node<T> Delete(Node<T> current, T target)
        {
            Node<T> parent;
            if (current == null) return null;
            else
            {
                if (target.CompareTo(current.data) < 0)
                {
                    current.left = Delete(current.left, target);
                    if (BalanceFactor(current) == -2)
                    {
                        if (BalanceFactor(current.left) <= 0) current = RotateRR(current);
                        else current = RotateRL(current);
                    }
                }
                else if (target.CompareTo(current.data) > 0)
                {
                    current.right = Delete(current.right, target);
                    if (BalanceFactor(current) == 2)
                    {
                        if (BalanceFactor(current.right) <= 0) current = RotateLL(current);
                        else current = RotateLR(current);
                    }
                }
                else
                {
                    if (current.right != null)
                    {
                        parent = current.right;
                        while (parent.left != null) parent = parent.left;
                        current.data = parent.data;
                        current.right = Delete(current.right, parent.data);
                        if (BalanceFactor(current) == 2)
                        {
                            if (BalanceFactor(current.left) <= 0) current = RotateLL(current);
                            else { current = RotateLR(current); }
                        }
                    }
                    else
                    {
                        return current.left;
                    }
                }
            }
            return current;
        }


        IEnumerator IEnumerable.GetEnumerator()
        {
            Queue<Node<T>> bfs = new Queue<Node<T>>();
            bfs.Enqueue(root);
            while (bfs.Any())
            {
                var tmp = bfs.Dequeue();
                yield return tmp.data;

                if (tmp.left != null)
                    bfs.Enqueue(tmp.left);

                if (tmp.right != null)
                    bfs.Enqueue(tmp.right);
            }
        }

        IEnumerator<T> IEnumerable<T>.GetEnumerator()
        {
            Queue<Node<T>> bfs = new Queue<Node<T>>();
            bfs.Enqueue(root);
            while (bfs.Any())
            {
                var tmp = bfs.Dequeue();
                yield return tmp.data;

                if (tmp.left != null)
                    bfs.Enqueue(tmp.left);

                if (tmp.right != null)
                    bfs.Enqueue(tmp.right);
            }
        }
        public int Count { get { return count; } }

        bool ICollection<T>.IsReadOnly { get { return false; } }

        public void CopyTo(Array array, int index)
        {
            if (array == null)
                throw new ArgumentNullException();
            if (index < 0)
                throw new ArgumentOutOfRangeException();
            foreach (T a in this)
            {
                array.SetValue(a, index++);
            }
        }

        void ICollection<T>.Clear()
        {
            root = null;
        }

        bool ICollection<T>.Contains(T data)
        {
            if (Find(data, root).data.CompareTo(data) == 0) return true;
            else return false;
        }

        void ICollection<T>.CopyTo(T[] array, int arrayIndex)
        {
            throw new NotImplementedException();
        }

        bool ICollection<T>.Remove(T data)
        {
            Delete(data);
            return true;
        }
    }
#endregion
}