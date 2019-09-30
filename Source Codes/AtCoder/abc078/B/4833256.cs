using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
            string[] input = Console.ReadLine().Split(' ');
            int x = int.Parse(input[0]), y = int.Parse(input[1]), z = int.Parse(input[2]);
            Console.WriteLine((x - z) / (y + z));
        }
    }
    //mcs Main.cs
    //mono Main.exe