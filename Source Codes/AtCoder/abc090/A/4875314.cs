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
        string[] input = new string[3];
        for (int a = 0; a < 3; a++)
        {
            input[a] = Console.ReadLine();
        }
        //int input =int.Parse(input[0]+""+input[3+1]+""+input[3*2+2]);
        Console.WriteLine(input[0][0] + "" + input[1][1] + "" + input[2][2]);


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