using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select(int.Parse).ToList();
        var grouped = a.GroupBy(x => x).OrderBy(x => x.Key).ToArray();
        if (grouped.Length >= 3) goto end;
        if (grouped.Length == 2)
        {
            if (grouped[1].Key - grouped[0].Key != 1) goto end;
            int single = grouped[0].Count();
            int many = grouped[1].Count();
            int max = many / 2 + single;
            int min = 1 + single;
            if (grouped[1].Key < min || max < grouped[1].Key) goto end;
        }
        if(grouped.Length == 1)
        {
            int count = grouped[0].Count();
            int max = count / 2;
            int min = 1;
            if (grouped[0].Key != count - 1 && (grouped[0].Key < min || max < grouped[0].Key)) goto end;
        }

        Console.WriteLine("Yes");
        return;
        end:Console.WriteLine("No");
    }
}