using System;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var W = ReadLine();

        foreach (var c in W)
        {
            if (!"aiueo".Contains(c))
            {
                Write(c);
            }
        }
        WriteLine();
    }
}