using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        //List<int> values = new List<int>(Console.ReadLine().Split(' ').Select(s => int.Parse(s)));
        //List<int> values = new List<int>();

        string input = Console.ReadLine();
        int n = int.Parse(input.Split(' ')[0]);
        int m = int.Parse(input.Split(' ')[1]);
        int k = int.Parse(input.Split(' ')[2]);

        if (input == "5 5 7")
        {
            Console.WriteLine("YES"); return;
        }
        if (input == "5 7 5")
        {
            Console.WriteLine("YES"); return;
        }
        if (input == "7 5 5")
        {
            Console.WriteLine("YES"); return;
        }


        Console.WriteLine("NO");
        
    }
}