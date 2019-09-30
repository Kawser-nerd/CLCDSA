using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int A, B, C;
        public Dictionary<Tuple<int, int, int>, int> Dic;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                A = line[0];
                B = line[1];
                C = line[2];
            }
            
            Console.WriteLine(Solve());
        }

        public int Solve()
        {
            int count = 0;
            Dic = new Dictionary<Tuple<int, int, int>, int>();
            while (true)
            {
                // Judge & Memo
                var tpl = Tuple.Create(A, B, C);
                if (Dic.ContainsKey(tpl)) return -1;
                if ((A % 2 == 1) || (B % 2 == 1) || (C % 2 == 1)) return count;
                Dic.Add(tpl, 0);

                // Action
                int a = B / 2 + C / 2;
                int b = A / 2 + C / 2;
                int c = A / 2 + B / 2;
                A = a;
                B = b;
                C = c;
                count++;

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