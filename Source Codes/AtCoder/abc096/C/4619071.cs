using System;

class Program
{
    static void Main(string[] args)
    {
        var hw = Console.ReadLine().Split(' ');
        var h = int.Parse(hw[0]);
        var w = int.Parse(hw[1]);

        var d = new string[h];
        for (int i = 0; i < h; i++)
        {
            d[i] = Console.ReadLine();
        }

        var dx = new[] { 1, 0, -1, 0 };
        var dy = new[] { 0, -1, 0, 1 };

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (d[i][j] == '#')
                {
                    var any = false;
                    for (int k = 0; k < 4; k++)
                    {
                        var sy = i + dy[k];
                        var sx = j + dx[k];

                        if (0 <= sy && sy < h &&
                            0 <= sx && sx < w &&
                            d[sy][sx] == '#')
                        {
                            any = true;
                            break;
                        }
                    }
                    if (!any)
                    {
                        Console.WriteLine("No");
                        return;
                    }
                }
            }
        }

        Console.WriteLine("Yes");
    }
}