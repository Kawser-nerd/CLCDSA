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
        //string[] input = Console.ReadLine().Split().Select(i => i).ToArray();
        //string input= Console.ReadLine();
        //int i = int.Parse(Console.ReadLine());
        int[] input = new int[3];
        for (int a = 0; a < input.Length; a++)
        {
            input[a] = int.Parse(Console.ReadLine());
        }
        int max = Math.Max(input[0], input[1]);
        int min =  Math.Min(input[0], input[1]);
        int[] temp = new int [3]{ max,min,max%min};
        while (temp[0] % temp[1] != 0)
        {
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[0] % temp[1];
        }
        int cm = ((input[0] * input[1]) / temp[1]);
        Console.WriteLine(cm*Math.Ceiling((double)input[2]/cm));


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