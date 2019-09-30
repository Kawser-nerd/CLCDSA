using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<enquete> enogu = new List<enquete>();
        for (int i = 0; i < n; i++)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            enogu.Add(new enquete(a[0], 1));
            enogu.Add(new enquete(a[1] + 1, -1));
        }
        int status = 0;
        int max = 0;
        foreach (var i in enogu.OrderBy(x => x.bound * 3 + x.direction))
        {
            status += i.direction;
            max = Math.Max(max,status);
        }
        Console.WriteLine(max);
    }
    struct enquete
    {
        public int bound;
        public int direction;
        public enquete(int b,int d)
        {
            bound = b;
            direction = d;
        }
    }
}