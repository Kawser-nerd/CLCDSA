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
        static string Solve(int B, long M)
        {
            if ((1L << (B - 2)) < M) { return "IMPOSSIBLE"; }
            var sb = new StringBuilder("POSSIBLE\r\n");
            var slides = new char[B][];
            for (int i = 0; i < B - 1; ++i)
            {
                slides[i] = new char[B];
                for (int j = 0; j < B; ++j)
                {
                    if (j + 1 < B)
                    {
                        slides[i][j] = (i < j) ? '1' : '0';
                    }
                    else
                    {
                        if (i == 0)
                        {
                            if ((1L << (B - 2)) == M)
                            {
                                slides[i][j] = '1';
                                --M;
                            }
                            else
                            {
                                slides[i][j] = '0';
                            }
                        }
                        else
                        {
                            slides[i][j] = ((M & (1L << (i - 1))) != 0) ? '1' : '0';
                        }
                    }
                }
                sb.Append(slides[i]);
                sb.Append("\r\n");
            }
            sb.Append(new string('0', B));
            return sb.ToString();
        }
        static void Main(string[] args)
        {
            using (var io = new FileIO("../../B-large"))
            {
                while (io.Active())
                {
                    int B;
                    long M;
                    io.Read(out B, out M);
                    io.Write(Solve(B, M));
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
        public void Read(out int arg1, out long arg2)
        {
            string[] args = ReadString().Split();
            arg1 = int.Parse(args[0]);
            arg2 = long.Parse(args[1]);
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
