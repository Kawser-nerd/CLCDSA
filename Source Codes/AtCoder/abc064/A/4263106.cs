using System;

class AtCoder
{    
    static void Main(string[] args)
     {
        string input = Console.ReadLine().Replace(" ", "");

        var s = int.Parse(input) % 4 == 0 ? "YES" : "NO";
        Console.WriteLine(s);
     }
 }