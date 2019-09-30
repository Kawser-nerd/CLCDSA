// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver {


    static public void Swap<T>(ref T a, ref T b) {
        T t = a;
        a = b;
        b = t;
    }

    static public bool NextPermutation<T>(T[] array) where T : IComparable<T> {
        int n = array.Length;
        for (int i = n - 2; i >= 0; i--) {
            if (array[i].CompareTo(array[i + 1]) < 0) {
                var index = Array.FindLastIndex(array, v => array[i].CompareTo(v) < 0);
                Swap(ref array[i], ref array[index]);
                Array.Reverse(array, i + 1, n - (i + 1));
                return true;
            }
        }
        Array.Reverse(array);
        return false;
    }

    int ToBit(string[] array) {
        int bit = 0;
        int cur = 0;
        foreach (var s in array) {
            foreach (var c in s) {
                if (c == '1') bit |= (1 << cur);
                cur++;
            }
        }
        return bit;
    }

    bool dfs(bool[,] canOperate, int[] perm, int index, int used) {
        if (index == perm.Length) return true;
        int N = perm.Length;
        var p = perm[index];

        bool selected = false;
        for (int i = 0; i < N; i++) {
            if ((used & (1 << i)) != 0) continue;
            if (canOperate[p, i]) {
                selected = true;
                var sub = dfs(canOperate, perm, index + 1, used | (1 << i));
                if (!sub) return false;
            }
        }

        return selected;
    }

    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {
            int ans = int.MaxValue;
            var N = ni();
            var S = new string[N];
            for (int i = 0; i < N; i++) {
                S[i] = ns();
            }

            var NN = N * N;
            var K = S.SelectMany(s => s).Count(c => c == '1');

            var originalBit = ToBit(S);

            for (int b = 0; b < (1 << NN); b++) {
                if ((originalBit & b) != originalBit) continue;
                var canOperate = new bool[N, N];

                int cur = 0;
                int afterK = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (((1 << cur) & b) != 0) {
                            canOperate[i, j] = true;
                            afterK++;
                        }
                        cur++;
                    }
                }

                var add = afterK - K;
                //cout.WriteLine(add);

                if (add > ans) continue;

                bool ok = true;

                var perm = Enumerable.Range(0, N).ToArray();

                do {
                    if (!dfs(canOperate, perm, 0, 0)) {
                        ok = false;
                        break;
                    }
                } while (NextPermutation(perm));

                if (ok) {
                    ans = Math.Min(ans, add);
                }
            }

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
