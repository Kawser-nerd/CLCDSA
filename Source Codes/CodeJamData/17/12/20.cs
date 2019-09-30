using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static long Div1(long a, long b) { return (a + b - 1) / b; }
        static long Div2(long a, long b) { return a / b; }
        static int Solve(int N, int P, long[] R, List<long>[] Q)
        {
            int count = 0;
            for (int i = 0; i < Q[0].Count;)
            {
                bool removed = false;
                long a = Div1(Q[0][i] * 10, R[0] * 11);
                long b = Div2(Q[0][i] * 10, R[0] * 9);
                for (long n = a; n <= b && !removed; ++n)
                {
                    var indices = new int[N];
                    indices[0] = i;
                    for (int j = 1; j < N; ++j)
                    {
                        var qs = Enumerable.Range(0, Q[j].Count).Where(k => R[j] * n * 9 <= Q[j][k] * 10 && Q[j][k] * 10 <= R[j] * n * 11);
                        indices[j] = (qs.Count() > 0) ? qs.ElementAt(0) : -1;
                    }
                    if (indices.All(index => index >= 0))
                    {
                        for (int j = 0; j < N; ++j)
                        {
                            Q[j].RemoveAt(indices[j]);
                        }
                        ++count;
                        removed = true;
                    }
                }
                if (!removed) { ++i; }
            }
            return count;
        }
        static void Main(string[] args)
        {
            using (var io = new FileIO("../B-large"))
            {
                while (io.Active())
                {
                    int[] values = io.ReadInts();
                    int N = values[0];
                    int P = values[1];
                    long[] R = io.ReadLongs();
                    var Q = new List<long>[N];
                    for (int i = 0; i < N; ++i)
                    {
                        Q[i] = io.ReadLongs().ToList();
                        Q[i].Sort();
                    }
                    io.Write(Solve(N, P, R, Q));
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
        public long ReadLong() { return long.Parse(ReadString()); }
        public long[] ReadLongs() { return Array.ConvertAll(ReadString().Split(), long.Parse); }
        public double ReadDouble() { return double.Parse(ReadString()); }
        public double[] ReadDoubles() { return Array.ConvertAll(ReadString().Split(), double.Parse); }
        public void Read(out int arg1, out int arg2, out int arg3, out int arg4)
        {
            string[] args = ReadString().Split();
            arg1 = int.Parse(args[0]);
            arg2 = int.Parse(args[1]);
            arg3 = int.Parse(args[2]);
            arg4 = int.Parse(args[3]);
        }
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
