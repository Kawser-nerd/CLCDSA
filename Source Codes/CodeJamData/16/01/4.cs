using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class Solve {

    static int ToDigitBit(long x) {
        int bit = 0;
        while (x > 0) {
            int d = (int)(x % 10);
            bit |= (1 << d);
            x /= 10;
        }
        return bit;
    }

    static void Main(string[] args) {
        var scanner = new Scanner();
        var t = scanner.NextInt();
        int caseNo = 1;
        while (t-- > 0) {
            string ans = "";
            var N = scanner.NextInt();

            if (N == 0) {
                ans = "INSOMNIA";
            } else {
                long x = 0;
                int used = 0;
                do {
                    x += N;
                    used |= ToDigitBit(x);
                } while (used != (1 << 10) - 1);
                ans = x.ToString();
            }

            Console.WriteLine("Case #{0}: {1}", caseNo++, ans);
        }
    }
}

public class Scanner {
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = new CultureInfo("en-US");

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

