using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    static void Main()
    {
        var hw = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var array = new List<string>();
        for (int i = 0; i < hw[0]; i++)
        {
            array.Add(Console.ReadLine());
        }

        var markRow = new bool[hw[0]];
        var markCol = new bool[hw[1]];
        for (int row = 0; row < hw[0]; row++)
        {
            for (int col = 0; col < hw[1]; col++)
            {
                if (array[row][col] == '#')
                {
                    markRow[row] = true;
                    markCol[col] = true;
                }
            }
        }

        for (int row = 0; row < hw[0]; row++)
        {
            if (markRow[row])
            {
                for (int col = 0; col < hw[1]; col++)
                {
                    if (markCol[col])
                    {
                        Console.Write(array[row][col]);
                    }
                }

                Console.WriteLine();
            }
        }
    }
}