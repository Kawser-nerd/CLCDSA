using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var piramids = new int[n][];
        var xs = new int[n];
        var ys = new int[n];
        var hs = new int[n];
        for (int i = 0; i < n; i++)
        {
            var input = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            xs[i] = input[0];
            ys[i] = input[1];
            hs[i] = input[2];
        }

        for (int cy = 0; cy <= 100; cy++)
        {
            for (int cx = 0; cx <= 100; cx++)
            {
                var flag = true;
                var ch = -1;
                var hMax = int.MaxValue;
                for (int i = 0; i < n; i++)
                {
                    var x = xs[i];
                    var y = ys[i];
                    var h = hs[i];
                    var d = Math.Abs(cx - x) + Math.Abs(cy - y);
                    if (h > 0)
                    {
                        var buf = h + d;
                        if (ch > 0 && ch != buf)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            ch = buf;
                        }
                    }
                    else
                    {
                        hMax = Math.Min(hMax, d);
                    }
                }

                if (flag && ch <= hMax)
                {
                    Console.WriteLine($"{cx} {cy} {ch}");
                }
            }
        }
    }
}