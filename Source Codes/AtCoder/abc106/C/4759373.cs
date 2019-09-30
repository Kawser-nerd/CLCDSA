using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        string S = Console.ReadLine();
        long K = long.Parse(Console.ReadLine());
        for(int i = 0; i < K; i++)
        {
            if (S[i] != '1')
            {
                Console.WriteLine(S[i]);
                return;
            }
        }
        Console.WriteLine('1');
    }
}