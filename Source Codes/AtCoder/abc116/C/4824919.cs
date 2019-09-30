using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        Console.ReadLine();
        var h = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int ans = 0;
        while (h.Sum() > 0)
        {
            int max = h.Max();
            var search = Enumerable.Repeat(false, h.Length).ToArray();
            for (int i = 0; i < h.Length; i++)
            {
                if (h[i] == max) search[i] = true;
            }
            int L = 0, R = search.Count() - 1;
            bool searched = false;
            for (int i = 0; i < search.Length; i++)
            {
                if (search[i] == true && !searched)
                {
                    L = i;
                    for (int j = i; j < search.Length; j++)
                    {
                        if (search[j] == false)
                        {
                            R = j - 1;
                            break;
                        }
                    }
                    searched = true;
                }
            }
            var list = new List<int>();
            list.Add(max);
            if (L != 0) list.Add(h[L - 1]);
            if (R != search.Count() - 1) list.Add(h[R + 1]);
            int cut = list[0];
            if (list.Count() == 2) cut = list[0] - list[1];
            else if (list.Count() == 3) cut = max - list.OrderBy(f => f).ToList()[1];
            for (int i = L; i <= R; i++) h[i] -= cut;
            ans += cut;
        }
        Console.WriteLine(ans);
    }
}