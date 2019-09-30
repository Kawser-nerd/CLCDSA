using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var now = Convert.ToInt32(input[0]);
        var span = Convert.ToInt32(input[1]);

        Console.WriteLine((now + span) % 24);
    }
}