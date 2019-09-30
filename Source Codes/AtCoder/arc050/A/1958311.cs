using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        Console.WriteLine(s[0] - s[2] == -32 ? "Yes" : "No");
    }
}