using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        // Not Solved ======================================--

        public int N;
        public List<Data> D;
        public int[] OrderLRight, OrderRLeft;

        public void Run()
        {
            N = Input.ReadInt();
            D = new List<Data>();
            for (int i = 0; i < N; i++)
            {
                var line = Input.ReadIntArray();
                D.Add(new Data { ID = i, L = line[0], R = line[1] });
            }

            D.Sort((d1, d2) => (-1) * d1.L.CompareTo(d2.L));
            OrderLRight = D.Select(d => d.ID).ToArray();
            D.Sort((d1, d2) => d1.R.CompareTo(d2.R));
            OrderRLeft = D.Select(d => d.ID).ToArray();
            D.Sort((d1, d2) => d1.ID.CompareTo(d2.ID));

            long ret1 = Solve(1);
            long ret2 = Solve(-1);
            
            Console.WriteLine(Math.Max(ret1, ret2));
        }

        public long Solve(int firstDirection)
        {
            long ret = 0;

            bool[] flags = new bool[N];
            for (int i = 0; i < N; i++) flags[i] = false;
            int pos = 0;
            int li = 0;
            int ri = 0;
            int direction = firstDirection;

            while (true)
            {
                if (direction == 1)
                {
                    if (ri == N) break;
                    int i = OrderLRight[ri];
                    if (!flags[i])
                    {
                        int newpos = D[i].L;
                        if (newpos <= pos) break;
                        ret += Math.Abs(pos - newpos);
                        Console.Error.WriteLine("=> {0}: {1}->{2}", i, pos, newpos);
                        pos = newpos;
                        direction *= -1;
                        flags[i] = true;
                    }
                    ri++;
                }
                else
                {
                    if (li == N) break;
                    int i = OrderRLeft[li];
                    if (!flags[i])
                    {
                        int newpos = D[i].R;
                        if (newpos >= pos) break;
                        ret += Math.Abs(pos - newpos);
                        Console.Error.WriteLine("<= {0}: {1}->{2}", i, pos, newpos);
                        pos = newpos;
                        direction *= -1;
                        flags[i] = true;
                    }
                    li++;
                }

            }

            ret += Math.Abs(pos);

            Console.Error.WriteLine("-----");
            return ret;
        }

    }

    // libs ----------
    class Data
    {
        public int ID;
        public int L;
        public int R;
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