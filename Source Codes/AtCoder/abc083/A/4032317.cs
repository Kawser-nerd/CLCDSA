using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        int a = int.Parse(cin[0]);
        int b = int.Parse(cin[1]);
        int c = int.Parse(cin[2]);
        int d = int.Parse(cin[3]);
        if (a + b < c + d) Console.WriteLine("Right");
        else if (a + b > c + d) Console.WriteLine("Left");
        else Console.WriteLine("Balanced");
    }
}