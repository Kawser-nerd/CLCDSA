using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

class MinesweeperMaster
{
    public void Solve()
    {
        StreamReader sr = new StreamReader(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\C.in");
        StreamWriter sw = new StreamWriter(@"C:\JMH Documents\Programming\TFSmap\JMH\Competitions\Code Jam\GCJ_2014\Files\C.out");

        int test_cases = Int32.Parse(sr.ReadLine());
        for (int t = 1; t <= test_cases; t++)
        {
            string[] line = sr.ReadLine().Split();
            int R = Int32.Parse(line[0]);
            int C = Int32.Parse(line[1]);
            int M = Int32.Parse(line[2]);
            int free = R * C - M;

            // I think we'll just need to handle a massive stack of cases.
            string output = String.Format("Case #{0}:", t);
            sw.WriteLine(output);

            // Case 1: The grids have size 1.
            if (R == 1)
            {
                sw.Write("c");
                for (int i = 0; i < C - M - 1; i++) sw.Write(".");
                for (int i = 0; i < M; i++) sw.Write("*");
                sw.WriteLine();
                continue;
            }
            if (C == 1)
            {
                sw.WriteLine("c");
                for (int i = 0; i < R - M - 1; i++) sw.WriteLine(".");
                for (int i = 0; i < M; i++) sw.WriteLine("*");
                continue;
            }

            // Case 2: 2, 3, 5 and 7 free squares is always impossible
            if ((free == 2) || (free == 3) || (free == 5) || (free == 7))
            {
                sw.WriteLine("Impossible");
                continue;
            }

            // Case 2A: 1 is always solvable
            if (free == 1)
            {
                // Put a click then write the rest of the row
                sw.Write("c");
                for (int i = 0; i < C - 1; i++) sw.Write("*");
                sw.WriteLine();

                // And write the rest of the grid
                for (int i = 0; i < R - 1; i++)
                {
                    for (int j = 0; j < C; j++) sw.Write('*');
                    sw.WriteLine();
                }
                continue;
            }

            // Case 3: Odd numbers are impossible if there are only two rows
            if ((free % 2 == 1) && ((R == 2) || (C == 2)))
            {
                sw.WriteLine("Impossible");
                continue;
            }

            // Now we need to deal with larger cases, so prepare a grid
            char[,] grid = new char[R, C];
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    grid[i, j] = '*';

            // Case 4: For even numbers (above 2), begin by drawing a 2x2 block
            // in the bottom left corner, and then just fill in pairs wherever
            // possible
            if (free % 2 == 0)
            {
                grid[0, 0] = 'c';
                grid[0, 1] = grid[1, 0] = grid[1, 1] = '.';
                int pairs_to_draw = (free - 4) / 2;

                while (pairs_to_draw > 0)
                {
                    AddPair(grid, R, C);
                    pairs_to_draw--;
                }

                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++) sw.Write(grid[i, j].ToString());
                    sw.WriteLine();
                }
                continue;
            }
            
            // Case 5: Odd numbers at this stage are at least 9, so begin with a 
            // 3x3 block and fill in pairs wherever possible
            else
            {
                grid[0, 0] = 'c';
                grid[0, 1] = grid[1, 0] = grid[1, 1] = '.';
                grid[0, 2] = grid[1, 2] = grid[2, 2] = grid[2, 1] = grid[2, 0] = '.';
                int pairs_to_draw = (free - 9) / 2;

                while (pairs_to_draw > 0)
                {
                    AddPair(grid, R, C);
                    pairs_to_draw--;
                }

                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++) sw.Write(grid[i, j].ToString());
                    sw.WriteLine();
                }
                continue;
            }
        }

        sr.Close();
        sw.Close();
    }

    void AddPair(char[,] grid, int R, int C)
    {
        for (int row = 0; row < R; row++)
            for (int col = 0; col < C; col++)
            {
                // The square has to be a mine
                if (grid[row, col] != '*') continue;

                // Can we put a vertical pair in?
                if ((row + 1 <= R - 1) && (col >= 2) && (grid[row + 1, col] == '*') &&
                    (grid[row, col - 1] == '.') && (grid[row + 1, col - 1] == '.'))
                {
                    grid[row, col] = '.';
                    grid[row + 1, col] = '.';
                    return;
                }

                // Can we put a horizontal pair in?
                if ((col + 1 <= C - 1) && (row >= 2) && (grid[row, col + 1] == '*') &&
                    (grid[row - 1, col] == '.') && (grid[row - 1, col + 1] == '.'))
                {
                    grid[row, col] = '.';
                    grid[row, col + 1] = '.';
                    return;
                }
            }
        return;
    }
}
