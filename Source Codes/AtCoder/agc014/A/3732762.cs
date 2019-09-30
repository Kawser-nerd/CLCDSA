using System;
using System.Linq;
class c
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        long ans = 0;
        while (true)
        {
            if (inp.Count(_ => _ % 2 == 1) > 0) break;
            else if (inp.Distinct().Count() == 1)
            {
                ans = -1;
                break;
            }
            var temp = new long[3] { inp[0], inp[1], inp[2] };
            inp[0] = (temp[1] + temp[2]) / 2;
            inp[1] = (temp[0] + temp[2]) / 2;
            inp[2] = (temp[0] + temp[1]) / 2;
            ans++;
        }
        Console.WriteLine(ans);
    }
}