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
        static int NumBits(int n)
        {
            int num = 0;
            while (n > 0)
            {
                if ((n & 1) != 0) { ++num; }
                n >>= 1;
            }
            return num;
        }
        static double Solve(double[] probs, int K)
        {
            int N = probs.Length;
            double max = 0;
            for (int i = 0; i < 1 << N; ++i)
            {
                if (NumBits(i) == K)
                {
                    var q = Enumerable.Range(0, N).Where(j => (i & (1 << j)) != 0).Select(j => probs[j]).ToArray();
                    var dp = new double[K + 1][];
                    dp[K] = new double[K / 2 + 1];
                    dp[K][0] = 1.0;
                    for (int j = K - 1; j >= 0; --j)
                    {
                        dp[j] = new double[K / 2 + 1];
                        for (int k = 0; k < K / 2 + 1; ++k)
                        {
                            double a = (k > 0) ? q[j] * dp[j + 1][k - 1] : 0;
                            double b = (1 - q[j]) * dp[j + 1][k];
                            dp[j][k] = a + b;
                        }
                    }
                    max = Math.Max(dp[0][K / 2], max);
                }
            }
            return max;
        }
        static void Main(string[] args)
        {
            using (var io = new FileIO("../../B-small-attempt0"))
            {
                while (io.Active())
                {
                    var values1 = io.ReadInts();
                    var values2 = io.ReadDoubles();
                    io.Write(Solve(values2, values1[1]));
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
