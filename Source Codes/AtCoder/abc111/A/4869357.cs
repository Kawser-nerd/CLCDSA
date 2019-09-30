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
        //int input =int.Parse(Console.ReadLine());
        char[] str = Console.ReadLine().ToCharArray();
        for(int a = 0; a < str.Length; a++)
        {
            if (str[a]=='1')
            {
                str[a]='9';
            }
            else
            {
                str[a] = '1';
            }
        }
        Console.WriteLine(string.Join("",str));


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