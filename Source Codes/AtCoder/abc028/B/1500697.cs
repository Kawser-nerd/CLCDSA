using System;
using System.Collections.Generic;
 
class Program
{
    static void Main(string [] args)
    {
        var str = Console.ReadLine();
        var l = new List<int>() { 0, 0, 0, 0, 0, 0 };
        foreach(var c in str)
        {
            l[c - 'A']++;
        }
        
        var result = string.Empty;
        for (var i = 0; i < 6; i++)
        {
            if (i > 0) result += " ";
            result += l[i].ToString();
        }

        Console.WriteLine(result);
    }
}