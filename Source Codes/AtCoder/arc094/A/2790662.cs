using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        var array = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

        var M = array.Max();
        if ((3 * M - array.Sum()) %2 == 0)
        {
            Console.WriteLine((3 * M - array.Sum()) / 2);
        }
        else
        {
            Console.WriteLine((3 * M + 3 - array.Sum()) / 2);
        }
    }
}