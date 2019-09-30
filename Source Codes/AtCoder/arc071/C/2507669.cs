using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {

        //a
        //aa
        //aaa

        // baaaab
        //?????????????????(Substr????????????????????)

        //a,aa,aaa??????????????
        string s = Console.ReadLine();
        int[] sruiseki = new int[s.Length + 1];
        for (int i = 0; i < s.Length; i++) sruiseki[i + 1] = sruiseki[i] + (1 + (s[i] - 'A'));
        string t = Console.ReadLine();
        int[] truiseki = new int[t.Length + 1];
        for (int i = 0; i < t.Length; i++) truiseki[i + 1] = truiseki[i] + (1 + (t[i] - 'A'));
        int q = int.Parse(Console.ReadLine());
        for (int i = 0; i < q; i++)
        {
            int[] abcd = Console.ReadLine().Split().Select(int.Parse).ToArray();
            if ((sruiseki[abcd[1]] - sruiseki[abcd[0] - 1]) % 3 == (truiseki[abcd[3]] - truiseki[abcd[2] - 1]) % 3) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
}