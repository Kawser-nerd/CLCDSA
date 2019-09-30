using System;
using System.Collections.Generic;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????????????
            int t = int.Parse(Console.ReadLine());

            // ???????
            int n = int.Parse(Console.ReadLine());

            // ?????????????????
            int[] takoyaki = new int[n];

            // ??????1????
            string input = Console.ReadLine();

            // ??
            for(int i = 0; i < n; i++)
            {
                takoyaki[i] = int.Parse(input.Split(' ')[i]);
            }

            // ???????
            int m = int.Parse(Console.ReadLine());

            // ????????????
            int[] guest = new int[m];
            
            // ??????????????????=true, ????=false?
            bool[] isBought = new bool[m];

            // ??????1????
            input = Console.ReadLine();

            // ??
            for(int i = 0; i < m; i++)
            {
                guest[i] = int.Parse(input.Split(' ')[i]);
            }

            // ?????????????
            int temp = 0;
            for(int i = 0; i < m; i++)
            {
                for (int j = temp; j < n; j++)
                {
                    if (guest[i] - takoyaki[j] <= t && guest[i] - takoyaki[j] >= 0)
                    {
                        isBought[i] = true;
                        temp = j + 1;
                        break;
                    }
                }
            }

            // ???yes????
            string result = "yes";

            // ??????????????????no???
            for(int i = 0; i < m; i++)
            {
                if (!isBought[i])
                {
                    result = "no";
                }
            }

            // ?????????
            Console.WriteLine(result);
        }
    }
}