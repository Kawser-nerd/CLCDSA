using System;
using static System.Console;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int count = int.Parse(ReadLine().Split(' ')[0]);
        string[] input = new string[count];

        for(int i = 0; i < count; i++)
        {
            input[i] = ReadLine();
        }

        List<string> str = new List<string>(input);
        str.Sort();

        string output = "";
        foreach(string s in str)
        {
            output = output + s;
        }

        Console.WriteLine(output);
        ReadKey();
    }
}