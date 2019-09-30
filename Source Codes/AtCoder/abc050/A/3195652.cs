using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num1 = Convert.ToInt32(input[0]);
        var num2 = Convert.ToInt32(input[2]);
        var result = input[1] == "+" ? num1 + num2 : num1 - num2;
        Console.WriteLine(result);
    }
}