using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine();
        var num = int.Parse(Regex.Replace(input, " ", ""));
        if (num >= 4 && num % 4 == 0)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}