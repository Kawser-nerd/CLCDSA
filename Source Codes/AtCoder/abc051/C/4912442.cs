using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split();
        var sx = int.Parse(s[0]);
        var sy = int.Parse(s[1]);
        var tx = int.Parse(s[2]);
        var ty = int.Parse(s[3]);

        var dx = new[] { tx, tx, sx, sx, tx + 1, tx + 1, tx, tx, sx - 1, sx - 1, sx };
        var dy = new[] { sy, ty, ty, sy - 1, sy - 1, ty, ty, ty + 1, ty + 1, sy, sy };

        var x = sx;
        var y = sy;
        for (int i = 0; i < 11; i++)
        {
            if (x < dx[i])
            {
                Console.Write(new string('R', dx[i] - x));
            }
            else
            {
                Console.Write(new string('L', x - dx[i]));
            }

            if (y < dy[i])
            {
                Console.Write(new string('U', dy[i] - y));
            }
            else
            {
                Console.Write(new string('D', y - dy[i]));
            }

            x = dx[i];
            y = dy[i];
        }

        Console.WriteLine();
    }
}