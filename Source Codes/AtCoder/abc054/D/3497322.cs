using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_054
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nab=ReadInts();
            var abcs = new int[nab[0]][];
            for(int i = 0; i < nab[0]; i++)
            {
                abcs[i] = ReadInts();
            }
            var posDict = new Dictionary<int, Dictionary<int, int>>();
            posDict.Add(0, new Dictionary<int, int>());
            posDict[0].Add(0, 0);
            for(int i = 0; i < nab[0]; i++)
            {
                var tempDict = new Dictionary<int, Dictionary<int, int>>();
                foreach(int a in posDict.Keys)
                {
                    foreach (int b in posDict[a].Keys)
                    {
                        int v = posDict[a][b] + abcs[i][2];
                        int newA = a + abcs[i][0];
                        int newB = b + abcs[i][1];
                        if (!tempDict.ContainsKey(newA))
                        {
                            tempDict.Add(newA, new Dictionary<int, int>());
                        }
                        tempDict[newA].Add(newB, v);
                    }
                }
                foreach(int a in tempDict.Keys)
                {
                    if (!posDict.ContainsKey(a))
                    {
                        posDict.Add(a, new Dictionary<int, int>());
                    }
                    foreach(int b in tempDict[a].Keys)
                    {
                        if (posDict[a].ContainsKey(b))
                        {
                            posDict[a][b]
                                = Math.Min(posDict[a][b], tempDict[a][b]);
                        }
                        else
                        {
                            posDict[a].Add(b, tempDict[a][b]);
                        }
                    }
                }
            }

            int res = int.MaxValue;
            for (int i = 1; i <= Math.Min(400 / nab[1], 400 / nab[2]); i++)
            {
                int a = nab[1] * i;
                int b = nab[2] * i;
                if (!posDict.ContainsKey(a)
                    || !posDict[a].ContainsKey(b)) continue;
                res = Math.Min(res, posDict[a][b]);
            }
            if (res == int.MaxValue)
            {
                Console.WriteLine(-1);
            }
            else
            {
                Console.WriteLine(res);
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