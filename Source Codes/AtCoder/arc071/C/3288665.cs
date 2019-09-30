using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long MOD = 1000000007;
        public string S, T;
        public int Q;
        public int[] AS, BS, AT, BT;
        public void Run()
        {
            S = Console.ReadLine();
            T = Console.ReadLine();
            Q = Input.ReadInt();

            AS = new int[S.Length];
            AT = new int[T.Length];

            for (int i = 0; i < S.Length; i++)
            {
                if (S[i] == 'A') AS[i]++;
                else AS[i]--;
                if (i > 0) AS[i] += AS[i - 1];
            }

            for (int i = 0; i < T.Length; i++)
            {
                if (T[i] == 'A') AT[i]++;
                else AT[i]--;
                if (i > 0) AT[i] += AT[i - 1];
            }

            for (int q = 0; q < Q; q++)
            {
                var line = Input.ReadIntArray();
                int sL = line[0] - 1;
                int sR = line[1] - 1;
                int tL = line[2] - 1;
                int tR = line[3] - 1;

                int sa = AS[sR] - (sL == 0 ? 0 : AS[sL - 1]);
                int sb = AT[tR] - (tL == 0 ? 0 : AT[tL - 1]);

                sa = (sa + 3 * 1000000) % 3;
                sb = (sb + 3 * 1000000) % 3;

                Console.WriteLine(sa == sb ? "YES" : "NO");
            }




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