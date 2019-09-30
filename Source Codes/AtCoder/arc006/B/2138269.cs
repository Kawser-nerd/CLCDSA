using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nl = Console.ReadLine().Split().Select(int.Parse).ToArray();
        bool[][] amida = Enumerable.Repeat(0, nl[1]).Select(_ => Console.ReadLine().Split('|').Select(x => x == "-").ToArray()).ToArray();
        int atari = Console.ReadLine().Split('o')[0].Length / 2;
        for (int i = amida.Length - 1; i >= 0; i--)
        {
            if (amida[i][atari])
            {
                atari--;
            }
            else if(amida[i][atari + 1])
            {
                atari++;
            }
        }
        Console.WriteLine(atari + 1);
    }
}