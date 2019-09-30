using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace ProgrammingContest
{
    class Writer : IDisposable
    {
        private System.IO.TextWriter Out { get; }
        private StringBuilder Sb { get; }
        private bool IsReactive { get; }
        public Writer(string path)
            : this(new System.IO.StreamWriter(path))
        {
        }
        public Writer(bool isReactive)
            : this(null, isReactive)
        {
        }
        public Writer(System.IO.TextWriter writer = null, bool isReactive = false)
        {
            this.Out = (writer ?? Console.Out);
            this.IsReactive = isReactive;
            if (!this.IsReactive)
            {
                this.Sb = new StringBuilder();
            }
        }
        public void Dispose()
        {
            if (!this.IsReactive)
            {
                this.Out.Write(Sb.ToString());
            }
            if (!this.Out.Equals(Console.Out))
            {
                this.Out.Dispose();
            }
        }
        public void Write(object val)
        {
            if (this.IsReactive)
            {
                this.Out.Write(val.ToString());
                this.Out.Flush();
            }
            else
            {
                this.Sb.Append(val.ToString());
            }
        }
        public void WriteFormat(string format, params object[] vals)
        {
            if (this.IsReactive)
            {
                this.Out.Write(format, vals);
                this.Out.Flush();
            }
            else
            {
                this.Sb.AppendFormat(format, vals);
            }
        }

        public void WriteLine(object val = null)
            => this.WriteFormat((val?.ToString() ?? string.Empty) + Environment.NewLine);

        public void WriteLine(int val)
            => this.WriteLine(val.ToString());

        public void WriteLine(long val)
            => this.WriteLine(val.ToString());

        public void WriteLine(string val)
            => this.WriteLine((object)val);

        public void WriteLine(string format, params object[] vals)
            => this.WriteFormat(format + Environment.NewLine, vals);
    }

    class Scanner : IDisposable
    {
        private Queue<string> Buffer { get; }
        private char[] Sep { get; }
        private System.IO.TextReader Reader { get; }
        public Scanner(string path, char[] sep = null)
            : this(new System.IO.StreamReader(path), sep)
        {
        }
        public Scanner(System.IO.TextReader reader = null,
                        char[] sep = null)
        {
            this.Buffer = new Queue<string>();
            this.Sep = (sep ?? new char[] { ' ' });
            this.Reader = (reader ?? Console.In);
        }
        private void CheckBuffer()
        {
            if (this.Buffer.Count == 0 && this.Reader.Peek() != -1)
            {
                string str = string.Empty;
                for (; string.IsNullOrEmpty(str) || string.IsNullOrWhiteSpace(str);
                str = this.Reader.ReadLine()) ;

                var strs = str.Split(this.Sep)
                    .Where(el => !(string.IsNullOrEmpty(el) || string.IsNullOrWhiteSpace(el)));
                foreach (var el in strs)
                {
                    this.Buffer.Enqueue(el);
                }
            }
        }

        public void Dispose()
        {
            if (!this.Reader.Equals(Console.In))
            {
                this.Reader.Dispose();
            }
        }

        public string Next()
        {
            this.CheckBuffer();
            return this.Buffer.Dequeue();
        }

        public string[] GetStringArray(int N)
            => Enumerable.Range(0, N)
                         .Select(e => this.Next())
                         .ToArray();

        public int NextInt()
            => int.Parse(this.Next());

        public int[] GetIntArray(int N)
            => Enumerable.Range(0, N)
                         .Select(e => this.NextInt())
                         .ToArray();

        public double NextDouble()
            => double.Parse(this.Next());

        public double[] GetdoubleArray(int N)
            => Enumerable.Range(0, N)
                         .Select(e => this.NextDouble())
                         .ToArray();

        public long NextLong()
            => long.Parse(this.Next());

        public long[] GetLongArray(int N)
            => Enumerable.Range(0, N)
                         .Select(e => this.NextLong())
                         .ToArray();

        public bool IsEnd
        {
            get
            {
                this.CheckBuffer();
                return this.Buffer.Count == 0;
            }
        }
    }

    class MainClass : IDisposable
    {
        private Scanner Sc { get; }
        private Writer Wr { get; }
        private string InFilePath => "in.txt";
        private string OutFilePath => "out.txt";
        public MainClass()
        {
            this.Wr = new Writer(this.IsReactive);
            //this.Wr = new Writer(this.OutFilePath);
#if DEBUG
            if (!this.IsReactive)
            {
                this.Sc = new Scanner(this.InFilePath);
            }
            else
            {
                this.Sc = new Scanner();
            }
#else
            this.Sc = new Scanner();
#endif
            this.Solve();
        }
        static void Main(string[] args)
        {
            using (new MainClass()) { }
        }

        public void Dispose()
        {
            this.Sc?.Dispose();
            this.Wr?.Dispose();
#if DEBUG
            Console.WriteLine("press any key to continue...");
            Console.ReadKey();
#endif
        }

        const int MAX = (int)2e5 + 10;
        const int MOD = (int)1e9 + 7;
        ModCalc mc = new ModCalc(MAX, MOD);
        void Solve()
        {
            int N = Sc.NextInt();
            int M = Sc.NextInt();

            var d = CalcPrimeFactor(M);
            long ans = 1;
            foreach (var el in d)
            {
                ans = mc.Mul(ans, mc.Combination(el.Value + N - 1, el.Value));
            }
            Wr.WriteLine(ans);
        }
        private bool IsReactive => false; // TODO: reactive check !!
        IReadOnlyDictionary<long, int> CalcPrimeFactor(long val)
        {
            Dictionary<long, int> dic = new Dictionary<long, int>();
            for (long i = 2; i * i <= val; i++)
            {
                while (val % i == 0)
                {
                    if (!dic.ContainsKey(i))
                    {
                        dic.Add(i, 1);
                    }
                    else
                    {
                        dic[i]++;
                    }
                    val /= i;
                }
            }
            if (val > 1)
            {
                if (dic.ContainsKey(val))
                    dic[val]++;
                else
                    dic.Add(val, 1);
            }
            return dic;
        }
    }
    class ModCalc
    {
        private readonly int maxVal;
        private readonly int mod;
        private readonly long[] memoFact;
        private readonly long[] memoInvFact;

        public ModCalc(int maxVal, int mod)
        {
            this.maxVal = maxVal;
            this.mod = mod;
            this.memoFact = new long[maxVal + 1];
            this.memoFact[0] = 1;
            for (int i = 0; i < maxVal; i++)
            {
                this.memoFact[i + 1] = Mul(i + 1, this.memoFact[i]);
            }
            this.memoInvFact = new long[maxVal + 1];
            for (int i = 0; i < maxVal + 1; i++)
            {
                this.memoInvFact[i] = Inverse(this.memoFact[i]);
            }
        }

        /// <summary>
        /// ?mod??????
        /// </summary>
        /// <param name="left">???</param>
        /// <param name="right">???</param>
        /// <returns>????????</returns>
        public long Add(long left, long right)
            => (left % mod + right % mod) % mod;

        /// <summary>
        /// ?mod??????
        /// </summary>
        /// <param name="left">???</param>
        /// <param name="right">???</param>
        /// <returns>????????</returns>
        public long Sub(long left, long right)
            => Add(left, -right % mod + mod);

        /// <summary>
        /// ?mod??????
        /// </summary>
        /// <param name="left">???</param>
        /// <param name="right">???</param>
        /// <returns>????????</returns>
        public long Mul(long left, long right)
            => (left % mod) * (right % mod) % mod;

        /// <summary>
        /// ?mod??????
        /// </summary>
        /// <param name="left">???</param>
        /// <param name="right">???</param>
        /// <returns>????????</returns>
        public long Div(long left, long right)
            => Mul(left, Inverse(right));

        /// <summary>
        /// ?mod???????
        /// </summary>
        /// <param name="value">????</param>
        /// <returns>???????</returns>
        public long Inverse(long value)
            => PowMod(value, mod - 2);

        /// <summary>
        /// ?mod???????????????
        /// </summary>
        /// <param name="a">?</param>
        /// <param name="p">??</param>
        /// <returns>?mod??a^p</returns>
        public long PowMod(long a, long p)
        {
            if (p == 0)
            {
                return 1;
            }
            else if (p % 2 == 1)
            {
                return Mul(a, PowMod(a, p - 1));
            }
            else
            {
                var tmp = PowMod(a, p / 2);
                return Mul(tmp, tmp);
            }
        }

        /// <summary>
        /// ?mod???????
        /// </summary>
        /// <param name="N">???</param>
        /// <returns>?mod??N!</returns>
        public long Fact(int N) => memoFact[N];

        /// <summary>
        /// ?mod???????????
        /// </summary>
        /// <param name="N">??</param>
        /// <returns>?mod??N???</returns>
        public long InvFact(int N) => memoInvFact[N];

        /// <summary>
        /// ?mod????????
        /// </summary>
        /// <param name="n">???</param>
        /// <param name="r">???</param>
        /// <returns>?mod??nPr</returns>
        public long Permutation(int n, int r)
            => Fact(n) * InvFact(n - r);

        /// <summary>
        /// ?mod???????????
        /// </summary>
        /// <param name="n">???</param>
        /// <param name="r">???</param>
        /// <returns>?mod??nCr</returns>
        public long Combination(int n, int r)
            => Mul(Mul(Fact(n), InvFact(r)), InvFact(n - r));
    }
}