using System;
using System.Linq;
class Problem
{
    static void Main()
    {
        int[] num = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int a = num[0];
        int b = num[1];
        if (b % a == 0)
        {
            Console.WriteLine(b + a);
        }
        else
        {
            Console.WriteLine(b - a);
        }
    }
}