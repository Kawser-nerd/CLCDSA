// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver {

    struct Data {
        public int Position;
        public int Step;
    }

    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {
            int ans = 0;

            var N = ni();
            var F = ni(N);
            F = F.Select(f => f - 1).ToArray();
            var invF = Enumerable.Range(0, N).Select(_ => new List<int>()).ToArray();
            for (int i = 0; i < N; i++) {
                //cout.WriteLine("{0} like {1}", i + 1, F[i] + 1);
                invF[F[i]].Add(i);
            }

            var visited = new bool[N];

            for (int i = 0; i < N; i++) {
                int position = i;
                int groupSize = 0;
                Array.Clear(visited, 0, visited.Length);

                //cout.WriteLine((position + 1));
                while (!visited[position]) {
                    //cout.WriteLine(" " + (position + 1));
                    visited[position] = true;
                    groupSize++;
                    position = F[position];
                }
                if (i == position) {
                    ans = Math.Max(ans, groupSize);
                }
            }
            int ansPattern2 = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < i; j++) {
                    if (F[i] == j && F[j] == i) {
                        //cout.WriteLine(" " + (i + 1) + " " + (j + 1));
                        int groupSize = 2;
                        foreach (var start in new[] { i, j }) {
                            Array.Clear(visited, 0, visited.Length);
                            var queue = new Queue<Data>();
                            queue.Enqueue(new Data { Position = start, Step = 0 });
                            int maxStep = 0;
                            while (queue.Count > 0) {
                                var now = queue.Dequeue();
                                maxStep = Math.Max(maxStep, now.Step);
                                //cout.WriteLine("   {0} {1}", now.Position, now.Step);
                                if (visited[now.Position]) continue;
                                visited[now.Position] = true;
                                foreach (var next in invF[now.Position]) {
                                    if (next == i || next == j) continue;
                                    queue.Enqueue(new Data { Position = next, Step = now.Step + 1 });
                                }
                            }
                            groupSize += maxStep;
                            //cout.WriteLine("MAX {0} {1}", start, maxStep);
                        }
                        //ansPattern2 = Math.Max(ansPattern2, groupSize);
                        ansPattern2 += groupSize;
                    }
                }
            }
            ans = Math.Max(ans, ansPattern2);
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
