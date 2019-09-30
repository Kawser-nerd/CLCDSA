using System;
using System.Linq;
using System.Collections.Generic;

class Dmondai
{
    static void Main()
    {
        var N = Int32.Parse(Console.ReadLine());

        //???????????
        var array = new int[100];
        array[0] = 1;
        for (int i = 1; i < 100; ++i) array[i] = 0;
        for (int i = 2; i <= N; ++i)
        {
            var num = i;
            for (int k = 2; k <= i; ++k)
            {
                if (num < k) break;
                while (num % k == 0)
                {
                    array[k - 1]++;
                    num /= k;
                }
            }
        }

        var list = new List<double>();
        // 74 2.24 4.14 2.4.4
        for (int i=0;i<array.Count();++i)
        {
            if (array[i] == 0) continue;
            if (74 <= array[i])
            {
                var n = Math.Pow(i + 1, 74);
                if (!list.Contains(n)) list.Add(n);
            }

            for (int j = 0; j < array.Count(); ++j)
            {
                if ((array[j] == 0)||(j==i)) continue;
                if (4 <= array[i] && 14 <= array[j])
                {
                    var n = (Math.Pow(i + 1, 4) + Math.Pow(j + 1, 14));
                    if (!list.Contains(n)) list.Add(n);
                }
                if (2 <= array[i] && 24 <= array[j])
                {
                    var n = (Math.Pow(i + 1, 2) + Math.Pow(j + 1, 24));
                    if (!list.Contains(n)) list.Add(n);
                }

                for (int k = 0; k < array.Count(); ++k)
                {
                    if ((array[k] == 0)||(k==i)||(k==j)) continue;

                    if ( 2 <= array[i] && 4 <= array[j] && 4 <= array[k] )
                    {
                        var n = (Math.Pow(i + 1, 2) + Math.Pow(j + 1, 4) + Math.Pow(k + 1, 4));
                        if (!list.Contains(n)) list.Add(n);
                    }
                }
            }
        }
        Console.WriteLine(list.Count());
        
    }
}