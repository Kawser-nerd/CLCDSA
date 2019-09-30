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
        class Pancake
        {
            public double R;
            public double H;
            public Pancake(double[] args)
            {
                R = args[0];
                H = args[1];
            }
        }
        static double Solve(int N, int K, Pancake[] pancakes)
        {
            var stacks = pancakes.Take(K).ToArray();
            double R = stacks.Max(stack => stack.R);
            for (int i = K; i < N; ++i)
            {
                double r1 = stacks.Last().R;
                double h1 = stacks.Last().H;
                double r2 = pancakes[i].R;
                double h2 = pancakes[i].H;
                if (r2 * r2 - R * R > 2.0 * (r1 * h1 - r2 * h2))
                {
                    R = r2;
                    stacks[K - 1].R = r2;
                    stacks[K - 1].H = h2;
                }
            }
            return stacks.Sum(stack => 2.0 * Math.PI * stack.R * stack.H) + Math.PI * R * R;
        }
        static void Main(string[] args)
        {
            using (var io = new FileIO("../A-large"))
            {
                while (io.Active())
                {
                    int[] args1 = io.ReadInts();
                    int N = args1[0];
                    int K = args1[1];
                    var pancakes = new Pancake[N];
                    for (int i = 0; i < N; ++i) { pancakes[i] = new Pancake(io.ReadDoubles()); }
                    io.Write(Solve(N, K, pancakes.OrderByDescending(pancake => pancake.R * pancake.H).ToArray()));
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
