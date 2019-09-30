using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //??A??????
        //??B??????

        //????#?50*100???.????????
        //????.?50*100???#????????
        char[][] res = Enumerable.Range(0, 100).Select(x => Enumerable.Repeat((x < 50 ? '#' : '.'), 100).ToArray()).ToArray();
        a[0]--;
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (a[0] == 0) goto end1;
                res[i * 2][j * 2] = '.';
                a[0]--;
            }
        }
        end1:;
        a[1]--;
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (a[1] == 0) goto end2;
                res[51 + i * 2][j * 2] = '#';
                a[1]--;
            }
        }
        end2:;

        Console.WriteLine("100 100");
        Console.WriteLine(string.Join("\n",res.Select(x => string.Join("",x)).ToArray()).ToArray());
    }
}