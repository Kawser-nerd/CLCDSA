using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_027
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Read();
            var list = new List<int>();
            int now = 0;
            int sum = 0;
            for(int i = s.Length-1; i >=0; i--)
            {
                if (s[i] == '+')
                {
                    now++;
                }
                else if (s[i] == '-')
                {
                    now--;
                }
                else
                {
                    list.Add(now);
                    sum += now;
                }
            }
            int max = int.MinValue;
            list.Sort();
            int subSum = 0;
            for (int i = 0; i < list.Count / 2; i++)
            {
                subSum += list[i];
            }
            Console.WriteLine(sum - subSum * 2);
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