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
        var nm = Console.ReadLine().Split().Select(int.Parse).ToList();
        Console.WriteLine(Enumerable.Repeat(0, nm[0]).Aggregate(Enumerable.Range(1, nm[1]), (x, y) => x.Intersect(Console.ReadLine().Split().Skip(1).Select(int.Parse))).Count());
        
    }
}