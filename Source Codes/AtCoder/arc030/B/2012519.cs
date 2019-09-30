using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgrammingContest
{
    class Writer : IDisposable
    {
        private System.IO.TextWriter writer;
        private StringBuilder sb;
        private bool isReactive;
        public Writer(string path) 
            : this(new System.IO.StreamWriter(path))
        {
        }
        public Writer(bool isReactive) 
            : this(null, isReactive)
        {
        }
        public Writer(System.IO.TextWriter writer = null,
                        bool isReactive = false)
        {
            this.writer = (writer ?? Console.Out);
            this.isReactive = isReactive;
            if (!this.isReactive)
            {
                this.sb = new StringBuilder();
            }
        }
        public void Dispose()
        {
            if (!this.isReactive)
            {
                this.writer.Write(sb.ToString());
            }
            if (!this.writer.Equals(Console.Out))
            {
                this.writer.Dispose();
            }
        }
        public void Write(object val)
        {
            if (this.isReactive)
            {
                this.writer.Write(val.ToString());
                this.writer.Flush();
            }
            else
            {
                this.sb.Append(val.ToString());
            }
        }
        public void Write(string format, params object[] vals)
        {
            if (this.isReactive)
            {
                this.writer.Write(format, vals);
                this.writer.Flush();
            }
            else
            {
                this.sb.AppendFormat(format, vals);
            }
        }
        public void WriteLine(object val = null)
        {
            this.Write((val ?? string.Empty).ToString() + System.Environment.NewLine);
        }
        public void WriteLine(int val)
        {
            this.WriteLine(val.ToString());
        }
        public void WriteLine(long val)
        {
            this.WriteLine(val.ToString());
        }
        public void WriteLine(string val)
        {
            this.WriteLine((object)val);
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
        public Scanner(string path, char[] sep = null) 
            : this(new System.IO.StreamReader(path), sep)
        {
        }
        public Scanner(System.IO.TextReader reader = null,
                        char[] sep = null)
        {
            this.buffer = new Queue<string>();
            this.sep = (sep ?? new char[] { ' ' });
            this.reader = (reader ?? Console.In);
        }
        private void CheckBuffer()
        {
            if (this.buffer.Count == 0 && this.reader.Peek() != -1)
            {
                string str = string.Empty;
                for (; string.IsNullOrEmpty(str);
                    str = this.reader.ReadLine()) ;

                str.Split(this.sep).ToList()
                   .ForEach(el => this.buffer.Enqueue(el));
            }
        }

        public void Dispose()
        {
            if (!this.reader.Equals(Console.In))
            {
                this.reader.Dispose();
            }
        }

        public string Next
        {
            get
            {
                this.CheckBuffer();
                return this.buffer.Dequeue();
            }
        }
        public string[] GetStringArray(int N)
        {
            return Enumerable.Range(0, N)
                             .Select(e => this.Next)
                             .ToArray();
        }

        public int NextInt
        {
            get
            {
                return int.Parse(this.Next);
            }
        }
        public int[] GetIntArray(int N)
        {
            return Enumerable.Range(0, N)
                             .Select(e => this.NextInt)
                             .ToArray();
        }

        public double NextDouble
        {
            get
            {
                return double.Parse(this.Next);
            }
        }
        public double[] GetdoubleArray(int N)
        {
            return Enumerable.Range(0, N)
                             .Select(e => this.NextDouble)
                             .ToArray();
        }

        public long NextLong
        {
            get
            {
                return long.Parse(this.Next);
            }
        }
        public long[] GetLongArray(int N)
        {
            return Enumerable.Range(0, N)
                             .Select(e => this.NextLong)
                             .ToArray();
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

    class MainClass : IDisposable
    {
        Scanner sc;
        Writer wr;
        string backPath = "..";
        char dirSep = System.IO.Path.DirectorySeparatorChar;
        string inFilePath = string.Empty;
        string outFilePath = string.Empty;
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

            this.wr = new Writer(this.isReactive);
            //this.wr = new Writer(this.outFilePath);
#if DEBUG
            if (!this.isReactive)
            {
                this.sc = new Scanner(this.inFilePath);
            }
            else
            {
                this.sc = new Scanner();
            }
#else
            this.sc = new Scanner();
#endif
        }
        static void Main(string[] args)
        {
            using (var mainClass = new MainClass())
            {
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
            if (this.wr != null)
            {
                this.wr.Dispose();
            }
            this.wr = new Writer(inFilePath);


        }

        List<int>[] G;
        HashSet<int> hSet;
        int st;

        int Dfs(int now, int prev)
        {
            int sum = 0;
            foreach (var el in G[now])
            {
                if (el != prev)
                {
                    sum += Dfs(el, now);
                }
            }
            if (now != st)
            {
                if (sum > 0)
                {
                    sum++;
                }
                else if (hSet.Contains(now))
                {
                    sum++;
                }
            }
            return sum;
        }

        void Solve()
        {
            int n = sc.NextInt;
            G = new List<int>[n].Select(e => new List<int>()).ToArray();
            st = sc.NextInt - 1;
            hSet = new HashSet<int>();
            for (int i = 0; i < n; i++)
            {
                if (sc.NextInt == 1)
                {
                    hSet.Add(i);
                }
            }
            for (int i = 0; i < n - 1; i++)
            {
                int a = sc.NextInt - 1;
                int b = sc.NextInt - 1;
                G[a].Add(b);
                G[b].Add(a);
            }
            wr.WriteLine(Dfs(st, -1) * 2);
        }

        bool isReactive = false; // TODO: reactive check !!
    }
}