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
        //int[] input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();
        //string input= Console.ReadLine();
        int[] input = new int[2];
        for (int a = 0; a < 2; a++)
        {
            input[a] = int.Parse(Console.ReadLine());
        }
        //int input =int.Parse(input[0]+""+input[3+1]+""+input[3*2+2]);
        Console.WriteLine(input[0]%500<=input[1]?"Yes":"No");


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