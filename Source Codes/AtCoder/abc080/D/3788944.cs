using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, M;
        public List<Data> D;
        public long MOD = 1000000007;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
            }

            D = new List<Data>();
            for (int i = 0; i < N; i++)
            {

                var line = Input.ReadIntArray();
                int s = line[0];
                int t = line[1];
                int c = line[2];

                var d = new Data(s, t, c);
                D.Add(d);
            }

            D.Sort(Data.CompareTo);

            for (int i = 1; i <= 30; i++)
            {
                if (Simulate(i))
                {
                    Console.WriteLine(i);
                    return;
                }
            }
        }

        public bool Simulate(int n)
        {
            var cs = new int[n];
            var ts = new int[n];
            for (int i = 0; i < n; i++)
            {
                cs[i] = -1;
                ts[i] = -1;
            }

            foreach (var d in D)
            {
                int ii = -1;
                int ls = -2;

                for (int i = 0; i < n; i++)
                {
                    // ????????????OK??????????????
                    if (ts[i] < d.s || (ts[i] == d.s && cs[i] == d.c))
                    {
                        if (ls < ts[i])
                        {
                            ii = i;
                            ls = ts[i];
                        }
                    }
                }

                if (ii == -1) return false;
                else
                {
                    cs[ii] = d.c;
                    ts[ii] = d.t;
                    // Console.Error.WriteLine($"{ii} {d.c} {d.t}");
                }
            }

            return true;
        }
    }

    // libs ----------
    // ????
    class Data
    {
        public int s;
        public int t;
        public int c;

        public Data(int s, int t, int c)
        {
            this.s = s;
            this.t = t;
            this.c = c;
        }

        // Sort?????Comparer?????????
        public static int CompareTo(Data d1, Data d2)
        {
            int result = d1.s.CompareTo(d2.s);
            return result;
        }
    }

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}