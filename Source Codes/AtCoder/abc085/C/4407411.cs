using System;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var ny = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for(var i=0;i<=ny[0];i++)
            for(var j = 0; j <= ny[0]; j++)
            {
                var h = ny[0] - i - j;
                if (h < 0) break;
                if (i * 10000 + j * 5000 + h * 1000 == ny[1])
                {
                    WriteLine($"{i} {j} {h}");
                    return;
                }
            }
        WriteLine("-1 -1 -1");
    }
}