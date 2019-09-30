using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgrammingContest
{
    class MainClass : IDisposable
    {
        Scanner sc;
        Writer wr;
        string backPath = "..";
        char dirSep = System.IO.Path.DirectorySeparatorChar;
        string inFilePath = null;
        string outFilePath = null;
        public MainClass()
        {
            this.inFilePath = this.backPath
                            + this.dirSep
                            + this.backPath
                            + this.dirSep
                            + "in.txt";
            this.outFilePath = this.backPath
                             + this.dirSep
                             + this.backPath
                             + this.dirSep
                             + "out.txt";
        }
        static void Main(string[] args)
        {
            using (var mainClass = new MainClass())
            {
                //mainClass.MakeTestCase();
                mainClass.Solve();
            }
        }

        public void Dispose()
        {
            if (this.sc != null)
            {
                this.sc.Dispose();
                this.sc = null;
            }
            if (this.wr != null)
            {
                this.wr.Dispose();
                this.wr = null;
            }
        }

        void MakeTestCase()
        {
            Random rand = new Random();
            this.wr = new Writer(inFilePath);


        }

        void Solve()
        {
            this.wr = new Writer(this.isReactive);
            //this.wr = new Writer(this.outFilePath);
#if DEBUG
            if (!this.isReactive)
                this.sc = new Scanner(this.inFilePath);
            else
                this.sc = new Scanner();
#else
            this.sc = new Scanner();
#endif

            int N = sc.NextInt;
            int X = sc.NextInt;
            long[] w = new long[N].Select(e => sc.NextLong).ToArray();
            Array.Sort(w);
            var dic1 = new Dictionary<long, long>();
            var dic2 = new Dictionary<long, long>();
            int fir = N / 2, sec = N - fir;
            for (int i = 0; i < (1 << fir); i++)
            {
                long sum = 0;
                for (int j = 0; j < fir; j++)
                {
                    if ((i & (1 << j)) != 0)
                    {
                        sum += w[j];
                    }
                }
                if (!dic1.ContainsKey(sum))
                {
                    dic1.Add(sum, 1);
                }
                else
                {
                    dic1[sum]++;
                }
            }
            for (int i = 0; i < (1 << sec); i++)
            {
                long sum = 0;
                for (int j = 0; j < sec; j++)
                {
                    if ((i & (1 << j)) != 0)
                    {
                        sum += w[fir + j];
                    }
                }
                if (!dic2.ContainsKey(sum))
                {
                    dic2.Add(sum, 1);
                }
                else
                {
                    dic2[sum]++;
                }
            }
            long ans = 0;
            foreach (var p in dic1)
            {
                if (dic2.ContainsKey(X - p.Key))
                {
                    ans += p.Value * dic2[X - p.Key];
                }
            }
            wr.WriteLine(ans);
        }


        bool isReactive = false; // TODO: reactive check !!
    }

    class Writer : IDisposable
    {
        private System.IO.TextWriter writer;
        private StringBuilder sb;
        private bool isReactive;
        public Writer(string path) : this(new System.IO.StreamWriter(path))
        {
        }
        public Writer(bool isReactive) : this(null, isReactive)
        {
        }
        public Writer(System.IO.TextWriter writer = null, bool isReactive = false)
        {
            this.writer = (writer ?? Console.Out);
            this.isReactive = isReactive;
            if (!this.isReactive)
                this.sb = new StringBuilder();
        }
        public void Dispose()
        {
            if (!this.isReactive)
                this.writer.Write(sb.ToString());
            if (!this.writer.Equals(Console.Out))
                this.writer.Dispose();
        }
        public void Write(object val)
        {
            if (this.isReactive)
            {
                this.writer.Write(val.ToString());
                this.writer.Flush();
            }
            else
                this.sb.Append(val.ToString());
        }
        public void Write(string format, params object[] vals)
        {
            if (this.isReactive)
            {
                this.writer.Write(format, vals);
                this.writer.Flush();
            }
            else
                this.sb.AppendFormat(format, vals);
        }
        public void WriteLine(object val)
        {
            this.Write(val.ToString() + System.Environment.NewLine);
        }
        public void WriteLine(string format, params object[] vals)
        {
            this.Write(format + System.Environment.NewLine, vals);
        }
    }

    class Scanner : IDisposable
    {
        private Queue<string> buffer;
        private char[] sep;
        private System.IO.TextReader reader;
        public Scanner(string path) : this(new System.IO.StreamReader(path))
        {
        }
        public Scanner(System.IO.TextReader reader = null)
        {
            this.buffer = new Queue<string>();
            this.sep = new char[] { ' ' };
            this.reader = (reader ?? Console.In);
        }
        private void CheckBuffer()
        {
            if (this.buffer.Count == 0)
            {
                string str = string.Empty;
                while (string.IsNullOrEmpty(str))
                    str = this.reader.ReadLine();

                str.Split(this.sep).ToList()
                    .ForEach(el => this.buffer.Enqueue(el));
            }
        }

        public void Dispose()
        {
            if (!this.reader.Equals(Console.In))
                this.reader.Dispose();
        }

        public string Next
        {
            get
            {
                this.CheckBuffer();
                return this.buffer.Dequeue();
            }
        }

        public int NextInt
        {
            get
            {
                return int.Parse(this.Next);
            }
        }
        public double NextDouble
        {
            get
            {
                return double.Parse(this.Next);
            }
        }

        public long NextLong
        {
            get
            {
                return long.Parse(this.Next);
            }
        }

        public bool IsEnd
        {
            get
            {
                this.CheckBuffer();
                return this.buffer.Count == 0;
            }
        }
    }
}