using System;
using System.IO;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using static System.Math;


class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n < 105 ? 0 : n < 135 ? 1 : n < 165 ? 2 : n < 189 ? 3 : n < 195 ? 4 : 5);
    }
}