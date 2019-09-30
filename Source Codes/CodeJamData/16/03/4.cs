using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;


public class PrimeSet : List<int> {
    private bool[] isPrime;

    public PrimeSet(int size)
        : base() {
        isPrime = Enumerable.Repeat(true, size).ToArray();
        Add(2);
        for (int i = 3; i <= size; i += 2) {
            if (!isPrime[i >> 1]) continue;
            Add(i);
            for (long j = (long)i * i; j <= size; j += i + i)
                isPrime[j >> 1] = false;
        }
    }

    public bool IsPrime(long x) {
        if (x == 2) return true;
        if (x <= 1 || x % 2 == 0) return false;
        return isPrime[x >> 1];
    }
}

public class Result {
    public string JamCoin { get; set; }
    public int[] Divisors = new int[11];
}

public class Solve {

    static PrimeSet primeSet = new PrimeSet(10000);

    static public int BitCount(long x) {
        int bitCount = 0;
        for (; x != 0; x = x & (x - 1)) bitCount++;
        return bitCount;
    }

    static int GetNonTrivialDivisor(int N, long bit, int baseNumber) {
        /*var bitCount = BitCount(bit);
        if (baseNumber == 3) {
            if (bitCount % 2 == 0) return 2;
        } else if (baseNumber == 4) {
            if (bitCount % 3 == 0) return 3;
        } else if (baseNumber == 5) {
            if (bitCount % 2 == 0) return 2;
        } else if (baseNumber == 6) {
            if (bitCount % 5 == 0) return 5;
        } else if (baseNumber == 7) {
            if (bitCount % 2 == 0) return 2;
            if (bitCount % 3 == 0) return 3;
        } else if (baseNumber == 8) {
            if (bitCount % 7 == 0) return 7;
        } else if (baseNumber == 9) {
            if (bitCount % 2 == 0) return 2;
        } else if (baseNumber == 10) {
            if (bitCount % 3 == 0) return 3;
        }*/

        foreach (var prime in primeSet) {
            if (prime >= (1L << N)) break;
            long r = 0;
            for (int i = N - 1; i >= 0; i--) {
                r = r * baseNumber;
                if (((1L << i) & bit) != 0) {
                    r++;
                }
                r %= prime;
            }
            if (r == 0) return prime;
        }

        return -1;
    }

    static void Main(string[] args) {
        var scanner = new Scanner();
        var t = scanner.NextInt();
        int caseNo = 1;
        while (t-- > 0) {
            var N = scanner.NextInt();
            var J = scanner.NextInt();

            var results = new List<Result>();
            var limit = 1L << (N - 2);
            for (long innerBits = 0; innerBits < limit; innerBits++) {
                long bit = innerBits << 1;
                bit |= 1;
                bit |= 1L << (N - 1);

                var result = new Result();
                result.JamCoin = Convert.ToString(bit, 2);

                bool notJamcoin = false;

                for (int b = 2; b <= 10; b++) {
                    var d = GetNonTrivialDivisor(N, bit, b);
                    if (d == -1) {
                        //Console.WriteLine("{0} {1}", Convert.ToString(bit, 2), b);
                        notJamcoin = true;
                        break;
                    }
                    result.Divisors[b] = d;
                }
                if (!notJamcoin) {
                    results.Add(result);
                    if (results.Count >= J) break;
                }
            }

            if (results.Count != J) Console.WriteLine("ERROR");

            Console.WriteLine("Case #{0}:", caseNo++);

            foreach (var result in results) {
                Console.Write("{0}", result.JamCoin);

                for (int b = 2; b <= 10; b++) {
                    Console.Write(" {0}", result.Divisors[b]);
                }

                Console.WriteLine();
            }
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

