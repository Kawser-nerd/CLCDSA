using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder.Grand017
{
    public class AGC017B_ModerateDifferences
    {
        public static void Main(string[] args)
        {
            
            // ??
            int[] nums = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int n = nums[0];
            int a = nums[1];
            int b = nums[2];
            int c = nums[3];
            int d = nums[4];

            // ?????????
            int diff = Math.Abs(b - a);

            // ????????
            int changeCnt = n - 1;
            
            for(int i=0; i <= changeCnt / 2; i++)
            {
                decimal plusCnt = i;
                decimal minusCnt = changeCnt - i;

                decimal minPlusNum = c * plusCnt;
                decimal maxPlusNum = d * plusCnt;
                decimal minMinusNum = c * minusCnt;
                decimal maxMinusNum = d * minusCnt;

                decimal change1 = Math.Abs(minPlusNum - minMinusNum);
                decimal change2 = Math.Abs(minPlusNum - maxMinusNum);
                decimal change3 = Math.Abs(maxPlusNum - minMinusNum);
                decimal change4 = Math.Abs(maxPlusNum - maxMinusNum);

                if( (change1 <= diff || change2 <= diff || change3 <= diff || change4 <= diff) &&
                    (change1 >= diff || change2 >= diff || change3 >= diff || change4 >= diff) )
                {
                    // ????
                    Console.WriteLine("YES");
                    return;
                }

            }
            
            // ????
            Console.WriteLine("NO");
        }
        

    }
}