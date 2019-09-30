// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver {
    static public int BitCount(ulong x) {
        int bitCount = 0;
        for (; x != 0; x = x & (x - 1)) bitCount++;
        return bitCount;
    }

    double?[,] memo;

    double dfs(List<double> P, int index, int k) {
        if (index == P.Count) return k == 0 ? 1.0 : 0.0;

        if (!memo[index, k].HasValue) {
            double val = 0;

            if (k > 0) {
                val += dfs(P, index + 1, k - 1) * P[index];
            }
            val += dfs(P, index + 1, k) * (1 - P[index]);

            memo[index, k] = val;
        }
        return memo[index, k].Value;
    }

    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {
            var N = ni();
            var K = ni();
            var P = new double[N];
            for (int i = 0; i < N; i++) {
                P[i] = nd();
            }

            // d(i) = P[i] * d(i) + (1-P[i]) * d(i-1)

            double ans = 0;

            for (int b = 0; b < (1 << N); b++) {
                if (BitCount((ulong)b) != K) continue;
                var subset = new List<double>();
                for (int i = 0; i < N; i++) {
                    if (((1 << i) & b) != 0) {
                        subset.Add(P[i]);
                    }
                }
                memo = new double?[500, 500];

                var sub = dfs(subset, 0, K / 2);
                ans = Math.Max(ans, sub);
            }

            cout.WriteLine("Case #{0}: {1:0.00000000}", caseNo++, ans);
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner {
    public static void Main(string[] args) {
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

    public int ni() { return NextInt(); }
    public int[] ni(int n) { return NextIntArray(n); }
    public long nl() { return NextLong(); }
    public long[] nl(int n) { return NextLongArray(n); }
    public double nd() { return NextDouble(); }
    public string ns() { return Next(); }
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
