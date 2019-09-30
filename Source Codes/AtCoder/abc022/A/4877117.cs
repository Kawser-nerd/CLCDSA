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
        //string input= Console.ReadLine();
        int[] nst = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();
        //string[] input = Console.ReadLine().Split().Select(i => i).ToArray();
        //
        int w = int.Parse(Console.ReadLine());
        
        int[] input = new int[nst[0]-2+1];
        for (int a = 0; a < input.Length; a++)
        {
            input[a] = int.Parse(Console.ReadLine());
        }

        int count = 0;
        if (nst[1] <= w && w <= nst[2]) count++;
        int weight = w;
        for(int a = 0; a < input.Length; a++)
        {
            weight += input[a];
            if (nst[1] <= weight&& weight <= nst[2]) count++;
        }
        /*
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
        */
        Console.WriteLine(count);


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