using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split();
        int a = int.Parse(s[0]);
        int b = int.Parse(s[1]);

        if (a <= 8 && b <= 8) Console.WriteLine("Yay!");
        else Console.WriteLine(":(");
    }
}