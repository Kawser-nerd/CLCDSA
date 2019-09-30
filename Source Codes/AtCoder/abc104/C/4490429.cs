using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var dg = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        var D = (int)dg[0];
        var G = dg[1];
        var list = new List<long[]>();
        for (int i=0;i<D;++i)
        {
            var pc= Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
            list.Add(new long[2] { pc[0], pc[1] });
        }
        var ans = long.MaxValue;
        for (int i = 0; i < (Math.Pow(2, D)); i++)
        {
            var count = 0L;
            var total = 0L;
            for (int j = 0; j < D; j++)
            {
                if ((1 & i >> j) == 1) {
                    count += list[j][0];
                    total += list[j][0] * 100 * (j + 1) + list[j][1];
                }
            }
            if (total < G)
            {
                for (int j = D - 1; 0 <= j; --j)
                {
                    if ((1 & i >> j) == 0)
                    {
                        var add = (G-total) / ((j + 1) * 100);
                        if (add <= list[j][0])
                        {
                            count+=add;
                            total += add * 100 * (j + 1);
                            if (G <= total)
                            {
                                ans = Math.Min(ans, count);
                                break;
                            }
                        }
                    }
                }
            }
            else ans=Math.Min(ans,count);
        }
        Console.WriteLine(ans);
    }
}