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
        static bool Paint(char[][] rows, int r, int c, int R, int C, char x)
        {
            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    if (rows[r + i][c + j] != '?' && rows[r + i][c + j] != x) { return false; }
                }
            }
            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    rows[r + i][c + j] = x;
                }
            }
            return true;
        }
        struct Area
        {
            public int i;
            public int j;
            public int r;
            public int c;
        }
       static string[] Solve(char[][] rows)
        {
            int R = rows.Length;
            int C = rows[0].Length;
            var areas = new List<Area>[26];
            var list = new List<Tuple<char, int, int>>();
            for (int i = 0; i < 26; ++i) { areas[i] = new List<Area>(); }
            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    if (rows[i][j] != '?') { list.Add(Tuple.Create(rows[i][j], i, j)); }
                }
            }
            for (int r = 1; r <= R; ++r)
            {
                for (int c = 1; c <= C; ++c)
                {
                    for (int i = 0; i + r <= R; ++i)
                    {
                        for (int j = 0; j + c <= C; ++j)
                        {
                            var tuples = list.Where(p => i <= p.Item2 && p.Item2 < i + r && j <= p.Item3 && p.Item3 < j + c);
                            if (tuples.Count() == 1)
                            {
                                char x = tuples.ElementAt(0).Item1;
                                areas[x - 'A'].Add(new Area { i = i, j = j, r = r, c = c });
                            }
                        }
                    }
                }
            }
            for (char x = 'A'; x <= 'Z'; ++x)
            {
                foreach (var area in areas[x - 'A'].OrderByDescending(area => area.r * area.c))
                {
                    if (Paint(rows, area.i, area.j, area.r, area.c, x)) { break; }
                }
            }
            return Array.ConvertAll(rows, row => new string(row));
        }
        static void Main(string[] args)
        {
            using (var io = new FileIO("../A-small-attempt0"))
            {
                while (io.Active())
                {
                    int[] values = io.ReadInts();
                    char[][] rows = new char[values[0]][];
                    for (int i = 0; i < rows.Length; ++i) { rows[i] = io.ReadString().ToCharArray(); }
                    io.Write(string.Join("\r\n", Solve(rows)));
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
            sw.WriteLine("Case #{0}:", i);
            sw.WriteLine(result);
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
