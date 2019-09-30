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

        string s_new = s.Replace("2017", "2018");
        
        Console.WriteLine(s_new);
    }
}