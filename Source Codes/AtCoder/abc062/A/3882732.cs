using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

        var group = new int[] { 0, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 1, 0 };

        if (group[input[0]] == group[input[1]])
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}