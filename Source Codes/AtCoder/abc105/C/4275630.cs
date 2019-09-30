using System;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        Stack<int> d = new Stack<int>();
        while (N != 0)
        {
            if (N % 2 != 0)
            {
                d.Push(1);
                N--;
            }
            else
                d.Push(0);
            N /= 2;
            N = -N;
        }
        if (d.Count == 0)
            Console.WriteLine(0);
        else
        {
            while (d.Count != 0)
                Console.Write(d.Pop());
            Console.WriteLine();
        }
    }
}