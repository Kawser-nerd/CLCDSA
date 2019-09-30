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

            N = sc.NextInt;
            t = new int[N].Select(el => sc.NextInt).ToArray();
            v = new int[N].Select(el => sc.NextInt).ToArray();
            r = new double[N + 1];
            for (int i = 1; i < N; i++)
            {
                r[i] = Math.Min(v[i - 1], v[i]);
            }
            r[0] = r[N] = 0;
            for (int i = 0; i < N; i++)
            {
                r[i + 1] = Math.Min(r[i + 1], r[i] + t[i]);
            }
            for (int i = N; i > 0; i--)
            {
                r[i - 1] = Math.Min(r[i - 1], r[i] + t[i - 1]);
            }
            double ans = 0;
            for (int i = 0; i < N; i++)
            {
                double buf = 0;
                double low = 0, high = t[i];
                double ma;
                for (int j = 0; j < 100; j++)
                {
                    double mid = (low + high) / 2;
                    ma = r[i] + mid;
                    if (ma > v[i])
                    {
                        high = mid;
                    }
                    else
                    {
                        if (ma - (t[i] - mid) <= r[i + 1])
                        {
                            low = mid;
                        }
                        else
                        {
                            high = mid;
                        }
                    }
                }
                double upTime = low;
                ma = r[i] + upTime;
                double downTime = ma - r[i + 1];
                buf = (r[i] + ma) * upTime / 2;
                buf += (ma + r[i + 1]) * downTime / 2;
                buf += (t[i] - upTime - downTime) * ma;
                ans += buf;
            }
            wr.WriteLine(ans);
        }


        void Calc(int now)
        {
            
        }
        int N;
        double[] r;
        int[] t, v;
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