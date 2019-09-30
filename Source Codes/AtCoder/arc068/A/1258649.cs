//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public static void Main()
    {
        var x = long.Parse(Console.ReadLine());

        Console.WriteLine((x * 2 + 9) / 11);
    }
}