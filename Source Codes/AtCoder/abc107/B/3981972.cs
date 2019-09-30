using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        var hw = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var grid = new string[hw[0]];
        for (int i = 0; i < hw[0]; i++) grid[i] = Console.ReadLine();
        var skipH = new List<int>();
        var skipW = new List<int>();
        for (int i = 0; i < hw[0]; i++)
        {
            if (!grid[i].Contains('#')) skipH.Add(i);
        }
        for (int i = 0; i < hw[1]; i++)
        {
            for (int j = 0; j < hw[0]; j++)
            {
                if (grid[j][i] == '#') break;
                else if (j == hw[0] - 1) skipW.Add(i);
            }
        }
        for (int i = 0; i < hw[0]; i++)
        {
            for (int j = 0; j < hw[1]; j++)
            {
                if (!skipH.Contains(i) && !skipW.Contains(j)) Console.Write(grid[i][j]);
            }
            if (!skipH.Contains(i)) Console.WriteLine();
        }
    }
}