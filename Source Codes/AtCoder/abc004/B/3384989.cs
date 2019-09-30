using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program
{
    const int n = 4;

    static void Main()
    {
        var c = new List<string>();

        foreach (var i in Enumerable.Range(0, n))
        {
            c.Add(ReadLine().Replace(" ", ""));
        }

        for (var i = n - 1; i >= 0; i--)
        {
            for (var j = n - 1; j >= 0; j--)
            {
                Write(c[i][j]);
                if (j != 0)
                {
                    Write(" ");
                }
            }
            WriteLine();
        }
    }
}