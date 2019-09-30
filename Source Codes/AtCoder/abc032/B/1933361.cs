using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        int n = int.Parse(Console.ReadLine());
        //int[] NQ = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //string[][] s = new string[n][].Select(_ => Console.ReadLine().Split()).ToArray();
        //int sum = 0;
        List<string> list = new List<string>();
        for (int i = 0; i <= s.Length - n; i++)
        {
            string substr = s.Substring(i,n);
            if(!list.Contains(substr)) list.Add(substr);
        }
        Console.WriteLine(list.Count);
    }
}