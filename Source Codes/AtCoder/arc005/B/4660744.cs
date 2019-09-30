using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int x, y;
        string[] s = Console.ReadLine().Split(' ');
        x = int.Parse(s[0]) - 1;
        y = int.Parse(s[1]) - 1;
        int vx = 0;
        int vy = 0;
        if (s[2].Contains('U'))
            vy = -1;
        if (s[2].Contains('D'))
            vy = 1;
        if (s[2].Contains('L'))
            vx = -1;
        if (s[2].Contains('R'))
            vx = 1;

        string r = "";
        string[] f = new string[9];
        for (int i = 0; i < 9; i++)
            f[i] = Console.ReadLine();
        for (int i = 0; i < 4; i++)
        {
            r += f[y][x];
            x += vx;
            if (x == 9)
            {
                x = 7;
                vx = -vx;
            }
            if (x == -1)
            {
                x = 1;
                vx = -vx;
            }
            y += vy;
            if (y == 9)
            {
                y = 7;
                vy = -vy;
            }
            if (y == -1)
            {
                y = 1;
                vy = -vy;
            }
        }
        Console.WriteLine(r);
    }
}