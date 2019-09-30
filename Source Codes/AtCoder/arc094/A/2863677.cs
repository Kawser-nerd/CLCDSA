using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int[] abc = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int ans = 0;

        while(!(abc[0] == abc[1] && abc[1] == abc[2]))
        {
            Array.Sort(abc);
            if(abc[0] < abc[1])
            {
                abc[0] += 2;
            }
            else if(abc[0] == abc[1])
            {
                abc[0] += 1;
                abc[1] += 1;
            }
            ans++;
        }
        Console.WriteLine(ans);
    }
}