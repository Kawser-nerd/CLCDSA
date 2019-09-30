using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] s = Console.ReadLine().Split().Select(x => x[0] - '0').ToArray();
        int[] code = new int[10];
        for (int i = 0; i < s.Length; i++)
        {
            code[s[i]] = i;
        }
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(string.Join("\n",Enumerable.Repeat(0,n).Select(_ => Console.ReadLine()).OrderBy(x => decode(x,code)).ToArray()));
    }
    static int decode(string s, int[] code)
    {
        int res = 0;
        for (int i = 0; i < s.Length; i++)
        {
            res = res * 10 + code[s[i] - '0'];
        }
        return res;
    }
}