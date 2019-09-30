using System;
using System.Collections.Generic;
using System.Collections;


class p
{
    static void Main(string[] args)
    {
        long N = long.Parse(Console.ReadLine());
        bool d = true;//??????

        for(int i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                d = false;
                break;
            }
        }

        if (d) Console.WriteLine("YES");
        else Console.WriteLine("NO");

    }   
}