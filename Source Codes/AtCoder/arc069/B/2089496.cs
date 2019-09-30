using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        //[????][??][???]
        int[][][] q =
        {
            //?
            new int[][]
            {
                //?
                new int[]{0,1},
                //?
                new int[]{1,0}
            },
            //×
            new int[][]
            {
                //?
                new int[]{1,0},
                //?
                new int[]{0,1}
            }
        };
        int n = int.Parse(Console.ReadLine());
        int[] s = Console.ReadLine().Select(x => x == 'o' ? 0 : 1).ToArray();
        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                int[] a = new int[n];
                a[0] = i;
                a[1] = j;
                for (int k = 2; k < n; k++)
                {
                    a[k] = q[s[k - 1]][a[k - 1]][a[k - 2]];
                }
                if (q[s[n - 1]][a[n - 1]][a[n - 2]] == a[0] && q[s[0]][a[0]][a[n - 1]] == a[1])
                {
                    Console.WriteLine(string.Join("", a.Select(x => x == 0 ? "S" : "W").ToArray()));
                    return;
                }
            }
        }
        Console.WriteLine(-1);
    }
}