using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var before = Convert.ToInt32(input[0]);
        var after = Convert.ToInt32(input[1]);

        var str = "";
        if (before > after) str = "Worse";
        else str = "Better";
        Console.WriteLine(str);
    }
}