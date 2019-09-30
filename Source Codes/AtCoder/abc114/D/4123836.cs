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

        void Solve()
        {
            int N = Sc.NextInt();
            Dictionary<int, int> divs = Enumerable.Range(0, N).Select(el =>
            {
                Dictionary<int, int> dic = new Dictionary<int, int>();
                el++;
                for (int j = 2; j * j <= el; j++)
                {
                    while (el % j == 0)
                    {
                        if (!dic.ContainsKey(j))
                        {
                            dic.Add(j, 0);
                        }
                        dic[j]++;
                        el /= j;
                    }
                }
                if (el != 1)
                {
                    if (!dic.ContainsKey(el))
                    {
                        dic.Add(el, 0);
                    }
                    dic[el]++;
                }
                return dic;
            }).SelectMany(e => e.AsEnumerable())
              .ToLookup(e => e.Key)
              .ToDictionary(e => e.Key, e => e.Select(el => el.Value).Sum());

            long[] dp = new long[77];
            dp[1] = 1;
            foreach (var p in divs)
            {
                for (int i = dp.Length - 1; i >= 0; i--)
                {
                    for (int j = p.Value - 1; j >= 0; j--)
                    {
                        if (i * (j + 2) <= 75)
                        {
                            dp[i * (j + 2)] += dp[i];
                        }
                    }
                }
            }
            Wr.WriteLine(dp[75]);
        }
        IDictionary<TKey,TValue> Merge<TKey, TValue>(
            IEnumerable<IDictionary<TKey, TValue>> source, 
            Func<IEnumerable<TValue>, TValue> aggregate)
            => source.
                SelectMany(e => e.AsEnumerable()).
                ToLookup(e => e.Key).
                ToDictionary(e => e.Key, e => aggregate(e.Select(el => el.Value)));

        private bool IsReactive => false; // TODO: reactive check !!
    }
}