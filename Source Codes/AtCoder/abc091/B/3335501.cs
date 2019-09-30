using System;
using System.Collections.Generic;

namespace Sample101
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????????
            var blueCardCount = int.Parse(Console.ReadLine());
            var blueCards = new Dictionary<string, int>();
            for (int i = 0; i < blueCardCount; ++i)
            {
                var str = Console.ReadLine();
                if (blueCards.ContainsKey(str))
                {
                    // ???????????????????????????
                    blueCards[str]++;
                } else
                {
                    // ????????????????
                    blueCards[str] = 1;
                }
            }

            // ??????????
            var redCardCount = int.Parse(Console.ReadLine());
            var redCards = new Dictionary<string, int>();
            for (int i = 0; i < redCardCount; ++i)
            {
                var str = Console.ReadLine();
                if (redCards.ContainsKey(str))
                {
                    redCards[str]++;
                } else
                {
                    redCards[str] = 1;
                }
            }

            // ????????
            var result = 0;
            var num = 0;
            foreach(KeyValuePair<string, int> item in blueCards)
            {
                if (redCards.ContainsKey(item.Key))
                {
                    // ????????????????????????
                    num = item.Value - redCards[item.Key];
                } else
                {
                    // ?????????????????
                    num = item.Value;
                }
                if (result < num)
                {
                    result = num;
                }
            }

            Console.WriteLine(result);
        }
    }
}