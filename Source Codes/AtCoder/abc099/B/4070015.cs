using System;
using System.Web;
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
        int[] ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine((ab[1] - ab[0]) * (ab[1] - ab[0] - 1) / 2 - ab[0]);
    }
}