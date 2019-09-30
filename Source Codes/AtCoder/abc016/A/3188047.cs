using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var month = Convert.ToInt32(input[0]);
        var day = Convert.ToInt32(input[1]);

        var str = month % day == 0 ? "YES" : "NO";
        Console.WriteLine(str);
    }
}