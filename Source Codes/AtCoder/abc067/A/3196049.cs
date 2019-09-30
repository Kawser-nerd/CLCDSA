using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num1 = Convert.ToInt32(input[0]);
        var num2 = Convert.ToInt32(input[1]);

        var result = num1 % 3 == 0 || num2 % 3 == 0 || (num1 + num2) % 3 == 0 ? "Possible" : "Impossible";
        Console.WriteLine(result);
    }
}