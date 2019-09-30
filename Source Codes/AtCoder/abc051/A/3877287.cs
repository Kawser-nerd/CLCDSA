using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

class Program
{
    static void Main()
    {
        var input = Console.ReadLine();
        Console.WriteLine(Regex.Replace(input, ",", " "));
    }
}