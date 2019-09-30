using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int[] pos = { int.Parse(input[0]), int.Parse(input[1]) };
        int[] direction = new int[2];
        if (input[2].Contains('R')) direction[0] = 1;
        if (input[2].Contains('L')) direction[0] = -1;
        if (input[2].Contains('U')) direction[1] = -1;
        if (input[2].Contains('D')) direction[1] = 1;
        int[][] a = Enumerable.Repeat(0, 9).Select(_ => Console.ReadLine().Select(x => x - '0').ToArray()).ToArray();
        
        for (int i = 0; i < 4; i++)
        {
            if ((pos[0] == 1 && direction[0] == -1) || (pos[0] == 9 && direction[0] == 1)) direction[0] *= -1;
            if ((pos[1] == 1 && direction[1] == -1) || (pos[1] == 9 && direction[1] == 1)) direction[1] *= -1;
            Console.Write(a[pos[1] - 1][pos[0] - 1]);
            pos[0] += direction[0];
            pos[1] += direction[1];
        }
        Console.WriteLine();
    }
}