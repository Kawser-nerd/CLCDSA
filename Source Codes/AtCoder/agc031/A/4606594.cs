using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcorder_GrandContest_031
{
    class Program
    {

        public const int MOD = 1000000000 + 7;

        static void Main(string[] args)
        {

            int cnt = int.Parse(Console.ReadLine());
            var data = Console.ReadLine().ToArray();

            List<int> charList = new List<int>();
            int[] cntArr = new int[128];

            int charCnt = 0;

            for (int i = 0; i < cnt; i++)
            {
                int aVal = (int)data[i];
                if (0 == cntArr[aVal])
                {
                    charList.Add(aVal);
                    charCnt++;
                }
                cntArr[aVal]++;
            }

            long ret = 1;
            for (int i = 0; i < charCnt; i++)
            {
                ret *= cntArr[charList[i]] + 1;
                ret %= MOD;
            }

            ret--;

            Console.WriteLine(ret);

        }

    }
}