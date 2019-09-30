using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[][] rh = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        int[][] rateandhand = Enumerable.Repeat(0, 100010).Select(_ => new int[3]).ToArray();
        for (int i = 0; i < rh.Length; i++)
        {
            rateandhand[rh[i][0]][rh[i][1] - 1]++;
        }
        //???????????????
        int[] ruisekiwa = new int[100010];
        for (int i = 1; i < ruisekiwa.Length; i++)
        {
            ruisekiwa[i] = rateandhand[i - 1].Sum() + ruisekiwa[i - 1];
        }
        for (int i = 0; i < rh.Length; i++)
        {
            int win = ruisekiwa[rh[i][0]] + rateandhand[rh[i][0]][rh[i][1] % 3];
            int draw = rateandhand[rh[i][0]][rh[i][1] - 1] - 1;
            Console.WriteLine($"{win} {n - win - draw - 1} {draw}");
        }
    }
}