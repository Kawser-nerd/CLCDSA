using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver {
    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {
            var B = nl();
            var N = nl();
            var M = NextLongArray((int)B);

            long lower = 0, upper = 1L << 61;
            long time = -1, doneOnTime = -1;
            while (lower <= upper) {
                long mid = (lower + upper) / 2;
                long done = 0;
                foreach (var m in M) {
                    done += mid / m + 1;
                }
                if (done >= N) {
                    time = mid;
                    doneOnTime = done;
                    upper = mid - 1;
                } else {
                    lower = mid + 1;
                }
            }

            long ans = -1;

            for (int i = M.Length - 1; i >= 0; i--) {
                if (time % M[i] == 0) {
                    if (doneOnTime == N) {
                        ans = i + 1;
                        break;
                    } else {
                        doneOnTime--;
                    }
                }
            }

            cout.WriteLine("Case #{0}: {1}", caseNo++, ans);
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner {
    public static void Main(string[] args) {
        /*new Solver(@"3
2 4
10 5
3 12
7 7 7
3 8
4 2 1", Console.Error).Run();*/
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
