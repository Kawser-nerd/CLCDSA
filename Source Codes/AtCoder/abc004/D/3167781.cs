using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.D_Challenge
{
    class ABC_004
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
            int g = int.Parse(input[1]);
            int b = int.Parse(input[2]);
            int rRight = (r - 1) / 2 - 100;
            int bLeft = -(b - 1) / 2 + 100;

            int minCnt = -1;
            for (int i = -650; i <= 325; i++)
            {
                int rR = i <= rRight ? i - 1 : rRight;
                int bL = bLeft <= i + g - 1 ? i + g : bLeft;

                int cnt = CalculateCount(
                    rR - r + 1, rR,
                    i, i + g - 1,
                    bL, bL + b - 1);
                if (minCnt == -1 || cnt < minCnt)
                {
                    minCnt = cnt;
                }
                //Console.WriteLine(rR + " " + i + " " + bL);
            }
            Console.WriteLine(minCnt);
        }

        static int CalculateCount(int rLeft, int rRight,
            int gLeft, int gRight,
             int bLeft, int bRight)
        {
            int rCnt = OperateCount(rLeft, rRight, -100);
            int gCnt = OperateCount(gLeft, gRight, 0);
            int bCnt = OperateCount(bLeft, bRight, 100);
            return rCnt + gCnt + bCnt;
        }

        static int OperateCount(int left, int right, int center)
        {
            int cnt = 0;
            if (left <= center && center <= right)
            {
                cnt = (center - left) * (center - left + 1) / 2
                    + (right - center) * (right - center + 1) / 2;
            }
            else if (center < left)
            {
                cnt = (right + left - center * 2)
                    * (right - left + 1) / 2;
            }
            else if (right < center)
            {
                cnt = (center * 2 - right - left)
                    * (right - left + 1) / 2;
            }
            return cnt;
        }
    }
}