using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NMAB = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int count = NMAB[0];
        for (int i = 0; i < NMAB[1]; i++)
        {
            if (count <= NMAB[2]) count += NMAB[3];
            count -= int.Parse(Console.ReadLine());
            if (count < 0)
            {
                Console.WriteLine(i + 1);
                return;
            }
        }
        Console.WriteLine("complete");
    }
}