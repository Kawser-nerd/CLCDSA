using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;



public class PointInt {
    public long X { get; set; }
    public long Y { get; set; }

    public PointInt() {

    }

    public PointInt(int x, int y) {
        this.X = x;
        this.Y = y;
    }

    public static PointInt operator +(PointInt p1, PointInt p2) {
        return new PointInt { X = p1.X + p2.X, Y = p1.Y + p2.Y };
    }

    public static PointInt operator -(PointInt p1, PointInt p2) {
        return new PointInt { X = p1.X - p2.X, Y = p1.Y - p2.Y };
    }

    public override bool Equals(object obj) {
        if (obj == null || GetType() != obj.GetType()) {
            return false;
        }
        var p = obj as PointInt;
        return this.X == p.X && this.Y == p.Y;
    }

    public override int GetHashCode() {
        return base.GetHashCode();
    }

    public long Norm {
        get {
            return 1L * X * X + 1L * Y * Y;
        }
    }

    public override string ToString() {
        return string.Format("({0},{1})", X, Y);
    }
}

public static class GeometryIntUtility {
    static public long DotProduct(PointInt p1, PointInt p2) {
        return (long)p1.X * p2.X + (long)p1.Y * p2.Y;
    }

    static public long CrossProduct(PointInt p1, PointInt p2) {
        return (long)p1.X * p2.Y - (long)p1.Y * p2.X;
    }
}
partial class Solver {
    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {

            var N = ni();
            var points = new List<PointInt>();

            for (int i = 0; i < N; i++) {
                int x = ni();
                int y = ni();
                var p = new PointInt(x, y);
                points.Add(p);
            }

            var ans = new int[N];
            for (int i = 0; i < N; i++) {
                ans[i] = int.MaxValue;
                if (N == 1) ans[i] = 0;
            }
            var doit = new Action<int>((i) => {
                //Console.Error.WriteLine(i);
                var pi = points[i];
                for (int j = 0; j < N; j++) {
                    if (i == j) continue;
                    int left = 0;

                    int lower = Math.Max(ans[i], ans[j]);
                    if (lower == 0) continue;
                    var pj = points[j];
                    var v1 = pj - pi;

                    for (int k = 0; k < N; k++) {
                        if (i == k || j == k) continue;
                        var v2 = points[k] - pi;
                        if (v1.X * v2.Y - v1.Y * v2.X > 0) {
                            left++;
                            if (lower <= left) break;
                        };
                    }

                    ans[i] = Math.Min(ans[i], left);
                    ans[j] = Math.Min(ans[j], left);
                }
            }
            );
            var tasks = new List<Task>();
            for (int p = 0; p < N; p++) {
                int pp = p;
                tasks.Add(Task.Run(() => doit(pp)));
            }

            Task.WaitAll(tasks.ToArray());

            cout.WriteLine("Case #{0}:", caseNo++);
            foreach (var a in ans) {
                cout.WriteLine(a);
            }
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner {
    public static void Main(string[] args) {
        /*new Solver(@"2
5
0 0
10 0
10 10
0 10
5 5
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10", Console.Error).Run();*/
        new Solver(Console.In, Console.Out).Run();
    }

    TextReader cin;
    TextWriter cout;

    public Solver(TextReader reader, TextWriter writer)
        : base(reader) {
        this.cin = reader;
        this.cout = writer;
    }
    public Solver(string input, TextWriter writer)
        : this(new StringReader(input), writer) {
    }

    public int ni() {
        return NextInt();
    }
    public long nl() {
        return NextLong();
    }
    public string ns() {
        return Next();
    }
}

public class Scanner {
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = CultureInfo.InvariantCulture;

    public Scanner()
        : this(Console.In) {
    }

    public Scanner(TextReader reader) {
        this.Reader = reader;
    }

    public int NextInt() { return Int32.Parse(Next(), ci); }
    public long NextLong() { return Int64.Parse(Next(), ci); }
    public double NextDouble() { return double.Parse(Next(), ci); }
    public string[] NextArray(int size) {
        var array = new string[size];
        for (int i = 0; i < size; i++) array[i] = Next();
        return array;
    }
    public int[] NextIntArray(int size) {
        var array = new int[size];
        for (int i = 0; i < size; i++) array[i] = NextInt();
        return array;
    }

    public long[] NextLongArray(int size) {
        var array = new long[size];
        for (int i = 0; i < size; i++) array[i] = NextLong();
        return array;
    }

    public String Next() {
        if (TokenQueue.Count == 0) {
            if (!StockTokens()) throw new InvalidOperationException();
        }
        return TokenQueue.Dequeue();
    }

    public bool HasNext() {
        if (TokenQueue.Count > 0)
            return true;
        return StockTokens();
    }

    private bool StockTokens() {
        while (true) {
            var line = Reader.ReadLine();
            if (line == null) return false;
            var tokens = line.Trim().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            if (tokens.Length == 0) continue;
            foreach (var token in tokens)
                TokenQueue.Enqueue(token);
            return true;
        }
    }
}
