using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcorder_BeginnerContest_117
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] line = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
            long cnt = line[0];
            long maxVal = line[1];

            long[] valArr = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);

            int maxLen = 0;
            long valArrMax = valArr.Max();
            if (valArrMax < maxVal)
            {
                maxLen = Convert.ToString(maxVal, 2).ToString().Length;
            }
            else
            {
                maxLen = Convert.ToString(valArrMax, 2).ToString().Length;            
            }

            int[] digitCnt0 = new int[maxLen];
            int[] digitCnt1 = new int[maxLen]; 
            
            for (int i = 0; i < cnt; i++)
            {
                string bNumStr = Convert.ToString(valArr[i], 2).PadLeft(maxLen,'0');
                for (int j = 0; j < maxLen; j++)
                {
                    if ("0" == bNumStr.Substring(j, 1))
                    {
                        digitCnt0[j]++;
                    }
                    else
                    {
                        digitCnt1[j]++;                    
                    }
                }
            }

            string  multValStr= "";

            for (int i = 0; i < maxLen; i++)
            {
                string tmpRet = multValStr;
                bool zeroValFlg = true;
                if (digitCnt0[i] < digitCnt1[i])
                {
                    tmpRet += "0";
                }
                else
                {
                    tmpRet += "1";
                    zeroValFlg = false;
                }

                //??????????????
                if (maxVal < Convert.ToInt64(tmpRet.PadRight(maxLen, '0'), 2))
                {
                    if (zeroValFlg) multValStr += "1";
                    else multValStr += "0";
                }
                else
                {
                    multValStr = tmpRet;
                }
            }

            long multValLng = Convert.ToInt64(multValStr, 2);
            long ret = 0;
            for (int i = 0; i < cnt; i++)
            {
                ret += valArr[i] ^ multValLng;
            }

            Console.WriteLine(ret);

        }
      
    }
}