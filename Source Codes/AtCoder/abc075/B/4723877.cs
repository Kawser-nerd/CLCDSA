using System;

class Program
{
    static void Main(string[] args)
    {
        var hw = Console.ReadLine().Split(' ');
        var h = int.Parse(hw[0]);
        var w = int.Parse(hw[1]);

        var s = new string[h];
        for (int i = 0; i < h; i++)
        {
            s[i] = Console.ReadLine();
        }

        var ans = new int[h, w];
        var dx = new[] { -1, 0, 1, -1, 1, -1, 0, 1, };
        var dy = new[] { -1, -1, -1, 0, 0, 1, 1, 1, };

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] == '.')
                {
                    for (int k = 0; k < 8; k++)
                    {
                        var sy = i + dy[k];
                        var sx = j + dx[k];

                        if (0 <= sy && sy < h &&
                            0 <= sx && sx < w &&
                            s[sy][sx] == '#')
                        {
                            ans[i, j]++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] == '#')
                {
                    Console.Write('#');
                }
                else
                {
                    Console.Write(ans[i, j]);
                }
            }
            Console.WriteLine();
        }
    }
}