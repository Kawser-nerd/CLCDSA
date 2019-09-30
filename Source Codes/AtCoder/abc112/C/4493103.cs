using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var x = new int[n];
        var y = new int[n];
        var h = new int[n];
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine().Split(' ');
            x[i] = int.Parse(s[0]);
            y[i] = int.Parse(s[1]);
            h[i] = int.Parse(s[2]);
        }

        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                var ans = 0;
                for (int k = 0; k < n; k++)
                {
                    if (h[k] != 0)
                    {
                        if (ans == 0)
                        {
                            ans = m1(i, j, x[k], y[k], h[k]);
                        }
                        else if (ans != m1(i, j, x[k], y[k], h[k]))
                        {
                            ans = 0;
                            break;
                        }
                    }
                }

                if (ans == 0) continue;

                for (int k = 0; k < n; k++)
                {
                    if (h[k] == 0)
                    {
                        if (m1(i, j, x[k], y[k], h[k]) < ans)
                        {
                            ans = 0;
                            break;
                        }
                    }
                }

                if (ans == 0) continue;

                Console.WriteLine($"{i} {j} {ans}");
                return;
            }
        }
    }

    public static int m1(int x1, int y1, int x2, int y2, int h)
    {
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2) + h;
    }
}