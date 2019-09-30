using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_088
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var marchCnt = new ulong[5];
            for(int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                switch (s[0])
                {
                    case 'M':
                        marchCnt[0]++;
                        break;
                    case 'A':
                        marchCnt[1]++;
                        break;
                    case 'R':
                        marchCnt[2]++;
                        break;
                    case 'C':
                        marchCnt[3]++;
                        break;
                    case 'H':
                        marchCnt[4]++;
                        break;
                }
            }

            ulong allCnt = 0;
            for(int i = 0; i < 3; i++)
            {
                for(int j = i + 1; j < 4; j++)
                {
                    for(int k = j + 1; k < 5; k++)
                    {
                        allCnt += marchCnt[i] * marchCnt[j] * marchCnt[k];
                    }
                }
            }

            Console.WriteLine(allCnt);
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