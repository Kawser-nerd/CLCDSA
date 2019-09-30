using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_080
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nc = ReadInts();
            var stc = new int[nc[0]][];
            for (int i = 0; i < nc[0]; i++)
            {
                stc[i] = ReadInts();
            }
            Array.Sort(stc, (a, b) => a[0] - b[0]);
            var vList = new List<int[]>();
            for(int i = 0; i < stc.Length; i++)
            {
                bool canRec = false;
                for(int j = 0; j < vList.Count; j++)
                {
                    if ((vList[j][1]==stc[i][2]&&vList[j][0]==stc[i][0])
                        ||vList[j][0] < stc[i][0])
                    {
                        vList[j][0] = stc[i][1];
                        vList[j][1] = stc[i][2];
                        canRec = true;
                        break;
                    }
                }
                if (!canRec)
                {
                    vList.Add(new int[2] { stc[i][1], stc[i][2] });
                }
            }
            Console.WriteLine(vList.Count);
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