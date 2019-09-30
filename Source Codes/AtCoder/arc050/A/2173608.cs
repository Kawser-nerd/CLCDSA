using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        string s =  Console.ReadLine();
        Console.WriteLine(s[0] - s[2] == 'A' - 'a' ? "Yes" : "No");
    }
}