using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver {
    public void Run() {
        var t = int.Parse(cin.ReadLine());
        int caseNo = 1;
        while (t-- > 0) {
            int ans = int.MaxValue;

            var N = int.Parse(cin.ReadLine());


            var lines = new HashSet<string>[N];

            for (int i = 0; i < N; i++) {
                lines[i] = new HashSet<string>(cin.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
            }

            var toindex = new Dictionary<string, int>();

            var allWords = lines.SelectMany(line => line).Distinct().OrderBy(s => s).ToArray();
            for (int i = 0; i < allWords.Length; i++) {
                toindex[allWords[i]] = i;
            }

            var wordIndexSet = new int[N][];

            for (int i = 0; i < N; i++) {
                wordIndexSet[i] = lines[i].Select(s => toindex[s]).ToArray();
            }

            for (int bit = 0; bit < (1 << N); bit++) {
                if ((bit & 1) != 1) continue;
                if ((bit & 2) != 0) continue;
                int sub = 0;

                var isEword = new bool[allWords.Length];
                var isFword = new bool[allWords.Length];

                for (int i = 0; i < N; i++) {
                    if (((1 << i) & bit) != 0) { // english
                        foreach (var id in wordIndexSet[i]) {
                            isEword[id] = true;
                        }
                    } else {
                        foreach (var id in wordIndexSet[i]) {
                            isFword[id] = true;
                        }
                    }
                }

                for (int i = 0; i < isEword.Length; i++) {
                    if (isEword[i] && isFword[i]) sub++;
                }

                ans = Math.Min(sub, ans);
            }
            Console.WriteLine("Case #{0}: {1}", caseNo++, ans);
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner {
    public static void Main(string[] args) {
        /*new Solver(@"4
2
he loves to eat baguettes
il aime manger des baguettes
4
a b c d e
f g h i j
a b c i j
f g h d e
4
he drove into a cul de sac
elle a conduit sa voiture
il a conduit dans un cul de sac
il mange pendant que il conduit sa voiture
6
adieu joie de vivre je ne regrette rien
adieu joie de vivre je ne regrette rien
a b c d e
f g h i j
a b c i j
f g h d e", Console.Out).Run();*/
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
