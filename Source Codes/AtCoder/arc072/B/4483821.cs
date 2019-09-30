using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;
using StructLayoutAttribute = System.Runtime.InteropServices.StructLayoutAttribute;
using FieldOffsetAttribute = System.Runtime.InteropServices.FieldOffsetAttribute;

class P
{
    static void Main()
    {
        //??????
        var xy = Console.ReadLine().Split().Select(long.Parse).ToList();
        Console.WriteLine(Abs(xy[0] - xy[1]) <= 1 ? "Brown" : "Alice");
    }
}