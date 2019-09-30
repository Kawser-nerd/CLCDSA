using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //int a = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        int[][] thread = Enumerable.Range(1, nm[0]).Select(x => new int[] { x, 0 }).ToArray();
        for (int i = 0; i < nm[1]; i++)
        {
            thread[int.Parse(Console.ReadLine()) - 1][1] = i + 1;
        }
        foreach (int[] i in thread.OrderByDescending(x => x[1]).ToArray())
        {
            Console.WriteLine(i[0]);
        }
    }
}