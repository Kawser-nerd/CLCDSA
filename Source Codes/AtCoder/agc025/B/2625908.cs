using System;
using System.IO;
using System.Collections.Generic;

namespace AGC025B_1
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(int.Parse);
            var A = ss.Next(long.Parse);
            var B = ss.Next(long.Parse);
            var K = ss.Next(long.Parse);

            ModInt.Mod = 998244353;
            var comb = new Combination(N * 2);

            var ans = (ModInt)0;
            for (var a = 0; a <= N; a++)
            {
                if ((K - a * A) % B != 0) continue;
                var b = (K - a * A) / B;
                if (0 > b || b > N) continue;
                ans += comb.NCK(N, a) * comb.NCK(N, (int)b);
            }

            sw.WriteLine(ans);
            //---------------------------------
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Solve(ss, sw);
            sw.Flush();
        }

        static readonly Func<string, string> String = s => s;
    }

    public static partial class MathX
    {
        public static int GcdEx(int a, int b, out int x, out int y)
        {
            if (b == 0)
            {
                x = 1;
                y = 0;
                return a;
            }

            int tx, ty;
            var gcd = GcdEx(b, a % b, out tx, out ty);

            x = ty;
            y = tx - ty * (a / b);
            return gcd;
        }
    }

    public class Combination
    {
        readonly ModInt[] facts;

        public Combination(int max)
        {
            facts = new ModInt[max + 1];
            facts[0] = 1;
            for (var i = 1; i <= max; i++) facts[i] = facts[i - 1] * i;
        }

        public ModInt Fact(int n)
        {
            return facts[n];
        }

        public ModInt NCK(int n, int k)
        {
            if (n < k) return 0;
            return facts[n] / facts[k] / facts[n - k];
        }

        public ModInt NPK(int n, int k)
        {
            if (n < k) return 0;
            return facts[n] / facts[n - k];
        }

        public ModInt NHK(int n, int k)
        {
            if (k == 0) return 1;
            if (n == 0) return 0;
            return facts[n + k - 1] / facts[k] / facts[n - 1];
        }
    }

    public struct ModInt
    {
        public static int Mod = 1000000007;

        readonly long value;
        public int Value { get { return (int)value; } }
        public ModInt Inverse { get { return GetInverse(); } }

        public ModInt(long value)
        {
            value %= Mod;
            this.value = value < 0 ? value + Mod : value;
        }

        ModInt GetInverse()
        {
            int x, y;
            if (MathX.GcdEx(Value, Mod, out x, out y) != 1)
            {
                throw new InvalidOperationException("'Value' and 'Mod' must be disjoint.");
            }
            return x;
        }

        public ModInt Square()
        {
            return this * this;
        }

        public ModInt Pow(long exp)
        {
            if (exp == 0) return 1;
            if (exp % 2 == 0) return Pow(exp / 2).Square();
            return this * Pow(exp - 1);
        }

        public static ModInt Parse(string str)
        {
            return long.Parse(str);
        }

        public static implicit operator ModInt(long value)
        {
            return new ModInt(value);
        }

        public static ModInt operator +(ModInt left, ModInt right)
        {
            return left.value + right.value;
        }

        public static ModInt operator -(ModInt left, ModInt right)
        {
            return left.value - right.value;
        }

        public static ModInt operator *(ModInt left, ModInt right)
        {
            return left.value * right.value;
        }

        public static ModInt operator /(ModInt left, ModInt right)
        {
            return left * right.Inverse;
        }

        public override bool Equals(object obj)
        {
            if (!(obj is ModInt)) return false;
            return value == ((ModInt)obj).value;
        }

        public override int GetHashCode()
        {
            return value.GetHashCode();
        }

        public override string ToString()
        {
            return value.ToString();
        }
    }

    public class StreamScanner
    {
        static readonly char[] Sep = {' '};
        readonly Queue<string> buffer = new Queue<string>();
        readonly TextReader textReader;

        public StreamScanner(TextReader textReader)
        {
            this.textReader = textReader;
        }

        public T Next<T>(Func<string, T> parser)
        {
            if (buffer.Count != 0) return parser(buffer.Dequeue());
            var nextStrings = textReader.ReadLine().Split(Sep, StringSplitOptions.RemoveEmptyEntries);
            foreach (var nextString in nextStrings) buffer.Enqueue(nextString);
            return Next(parser);
        }

        public T[] Next<T>(Func<string, T> parser, int x)
        {
            var ret = new T[x];
            for (var i = 0; i < x; ++i) ret[i] = Next(parser);
            return ret;
        }

        public T[][] Next<T>(Func<string, T> parser, int x, int y)
        {
            var ret = new T[y][];
            for (var i = 0; i < y; ++i) ret[i] = Next(parser, x);
            return ret;
        }
    }
}