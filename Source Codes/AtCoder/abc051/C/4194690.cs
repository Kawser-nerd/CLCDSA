using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int dx = inputs[2] - inputs[0];
        int dy = inputs[3] - inputs[1];
        for (int i = 0; i < dx; i++)
            Console.Write('R');
        for (int i = 0; i < dy; i++)
            Console.Write('U');
        for (int i = 0; i < dx; i++)
            Console.Write('L');
        for (int i = 0; i <= dy; i++)
            Console.Write('D');
        for (int i = 0; i <= dx; i++)
            Console.Write('R');
        for (int i = 0; i <= dy; i++)
            Console.Write('U');
        Console.Write("LU");
        for (int i = 0; i <= dx; i++)
            Console.Write('L');
        for (int i = 0; i <= dy; i++)
            Console.Write('D');
        Console.WriteLine('R');
    }
}