using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var buffer = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int x1 = buffer[0], y1 = buffer[1], r = buffer[2];
            buffer = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int x2 = buffer[0], y2 = buffer[1], x3 = buffer[2], y3 = buffer[3];

            var field = new int[201, 201];

            for (int dx = -r; dx <= r; dx++)
            {
                if (x1 + dx < -100 || 100 < x1 + dx) { continue; }
                for (int dy = -r; dy <= r; dy++)
                {
                    if (y1 + dy < -100 || 100 < y1 + dy) { continue; }
                    if (dx * dx + dy * dy > r * r) { continue; }
                    field[x1 + dx + 100, y1 + dy + 100] = 1;
                }
            }
            for (int x = x2; x <= x3; x++)
            {
                for (int y = y2; y <= y3; y++)
                {
                    field[x + 100, y + 100] += 2;
                }
            }
            var red = false;
            var blue = false;
            for (var i = 0; i < 201; i++)
            {
                for (var j = 0; j < 201; j++)
                {
                    if (field[i, j] == 1) { red = true; }
                    else if (field[i, j] == 2)
                    {
                        blue = true;
                    }
                }
            }
            Console.WriteLine(red ? "YES" : "NO");
            Console.WriteLine(blue ? "YES" : "NO");
        }
    }
}