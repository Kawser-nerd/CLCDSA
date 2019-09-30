using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using static System.Math;
using Debug = System.Diagnostics.Debug;


static class P
{
    static void Main()
    {
        var nm = Console.ReadLine().Split().Select(int.Parse).ToList();
        //???3?????????????????
        //???????????????????????
        //??????????????
        //??2????0???????
        //???2?????????
        //?????????????????2???????????
        //
        //??????2???????
        //
        //????????
        HashSet<int>[] neighbours = Enumerable.Repeat(0, nm[0]).Select(_ => new HashSet<int>()).ToArray();
        for (int i = 0; i < nm[1]; i++)
        {
            var ab = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToArray();
            neighbours[ab[0]].Add(ab[1]);
            neighbours[ab[1]].Add(ab[0]);
        }
        if(neighbours.Any(x => x.Count % 2 != 0))
        {
            Console.WriteLine("No");
            return;
        }

        int loopCount = 0;
        Stack<int> stack = new Stack<int>();
        for (int i = 0; i < nm[0]; i++) stack.Push(i);
        while (stack.Count > 0)
        {
            var elem = stack.Pop();
            if (neighbours[elem].Count != 2) continue;

            var arr = neighbours[elem].ToArray();

            neighbours[elem].Clear();
            neighbours[arr[0]].Remove(elem);
            neighbours[arr[1]].Remove(elem);
            if (!neighbours[arr[0]].Add(arr[1]) & !neighbours[arr[1]].Add(arr[0]))
            {
                neighbours[arr[0]].Remove(arr[1]);
                neighbours[arr[1]].Remove(arr[0]);
                loopCount++;
            }
            stack.Push(arr[0]);
            stack.Push(arr[1]);
        }

        Console.WriteLine(neighbours.Any(x => x.Count > 2) || loopCount >= 3 ? "Yes" : "No");
    }
}