using System;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ??
        int N = int.Parse(Console.ReadLine());
        decimal ret = 0;
        for (int i = 0; i < N; i++ )
        {
            string[] input = Console.ReadLine().Split(' ');
            if(input[1].CompareTo("BTC") == 0)
            {
                ret += decimal.Parse(input[0]) * 380000;
            }
            else
            {
                ret += int.Parse(input[0]);
            }
        }

        Console.WriteLine(ret);
    }

}