using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').ToList();
        if (input[0].Substring(input[0].Length - 1, 1) == input[1].Substring(0, 1) && input[1].Substring(input[1].Length - 1, 1) == input[2].Substring(0, 1))
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}