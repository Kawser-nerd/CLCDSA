using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var sp = Console.ReadLine().Split(' ');
        int allC = int.Parse(sp[0]);
        int eatC = int.Parse(sp[1]);
        var lists = new List<long>[8];
        for(int i = 0; i < 8; ++i)
        {
            lists[i] = new List<long>(allC);
        }
        for(int i = 0; i < allC; ++i)
        {
            sp = Console.ReadLine().Split(' ');
            long n0 = long.Parse(sp[0]), n1 = long.Parse(sp[1]), n2 = long.Parse(sp[2]);
            lists[0].Add(n0 + n1 + n2);
            lists[1].Add(n0 + n1 - n2);
            lists[2].Add(n0 - n1 + n2);
            lists[3].Add(-n0 + n1 + n2);
            lists[4].Add(n0 - n1 - n2);
            lists[5].Add(-n0 + n1 - n2);
            lists[6].Add(-n0 - n1 + n2);
            lists[7].Add(-n0 - n1 - n2);
        }
        long result = 0;
        for(int k = 0; k < 8; ++k)
        {
            var list = lists[k];
            list.Sort();
            long tmp = 0;
            for (int i = list.Count - 1, j = 0; j < eatC; --i, ++j)
            {
                tmp += list[i];
            }
            if (k == 0 || result < tmp) result = tmp;
        }
        Console.WriteLine(result.ToString());
    }
}