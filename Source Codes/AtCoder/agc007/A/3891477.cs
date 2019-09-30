using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;


class P
{
    static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        char[][] map = Enumerable.Repeat(0, hw[0]).Select(_ => Console.ReadLine().ToArray()).ToArray();
        int x = 0;
        int y = 0;
        while (x < hw[1] && y < hw[0])
        {
            map[y][x] = '.';
            if (y + 1 < hw[0] && map[y + 1][x] == '#') y++;
            else if (x + 1 < hw[1] && map[y][x + 1] == '#') x++;
            else break;
        }
        if (x == hw[1] - 1 && y == hw[0] - 1 && map.All(xe => xe.All(ye => ye == '.'))) Console.WriteLine("Possible");
        else Console.WriteLine("Impossible");
    }
}