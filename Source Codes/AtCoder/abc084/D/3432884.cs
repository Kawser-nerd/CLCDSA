using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_084
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int q = ReadInt();
            long[] likes = LikeNumbers(1, 100000);
            var cnts = new int[100000];
            int likeIndex = 0;
            cnts[0]= 0;
            for (int i = 1; i < cnts.Length; i++)
            {
                cnts[i] = cnts[i - 1];
                if (likeIndex < likes.Length
                    && i + 1 == likes[likeIndex])
                {
                    cnts[i]++;
                    likeIndex++;
                }
                //Console.WriteLine(cnts[i]);
            }
            var lrs = new int[q][];
            for(int i = 0; i < q; i++)
            {
                lrs[i] = ReadInts();
            }

            for(int i = 0; i < q; i++)
            {
                int val = cnts[lrs[i][1] - 1];
                if (lrs[i][0] - 2 >= 0)
                {
                    val -= cnts[lrs[i][0] - 2];
                }
                Console.WriteLine(val);
            }
        }

        static long[] LikeNumbers(long min, long max)
        {
            var likes = new List<long>();
            var primeDict = new Dictionary<long,bool>();
            primeDict.Add(2, true);
            for (long i = 3; i <= max; i += 2)
            {
                long rootI = (long)Math.Sqrt(i);
                bool isPrime = true;
                for (long j = 3; j <= rootI; j += 2)
                {
                    if (i % j == 0)
                    {
                        isPrime = false;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (isPrime)
                {
                    if (primeDict.ContainsKey((i + 1) / 2))
                    {
                        likes.Add(i);
                    }
                    primeDict.Add(i, true);
                }
            }
            return likes.ToArray();
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