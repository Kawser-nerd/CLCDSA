using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
class Program
{
    public static int Main()
    {
        //???????
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = inputs[0], m = inputs[1];
        int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //?????
        if (m <= n)
        {
            Console.WriteLine(0);
            return 0;
        }
        Array.Sort(x);
        List<int> dis = new List<int>();
        for (int i = 0; ; i++)
        {
            try { dis.Add(x[i + 1] - x[i]); }
            catch { break; }
        }
        dis.Sort();
        int ans = 0;
        for (int i = 0; i < m - n; i++)
            ans += dis[i];
        Console.WriteLine(ans);
        return 0;
    }
}