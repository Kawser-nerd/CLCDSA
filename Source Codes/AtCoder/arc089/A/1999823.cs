using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] lastpos = { 0, 0, 0 };
        for (int i = 0; i < n; i++)
        {
            int[] currentpos = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int diff = Math.Abs(currentpos[1] - lastpos[1]) + Math.Abs(currentpos[2] - lastpos[2]);
            int time = (currentpos[0] - lastpos[0]);
            if (diff > time  || (diff - time) % 2 != 0)
            {
                Console.WriteLine("No");
                return;
            }
            lastpos = currentpos;
        }
        Console.WriteLine("Yes");
    }
}