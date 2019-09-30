using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var grid = new int[3][];
        for (int i = 0; i < 3; i++)
        {
            grid[i] = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        var min = grid.Select(x => x.Min()).Min();
        grid = grid.Select(x => x.Select(y => y - min).ToArray()).ToArray();

        var a = new int[3];
        var b = new int[3];

        //???
        for (int i = 0; i <= 100; i++)
        {
            a[0] = i;
            for (int j = 0; j < 3; j++)
            {
                b[j] = grid[0][j] - a[0];
            }

            for (int j = 1; j < 3; j++)
            {
                a[j] = grid[j][0] - b[0];
            }

            var flag = true;
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    if (grid[row][col] != a[row]+b[col])
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag)
            {
                Console.WriteLine("Yes");
                return;
            }
        }

        Console.WriteLine("No");
    }
}