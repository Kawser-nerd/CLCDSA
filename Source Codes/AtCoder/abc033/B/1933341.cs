using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //string a = Console.ReadLine();
        int n = int.Parse(Console.ReadLine());
        //int[] NQ = Console.ReadLine().Split().Select(int.Parse).ToArray();
        string[][] s = new string[n][].Select(_ => Console.ReadLine().Split()).ToArray();
        int sum = 0;
        foreach (var aet in s)
        {
            sum += int.Parse(aet[1]);
        }
        string name = "atcoder";
        foreach (var aet in s)
        {
            if (int.Parse(aet[1]) * 2 > sum)
            {
                name = aet[0];
                break;
            }
        }
        Console.WriteLine(name);
    }
}