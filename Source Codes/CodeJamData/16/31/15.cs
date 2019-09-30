using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        struct Party
        {
            public char c;
            public int n;
        }
        static IEnumerable<string> Solve(int[] P)
        {
            int N = P.Length;
            int sum = P.Sum();
            var parties = Enumerable.Range(0, N).Select(i => new Party { c = (char)('A' + i), n = P[i] }).ToArray();
            var list = new List<string>();
            while (sum > 0)
            {
                var sb = new StringBuilder();
                for (int i = 0; i < 2; ++i)
                {
                    if (i == 0 || (sum != 0 && sum != 2 && sum != 4))
                    {
                        Array.Sort(parties, (a, b) => (b.n - a.n));
                        sb.Append(parties[0].c);
                        --parties[0].n;
                        --sum;
                    }
                }
                list.Add(sb.ToString());
            }
            return list;
        }
        static void Main(string[] args)
        {
            using (var io = new FileIO("../../A-large"))
            {
                while (io.Active())
                {
                    int N = io.ReadInt();
                    int[] P = io.ReadInts();
                    io.Write(string.Join(" ", Solve(P)));
                }
            }
        }
    }
    class FileIO : IDisposable
    {
        private readonly StreamReader sr;
        private readonly StreamWriter sw;
        private readonly StringBuilder sb;
        private readonly int T;
        private int i = 0;
        public FileIO(string filename)
        {
            sr = new StreamReader(filename + ".in");
            sw = new StreamWriter(filename + ".out");
            sb = new StringBuilder();
            T = int.Parse(sr.ReadLine());
        }
        public void Dispose()
        {
            sw.Close();
            sr.Close();
        }
        public string ReadString()
        {
            string str = sr.ReadLine();
            sb.AppendLine(str);
            return str;
        }
        public string[] ReadStrings() { return ReadString().Split(); }
        public int ReadInt() { return int.Parse(ReadString()); }
        public int[] ReadInts() { return Array.ConvertAll(ReadString().Split(), int.Parse); }
        public double ReadDouble() { return double.Parse(ReadString()); }
        public double[] ReadDoubles() { return Array.ConvertAll(ReadString().Split(), double.Parse); }
        public void Read(out int arg1, out int arg2) { string[] args = ReadString().Split(); arg1 = int.Parse(args[0]); arg2 = int.Parse(args[1]); }
        public void Read(out int arg1, out int arg2, out int arg3) { string[] args = ReadString().Split(); arg1 = int.Parse(args[0]); arg2 = int.Parse(args[1]); arg3 = int.Parse(args[2]); }
        public void Read(out char arg1, out int arg2, out int arg3)
        {
            string[] args = ReadString().Split();
            arg1 = args[0][0];
            arg2 = int.Parse(args[1]);
            arg3 = int.Parse(args[2]);
        }
        public void Read(out double arg1) { string[] args = ReadString().Split(); arg1 = double.Parse(args[0]); }
        public void Read(out double arg1, out double arg2) { string[] args = ReadString().Split(); arg1 = double.Parse(args[0]); arg2 = double.Parse(args[1]); }
        public void Read(out double arg1, out double arg2, out double arg3) { string[] args = ReadString().Split(); arg1 = double.Parse(args[0]); arg2 = double.Parse(args[1]); arg3 = double.Parse(args[2]); }
        public bool Active() { return i < T; }
        public void Write(object result)
        {
            ++i;
            sw.WriteLine("Case #{0}: {1}", i, result);
            Debug.WriteLine("--- Case #{0} ---", i);
            Debug.WriteLine(sb.ToString().TrimEnd());
            Debug.WriteLine("----------------", i);
            Debug.WriteLine(result);
            Debug.WriteLine("----------------", i);
            Debug.WriteLine("");
            sb.Clear();
        }
    }
}
