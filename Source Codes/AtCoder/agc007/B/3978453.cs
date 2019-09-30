using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _007_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] pArray = ReadInts();
            var aArray = new int[n];
            for(int i = 0; i < n; i++)
            {
                aArray[i] = n * i + 1;
            }
            var bArray = new int[n];
            bArray[n - 1] = 1;
            bool lower = true;
            var lowerList = new List<int>();
            var upperList = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (pArray[i] == n)
                {
                    lower = false;
                    continue;
                }
                if (lower)
                {
                    lowerList.Add(pArray[i]);
                }
                else
                {
                    upperList.Add(pArray[i]);
                }
            }
            lowerList.Reverse();
            int baseVal = bArray[n - 1] + aArray[n - 1];
            int val = baseVal - 1;
            for(int i = 0; i < lowerList.Count; i++)
            {
                bArray[lowerList[i] - 1] = val - aArray[lowerList[i] - 1];
                val--;
            }
            val = baseVal + 1;
            for (int i = 0; i < upperList.Count; i++)
            {
                bArray[upperList[i] - 1] = val - aArray[upperList[i] - 1];
                val++;
            }
            for(int i = 0; i < n; i++)
            {
                Console.Write(aArray[i]+" ");
            }
            Console.WriteLine();
            for (int i = 0; i < n; i++)
            {
                Console.Write(bArray[i]+" ");
            }
            Console.WriteLine();
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