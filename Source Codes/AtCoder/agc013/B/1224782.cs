#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
// Do not use: System.Numerics; at CodeIQ

public class Test
{
    public class Collision
    {
        public int X;
        public int Y;
    }

    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();
        var N = line1[0];  // ???
        var M = line1[1];  // ???

        var edges = Enumerable.Range(0, N).Select(x => new List<int>()).ToArray();  // ?????

        List<int> leftside = new List<int>();  // ???????????
        List<int> rightside = new List<int>();  // ???????????

        bool[] contains = new bool[N];  // ???????????????

        for (int i = 0; i < M; i++)
        {
            var line2 = Console.ReadLine().Split(' ').Select(x => Int32.Parse(x) - 1).ToArray();  // 0???????

            edges[line2[0]].Add(line2[1]);
            edges[line2[1]].Add(line2[0]);

            if (i == 0)
            {
                leftside.Add(line2[0]);
                rightside.Add(line2[1]);

                contains[line2[0]] = true;
                contains[line2[1]] = true;
            }
        }

        int lastpos = leftside[leftside.Count - 1];  // ???? Count == 1
        while (true)
        {
            int nextpos = -1;
            foreach (var pos in edges[lastpos])
            {
                if (!contains[pos])
                {
                    // ????????????????

                    leftside.Add(pos);
                    contains[pos] = true;
                    nextpos = pos;
                    break;
                }
            }

            if (nextpos == -1)
            {
                break;
            }

            lastpos = nextpos;
        }

        // ???
        lastpos = rightside[rightside.Count - 1];  // ???? Count == 1
        while (true)
        {
            int nextpos = -1;
            foreach (var pos in edges[lastpos])
            {
                if (!contains[pos])
                {
                    // ????????????????

                    rightside.Add(pos);
                    contains[pos] = true;
                    nextpos = pos;
                    break;
                }
            }

            if (nextpos == -1)
            {
                break;
            }

            lastpos = nextpos;
        }

        var path = ((IEnumerable<int>)leftside).Reverse().Concat(rightside).Select(x => x + 1).ToArray();  // 1???????

        Console.WriteLine(path.Length);
        Console.WriteLine(String.Join(" ", path));
    }
}