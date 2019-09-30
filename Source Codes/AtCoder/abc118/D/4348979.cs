using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcorder_BeginnerContest_118
{
    class Program
    {

        struct NumPoint
        {
            public int no;
            public int cnt;
        }

        public static int[] _noPoint = new int[] { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

        static void Main(string[] args)
        {
            int[] cntArr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            int matchCnt = cntArr[0];
            int numCnt = cntArr[1];
            
            int[] dataArr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
          
            List<NumPoint> numPointList = new List<NumPoint>();
            NumPoint np = new NumPoint();
            np.no = 0;
            np.cnt = 0;
            numPointList.Add(np);
            for(int i = 0; i < numCnt; i++)
            {
                np.no = dataArr[i];
                np.cnt = _noPoint[dataArr[i]];
                numPointList.Add(np);
            }

            numPointList.Sort((a, b) => a.no.CompareTo(b.no));

            int[,] dpCreateCnt = new int[numCnt + 1, matchCnt + 1];
            int[,] dpMacthCnt = new int[numCnt + 1, matchCnt + 1];
            int[,,] dpEachNumCnt = new int[numCnt + 1, matchCnt + 1, numCnt + 1];

            for(int i = 1; i <= numCnt; i++)
            {
                for (int j = 1; j <= matchCnt; j++)
                {

                    dpCreateCnt[i, j] = dpCreateCnt[i - 1, j];
                    dpMacthCnt[i, j] = dpMacthCnt[i - 1, j];
                    for (int k = 1; k <= numCnt; k++)
                    {
                        dpEachNumCnt[i, j, k] = dpEachNumCnt[i - 1, j, k];
                    }

                    if (numPointList[i].cnt <= j)
                    {

                        int tmpCreateCnt = dpCreateCnt[i, j - numPointList[i].cnt] + 1;
                        int tmpMacthCnt = dpMacthCnt[i, j - numPointList[i].cnt] + numPointList[i].cnt;

                        if (j == tmpMacthCnt)
                        {
                            if (dpCreateCnt[i - 1, j] <= tmpCreateCnt)
                            {
                                dpCreateCnt[i, j] = tmpCreateCnt;
                                dpMacthCnt[i, j] = tmpMacthCnt;
                                for (int k = 1; k <= numCnt; k++)
                                {
                                    dpEachNumCnt[i, j, k] = dpEachNumCnt[i, j - numPointList[i].cnt, k];
                                }
                                dpEachNumCnt[i, j, i]++;
                            }
                        }
                    }
                }

            }

            List<int> retList = new List<int>();
            int fixNumCnt = 0;
            for(int i = numCnt; 1 <= i; i--)
            {
                if (matchCnt == dpMacthCnt[i, matchCnt])
                {
                    fixNumCnt = i;
                    break;
                }
            }
            for (int i = 1; i <= numCnt; i++)
            {
                int addCnt = dpEachNumCnt[fixNumCnt, matchCnt, i];
                for (int j = 0; j < addCnt; j++)
                {
                    retList.Add(numPointList[i].no);
                }

            }

            retList.Sort((a, b) => b - a);

            string ret = "";
            for (int i = 0; i < retList.Count; i++)
            {
                ret += retList[i]; 
            }
            Console.WriteLine(ret);

        }
    }
}