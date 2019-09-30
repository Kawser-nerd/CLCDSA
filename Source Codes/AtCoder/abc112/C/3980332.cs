using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var list = new List<int[]>();
        for (int i = 0; i < n; i++)
        {
            var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            list.Add(inp);
        }
        list = list.OrderByDescending(f => f[2]).ToList();
        var ans = new int[101][];
        for (int i = 0; i <= 100; i++) ans[i] = new int[101];
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                ans[i][j] = list[0][2] + Math.Abs(i - list[0][0]) + Math.Abs(j - list[0][1]);
            }
        }
        for (int k = 1; k < list.Count(); k++)
        {
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    if (list[k][2] == 0 && (Math.Abs(list[k][0] - i) + Math.Abs(list[k][1] - j) + list[k][2] < ans[i][j])) ans[i][j] = 0;
                    else if (list[k][2] != 0 && Math.Abs(list[k][0] - i) + Math.Abs(list[k][1] - j) + list[k][2] != ans[i][j]) ans[i][j] = 0;
                }
            }
        }
        var top = new int[3];
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                if (top[2] < ans[i][j])
                {
                    top[0] = i;
                    top[1] = j;
                    top[2] = ans[i][j];
                }
            }
        }
        Console.WriteLine(string.Join(" ", top));
    }
}