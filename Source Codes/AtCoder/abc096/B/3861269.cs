using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
class ABC96B
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        List<int> NUM =new  List<int>();
        foreach(string line in input)
        {
            NUM.Add(int.Parse(line));
        }
        NUM.Sort();
        NUM.Reverse();

        int n = int.Parse(Console.ReadLine());
        while (n > 0)
        {
            NUM[0] *= 2;
            n--;
        }
        Console.WriteLine(NUM.Sum());
    }
}