using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_005_B
{
    class Program
    {
        static void Main(string[] args)
        {
        
            string[] Come = Console.ReadLine().Split();
            string direc = Come[2];
            int startX = int.Parse(Come[0]) - 1;
            int startY = int.Parse(Come[1]) - 1;
            int nowX = startX;
            int nowY = startY;
            int[,] grid = new int[9, 9];

            int[] vx = new int[] { 1, -1, 0, 0, 1, 1, -1, -1 };
            int[] vy = new int[] { 0, 0, -1, 1, -1, 1, -1, 1 };
            for (int i = 0; i < 9; i++)
            {
                string adf = Console.ReadLine();
                for (int j = 0; j < 9; j++)
                {
                    grid[i, j] = int.Parse(adf[j].ToString());
                }
            }
            for (int i = 0; i < 4; i++)
            {
                Console.Write(grid[nowY, nowX]);
                int direction = 7;
                if (direc == "R") { direction = 0; }
                else if (direc == "L") { direction = 1; }
                else if (direc == "U") { direction = 2; }
                else if (direc == "D") { direction = 3; }
                else if (direc == "RU") { direction = 4; }
                else if (direc == "RD") { direction = 5; }
                else if (direc == "LU") { direction = 6; }
                int nextX = nowX + vx[direction];
                int nextY = nowY + vy[direction];
                if (nextX >= 9)
                {
                    direc = direc.Replace("R", "L");
                    nextX = 7;
                    if (nextY >= 9)
                    {
                        nextY = 7; direc = direc.Replace("D", "U");
                    }
                    else if (nextY <= -1)
                    {
                        nextY = 1; direc = direc.Replace("U", "D");
                    }

                }
                if (nextX <= -1)
                {
                    direc = direc.Replace("L", "R");

                    nextX = 1;
                    if (nextY >= 9)
                    {
                        nextY = 7; direc = direc.Replace("D", "U");
                    }
                    else if (nextY <= -1)
                    {
                        nextY = 1; direc = direc.Replace("U", "D");
                    }
                }
                if (nextY >= 9)
                {
                    direc = direc.Replace("D", "U");
                    nextY = 7;
                    if (nextX >= 9)
                    {
                        nextX = 7; direc = direc.Replace("R", "L"); ;
                    }
                    else if (nextX <= -1)
                    {
                        nextX = 1; direc = direc.Replace("L", "R");
                    }
                }
                if (nextY <= -1)
                {
                    direc = direc.Replace("U", "D");
                    nextY = 1;
                    if (nextX >= 9)
                    {
                        nextX = 7;
                        direc = direc.Replace("R", "L");
                    }
                    else if (nextX <= -1)
                    {
                        nextX = 1;
                        direc = direc.Replace("L", "R");
                    }
                }
                nowX = nextX;
                nowY = nextY;
            }
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}