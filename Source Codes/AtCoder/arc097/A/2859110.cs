using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string s = Console.ReadLine();
        int k = int.Parse(Console.ReadLine());
        int n = s.Length;
        Dictionary<string, int> dic = new Dictionary<string, int>();

        for (int i = 0; i < n; i++)
        {
            for(int j = 1; i + j <= n && j <= 5; j++)
            {
                dic[s.Substring(i, j)] = 0;
            }
        }
        string[] keys = dic.Keys.ToArray();
        Array.Sort(keys);

        Console.WriteLine(keys[k - 1]);
    }
}