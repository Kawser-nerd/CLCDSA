using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] point = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        string res = "YES";
        for (int i = 0; i < s.Length / 2; i++)
        {
            if (s[i] != '*' && s[s.Length - 1 - i] != '*' && s[i] != s[s.Length - 1 - i]) res = "NO";
        }
        Console.WriteLine(res);
    }
}