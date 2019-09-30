using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        if (s.Substring(s.Length - 1, 1) == "T")
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}