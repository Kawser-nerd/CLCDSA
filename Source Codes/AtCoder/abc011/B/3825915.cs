using System;
using System.Collections.Generic;
using System.Linq;

using System.Globalization;

class Program
{
    static void Main()
    {
        string s = Console.ReadLine();

        TextInfo ti = CultureInfo.CurrentCulture.TextInfo;

        string ans = ti.ToTitleCase(s);

        Console.WriteLine(ans);
    }
}