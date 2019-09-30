using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2013_0
{
    class GCJ2013_0A
    {
        StreamReader reader = new StreamReader("A-large.in");
        StreamWriter writer = new StreamWriter("A-large.out");

        public GCJ2013_0A()
        {
            char[] grid;
            int xWin, oWin, empty;
            string result;
            int T = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < T; i++)
            {
                xWin = 0;
                oWin = 0;
                empty = 0;

                for (int j = 0; j < 4; j++)
                {
                    grid = reader.ReadLine().ToCharArray();
                    for (int k = 0; k < 4; k++)
                    {
                        if (grid[k] == '.')
                        {
                            empty++;
                        }
                        if (grid[k] == 'O' || grid[k] == '.')
                        {
                            xWin |= (1 << j);
                            xWin |= (1 << (4 + k));
                            if (j == k) xWin |= (1 << 8);
                            if (j + k == 3) xWin |= (1 << 9);
                        }
                        if (grid[k] == 'X' || grid[k] == '.')
                        {
                            oWin |= (1 << j);
                            oWin |= (1 << (4 + k));
                            if (j == k) oWin |= (1 << 8);
                            if (j + k == 3) oWin |= (1 << 9);
                        }
                    }
                }
                if (xWin < 1023) result = "X won";
                else if (oWin < 1023) result = "O won";
                else if (empty == 0) result = "Draw"; 
                else result = "Game has not completed";
                writer.WriteLine(String.Format("Case #{0}: {1}", (i+1), result));
                reader.ReadLine();
            }
            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            new GCJ2013_0A();
        }
    }
}
