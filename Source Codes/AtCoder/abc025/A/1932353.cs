using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        string[] str = { "aa", "ab", "ac", "ad", "ae", "ba", "bb", "bc", "bd", "be", "ca", "cb", "cc", "cd", "ce", "da", "db", "dc", "dd", "de", "ea", "eb", "ec", "ed", "ee" };
        string s = Console.ReadLine();
        int a = int.Parse(Console.ReadLine());
        string res = str[a - 1].Replace('e', s[4]).Replace('d', s[3]).Replace('c', s[2]).Replace('b', s[1]).Replace('a', s[0]);
        Console.WriteLine(res);
    }
}