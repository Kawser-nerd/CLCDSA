// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver {
    const char Rock = 'R';
    const char Paper = 'P';
    const char Scissors = 'S';

    string Concat(string s1, string s2) {
        var a = s1 + s2;
        var b = s2 + s1;
        if (string.CompareOrdinal(a, b) > 0) return b;
        return a;
    }

    string Find(char c, int N) {
        if (N == 0) return "" + c;
        N--;
        if (c == 'R') return Concat(Find('R', N), Find('S', N));
        else if (c == 'S') return Concat(Find('P', N), Find('S', N));
        else if (c == 'P') return Concat(Find('P', N), Find('R', N));
        else throw new Exception();
    }

    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {
            int N = ni();
            int R = ni();
            int P = ni();
            int S = ni();

            string ans = "";

            foreach (var last in new[] { 'S', 'P', 'R' }) {
                string current = Find(last, N);

                if (current.Count(c => c == 'S') != S) continue;
                if (current.Count(c => c == 'P') != P) continue;
                if (current.Count(c => c == 'R') != R) continue;

                if (ans == "" || string.CompareOrdinal(ans, current) > 0) ans = current;
            }

            if (ans == "") ans = "IMPOSSIBLE";

            cout.WriteLine("Case #{0}: {1}", caseNo++, ans);
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
