using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static void Main()
    {
        string s = Console.ReadLine();

        Console.WriteLine(s.Substring(0, 3) + "8" + s.Substring(4, s.Length - 4));
    }
}