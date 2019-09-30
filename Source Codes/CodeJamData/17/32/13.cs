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
        enum Parent
        {
            Cameron,
            Jamie,
        }
        class Activity
        {
            public readonly int s;
            public readonly int e;
            public readonly Parent p;
            public Activity(int s, int e, Parent p)
            {
                this.s = s;
                this.e = e;
                this.p = p;
            }
        }
        static int Solve(Activity[] activities)
        {
            int N = activities.Length;
            int count = 0;
            var c1 = new List<int>();
            var j1 = new List<int>();
            for (int i = 1; i < N; ++i)
            {
                var a = activities[i - 1];
                var b = activities[i];
                if (a.p == Parent.Cameron && b.p == Parent.Cameron)
                {
                    c1.Add(b.s - a.e);
                }
                else if (a.p == Parent.Jamie && b.p == Parent.Jamie)
                {
                    j1.Add(b.s - a.e);
                }
                else
                {
                    ++count;
                }
            }
            {
                var a = activities[0];
                var b = activities[N - 1];
                if (a.p == Parent.Cameron && b.p == Parent.Cameron)
                {
                    c1.Add(a.s + 1440 - b.e);
                }
                else if (a.p == Parent.Jamie && b.p == Parent.Jamie)
                {
                    j1.Add(a.s + 1440 - b.e);
                }
                else
                {
                    ++count;
                }
            }
            var c2 = c1.OrderBy(x => x).ToArray();
            var j2 = j1.OrderBy(x => x).ToArray();
            {
                int sum = activities.Where(a => a.p == Parent.Cameron).Sum(a => a.e - a.s);
                for (int i = 0; i < c2.Length; ++i)
                {
                    sum += c2[i];
                    if (sum > 720) { return (c2.Length - i) * 2 + count; }
                }
            }
            {
                int sum = activities.Where(a => a.p == Parent.Jamie).Sum(a => a.e - a.s);
                for (int i = 0; i < j2.Length; ++i)
                {
                    sum += j2[i];
                    if (sum > 720) { return (j2.Length - i) * 2 + count; }
                }
            }
            return count;
        }
        static void Main(string[] args)
        {
            using (var io = new FileIO("../B-large"))
            {
                while (io.Active())
                {
                    int[] args1 = io.ReadInts();
                    int C = args1[0];
                    int J = args1[1];
                    var activities = new Activity[C + J];
                    for (int i = 0; i < C + J; ++i)
                    {
                        int[] args2 = io.ReadInts();
                        activities[i] = (i < C) ? new Activity(args2[0], args2[1], Parent.Cameron)
                                                : new Activity(args2[0], args2[1], Parent.Jamie);
                    }
                    Array.Sort(activities, (a, b) => (a.s - b.s));
                    io.Write(Solve(activities));
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
