using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        //var exStdIn = new System.IO.StreamReader("C:\\Users\\hmakita\\Downloads\\even_0.txt");
        //System.Console.SetIn(exStdIn);

        long n = long.Parse(Console.ReadLine());
        long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long[] l = new long[2 * n + 2];
        List<long> forward = new List<long>();
        List<long> backward = new List<long>();
        int direction = 1;
        
        for(long i = 0; i < n; i++)
        {
            if(direction == 1)
            {
                forward.Add(a[i]);
            }
            else
            {
                backward.Add(a[i]);
            }
            direction *= -1;
        }

        if(direction == 1)
        {
            backward.Reverse();
            long size = backward.Count();
            long count = 1;

            foreach(var item in backward)
            {
                Console.Write(item);
                if(count++ != size)
                {
                        Console.Write(" ");
                }
            }
            size = forward.Count();
            count = 1;

            if(size > 0)
            {
                Console.Write(" ");
            }

            foreach (var item in forward)
            {
                Console.Write(item);
                if (count++ != size)
                {
                    Console.Write(" ");
                }
            }
            //Console.WriteLine(String.Join(" ", list.ToArray()));
        }
        else
        {

            forward.Reverse();
            long size = forward.Count();
            long count = 1;

            foreach (var item in forward)
            {
                Console.Write(item);
                if (count++ != size)
                {
                    Console.Write(" ");
                }
            }

            size = backward.Count();
            count = 1;

            if (size > 0)
            {
                Console.Write(" ");
            }

            foreach (var item in backward)
            {
                Console.Write(item);
                if (count++ != size)
                {
                    Console.Write(" ");
                }
            }

        }
    }
}