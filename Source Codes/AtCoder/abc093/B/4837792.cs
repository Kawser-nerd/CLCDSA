using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var list = new SortedSet<int>();
        for (int i = 0; i < s[2]; i ++) {
            list.Add(s[0]+i);
            list.Add(s[1]-i);
            if (s[0]+i >= s[1]-i) break;
        }
        foreach (int i in list) Console.WriteLine(i);
    }
}