using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
class Program
{
    static void Main()
    {
        //??
        //int n = 100;
        /*
        long n = long.Parse(Console.ReadLine());
        long[] input = new long[5];
        for(int a = 0; a < 5; a++)
        {
            input[a]=long.Parse(Console.ReadLine());
        }
        */
        int[] g1 = {1,3,5,7,8,10,12 };
        int[] g2 = { 4,6,9,11};
        int[] g3 = { 2};
        int[] input = Console.ReadLine().Split().Select(i =>int.Parse(i)).ToArray();

        Console.WriteLine((Array.IndexOf(g1,input[0])>-1&& Array.IndexOf(g1, input[1])>-1)|| (Array.IndexOf(g2, input[0])>-1 && Array.IndexOf(g2, input[1])>-1) ?"Yes":"No");

        /*
        //??????
        var sw = new System.Diagnostics.Stopwatch();
        sw.Start();
        //??

        //??????
        sw.Stop();
        TimeSpan ts = sw.Elapsed;
        Console.WriteLine((int)(Math.Floor((ts).TotalMilliseconds))+"ms");
        */
        Console.ReadLine();
        
    }
}