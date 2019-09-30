using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] mnN = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int damepen = 0;
        int sell = mnN[2];
        int res = sell;
        while (true)
        {
            damepen += sell;
            sell = damepen / mnN[0] * mnN[1];
            damepen = damepen % mnN[0];
            res += sell;
            if(sell == 0)
            {
                Console.WriteLine(res);
                return;
            }
        }
    }
}