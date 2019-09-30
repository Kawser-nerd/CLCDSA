using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine();
        var nums = new HashSet<int>();
        for(var i = 0; i < 4; i++)
        {
            nums.Add(Convert.ToInt32(input.Substring(i, 1)));
        }
        var str = "";
        if (nums.Count == 1) str = "SAME";
        else str = "DIFFERENT";

        Console.WriteLine(str);
    }
}