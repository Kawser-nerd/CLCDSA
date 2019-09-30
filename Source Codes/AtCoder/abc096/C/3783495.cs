using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        var hw = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var grid = new List<string>();
        grid.Add(new string('.', hw[1] + 2));
        for (int i = 0; i < hw[0]; i++) grid.Add("." + Console.ReadLine() + ".");
        grid.Add(new string('.', hw[1] + 2));
        bool judge = true;
        for (int i = 0; i < grid.Count(); i++)
        {
            for (int j = 0; j < grid[0].Length; j++)
            {
                if (grid[i][j] == '#')
                {
                    if (!new char[4] { grid[i - 1][j], grid[i][j - 1], grid[i + 1][j], grid[i][j + 1] }.Contains('#')) judge = false;
                }
            }
        }
        Console.WriteLine(judge ? "Yes" : "No");
    }
}