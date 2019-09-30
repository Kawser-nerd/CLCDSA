using System;
using System.Collections.Generic;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_023
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int r = int.Parse(input[0]);
            int c = int.Parse(input[1]);
            int k = int.Parse(input[2]);
            int n = int.Parse(Console.ReadLine());
            var candyPoses = new Pos[n];
            var rCnt = new int[r];
            var cCnt = new int[c];
            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split(' ');
                int rr = int.Parse(input[0]) - 1;
                int cc = int.Parse(input[1]) - 1;
                candyPoses[i] = new Pos(cc, rr);
                rCnt[rr]++;
                cCnt[cc]++;
            }

            var rCntArray = new long[k + 1];
            var cCntArray = new long[k + 1];
            for (int i = 0; i < r; i++)
            {
                if (rCnt[i] <= k) rCntArray[rCnt[i]]++;
            }
            for (int i = 0; i < c; i++)
            {
                if (cCnt[i] <= k) cCntArray[cCnt[i]]++;
            }

            long allPat = 0;
            for (int i = 0; i <= k; i++)
            {
                allPat += rCntArray[i] * cCntArray[k - i];
            }
            for(int i = 0; i < n; i++)
            {
                int baseCnt = rCnt[candyPoses[i].y] + cCnt[candyPoses[i].x];
                if (baseCnt == k) allPat--;
                else if (baseCnt == k + 1) allPat++;
            }

            Console.WriteLine(allPat);
        }
    }

    class Pos : IComparable
    {
        public int x, y;
        public Pos(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public int CompareTo(object obj)
        {
            Pos comparer = (Pos)obj;
            if (y < comparer.y
                || (y == comparer.y && x < comparer.x))
            {
                return -1;
            }
            else if (y == comparer.y && x == comparer.x)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
}