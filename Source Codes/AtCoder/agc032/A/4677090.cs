using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcorder_GrandContest_032
{
    class Program
    {

        public const int MOD = 1000000000 + 7;

        static void Main(string[] args)
        {

            int cnt = int.Parse(Console.ReadLine());
            int[] numArr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
          
            List<int> numList = new List<int>();
            for(int i = cnt - 1; 0 <= i; i--)
            {
                numList.Add(numArr[i]);
            }

            Stack<int> retStack = new Stack<int>();
            int idx = 0;
            while (idx < numList.Count)
            {
                if (numList.Count - idx == numList[idx])
                {
                    retStack.Push(numList[idx]);
                    numList.RemoveAt(idx);
                    idx = 0;
                }
                else
                {
                    idx++;
                }
            }

            if (cnt == retStack.Count)
            {
                for (int i = 0; i < cnt; i++)
                {
                    Console.WriteLine(retStack.Pop());
                }
            }
            else
            {
                Console.WriteLine(-1);
            }
        }

    }
}