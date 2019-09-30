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
        var nx = Console.ReadLine().Split().Select(int.Parse).ToList();
        var h = Console.ReadLine().Split().Select(int.Parse).ToList();
        List<int>[] connect = Enumerable.Repeat(0, nx[0]).Select(_ => new List<int>()).ToArray();
        for (int i = 0; i < nx[0] - 1; i++)
        {
            var a = Console.ReadLine().Split().Select(int.Parse).ToList();
            connect[a[0] - 1].Add(a[1] - 1);
            connect[a[1] - 1].Add(a[0] - 1);
        }
        int total = nx[0];
        int[] parents = Enumerable.Repeat(-1, nx[0]).ToArray();
        Stack<int> stack = new Stack<int>();
        stack.Push(nx[1] - 1);
        parents[nx[1] - 1] = -2;
        while (stack.Count > 0)
        {
            int elem = stack.Pop();
            bool isLeaf = true;
            foreach (var item in connect[elem])
            {
                if (parents[item] == -1)
                {
                    isLeaf = false;
                    parents[item] = elem;
                    stack.Push(item);
                }
            }
        }
        bool[] arrived = new bool[nx[0]];
        arrived[nx[1] - 1] = true;
        foreach (var item in h.Select((x,y) => new Tuple<int,int>(x,y)).Where(x => x.Item1 == 1).Select(x => x.Item2))
        {
            int elem = item;
            while (elem >= 0 && !arrived[elem])
            {
                arrived[elem] = true;
                elem = parents[elem];
            }
        }
        Console.WriteLine((arrived.Count(x => x) - 1) * 2);
    }
}