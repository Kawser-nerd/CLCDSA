using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num1 = Convert.ToInt32(input[0]);
        var num2 = Convert.ToInt32(input[1]);
        var num3 = Convert.ToInt32(input[2]);

        Console.WriteLine(num1 * num3*2+num2*num3*2+num1*num2*2);
    }
}