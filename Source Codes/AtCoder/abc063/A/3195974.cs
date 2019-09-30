using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num1 = Convert.ToInt32(input[0]);
        var num2 = Convert.ToInt32(input[1]);

        if (num1 + num2 >= 10) Console.WriteLine("error");
        else Console.WriteLine(num1 + num2);
    }
}