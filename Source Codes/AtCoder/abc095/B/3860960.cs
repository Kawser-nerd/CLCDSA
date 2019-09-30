using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
class ABC95B
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int X = int.Parse(input[1]);

        List<int> recips =new  List<int>();

        for (int i = 0; i < N; i++)
        {
            recips.Add(int.Parse(Console.ReadLine()));
        }
        int a = recips.Sum();
        recips.Sort();
    

        Console.WriteLine(N + (X - a )/recips[0]);
    }
}