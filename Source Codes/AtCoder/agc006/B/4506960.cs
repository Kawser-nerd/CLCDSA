using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;

class P
{
    static void Main()
    {
        var Nx = Console.ReadLine().Split().Select(int.Parse).ToList();
        if (Nx[0] == 2)
        {
            if (Nx[1] == 2)
            {
                Console.WriteLine("Yes");
                Console.WriteLine("1 2 3");
            }
            else
            {
                Console.WriteLine("No");
            }
            return;
        }
        var count = Nx[0] * 2 - 1;
        int lb = Nx[1] - 2;
        int ub = Nx[1] + 2;
        int headCount = (count - 5) / 2;
        int tailCount = (count - 5) / 2;
        int[] mid = new int[] { Nx[1] + 2, Nx[1] - 1, Nx[1], Nx[1] + 1, Nx[1] - 2 };
        if (lb < 0 || count + 1 < ub)
        {
            Console.WriteLine("No");
            return;
        }
        else if (lb < 1 || count < ub)
        {
            if (lb < 1)
            {
                lb++;
                tailCount++;
                mid = new int[] { Nx[1] + 2, Nx[1] - 1, Nx[1], Nx[1] + 1 };
            }
            if (count < ub)
            {
                ub--;
                headCount++;
                mid = new int[] { Nx[1] - 1, Nx[1], Nx[1] + 1, Nx[1] - 2 };
            }
        }
        
        Console.WriteLine("Yes");
        List<int> collection = Enumerable.Range(1, count).Where(x => x < lb || ub < x).ToList();
        Console.WriteLine(string.Join("\n",collection.Take(headCount).Concat(mid).Concat(collection.Skip(headCount))));
    }
}