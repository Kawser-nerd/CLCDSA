using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;


class P
{
    static void Main()
    {
        Console.WriteLine(700 + Console.ReadLine().Count(x => x =='o') * 100);
    }
}