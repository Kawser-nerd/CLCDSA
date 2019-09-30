using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int H, W, N;
        public long MOD = 1000000007;

        public void Run()
        {
            // H?W, X?Y???????
            {
                var line = Input.ReadIntArray();
                W = line[0];
                H = line[1];
                N = line[2];
            }

            var O = new List<int>[H];
            for (int i = 0; i < H; i++)
            {
                O[i] = new List<int>();
                // ??????
                O[i].Add(W);
            }

            for (int i = 0; i < N; i++)
            {
                var line = Input.ReadIntArray();
                int x = line[0] - 1;
                int y = line[1] - 1;
                O[y].Add(x);
            }

            for (int y = 0; y < H; y++)
            {
                O[y].Sort();
            }

            // ?????????????????W?????
            int[] T = new int[H];
            for (int y = 0; y < H; y++)
            {
                T[y] = W;
            }

            // ???????????
            int f = 0;
            for (int y = 0; y < H; y++)
            {
                foreach (var x in O[y])
                {
                    if (x > f)
                    {
                        T[y] = x;
                        break;
                    }
                }

                if (y < H - 1)
                {
                    f++;
                    var s = new HashSet<int>(O[y+1]);
                    while (s.Contains(f))
                    {
                        f++;
                    }

                    // ??????????
                    if (f >= W) break;
                }
            }

            Console.WriteLine(T.Min());
        }
    }

    // libs ----------
    

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