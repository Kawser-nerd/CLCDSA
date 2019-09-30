using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _006_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nx = ReadInts();
            int n = nx[0];
            int x = nx[1];
            if (x == 1 || x == 2 * n - 1)
            {
                Console.WriteLine("No");
                return;
            }

            var nums = new List<int>();
            for (int i = 0; i < 2 * n - 1; i++)
            {
                nums.Add(i + 1);
            }
            if (n > 2)
            {
                if (x == 2 * n - 2)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        nums.RemoveAt(x - 3);
                    }
                    nums.Insert(n - 2, x - 2);
                    nums.Insert(n - 1, x);
                    nums.Insert(n, x + 1);
                    nums.Insert(n + 1, x - 1);
                }
                else
                {
                    for (int i = 0; i < 4; i++)
                    {
                        nums.RemoveAt(x - 2);
                    }
                    nums.Insert(n - 2, x + 1);
                    nums.Insert(n - 1, x);
                    nums.Insert(n, x - 1);
                    nums.Insert(n + 1, x + 2);
                }
            }
            Console.WriteLine("Yes");
            for(int i = 0; i < nums.Count; i++)
            {
                Console.WriteLine(nums[i]);
            }
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}