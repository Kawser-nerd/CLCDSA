using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string a = Console.ReadLine();
        int t = int.Parse(Console.ReadLine());
        //int[] NQ = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //string[] s = new string[a].Select(_ => Console.ReadLine()).ToArray();
        int missing = 0;
        int[] pos = new int[2];
        foreach (var c in a)
        {
            switch (c)
            {
                case 'L':
                pos[0]--;
                break;
                case 'R':
                pos[0]++;
                break;
                case 'U':
                pos[1]--;
                break;
                case 'D':
                pos[1]++;
                break;
                default:
                missing++;
                break;
            }
        }
        int res = 0;
        if (t == 1)
        {
            res = (Math.Abs(pos[0]) + Math.Abs(pos[1])) + missing;
        }
        else
        {
            res = (Math.Abs(pos[0]) + Math.Abs(pos[1])) - missing;
            if (res < 0) res = Math.Abs(res) % 2;
        }
        Console.WriteLine(res);
    }
}