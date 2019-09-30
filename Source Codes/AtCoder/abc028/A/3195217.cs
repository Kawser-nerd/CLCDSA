using System;

class Program
{
    static void Main(string[] args)
    {
        var score = Convert.ToInt32(Console.ReadLine());
        var str = "";
        if (score < 60) str = "Bad";
        else if (score < 90) str = "Good";
        else if (score < 100) str = "Great";
        else str = "Perfect";
        Console.WriteLine(str);
    }
}