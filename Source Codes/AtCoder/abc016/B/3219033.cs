using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num1 = Convert.ToInt32(input[0]);
        var num2 = Convert.ToInt32(input[1]);
        var result = Convert.ToInt32(input[2]);

        if (num2 == 0)
        {
            if (num1 - num2 == result) Console.WriteLine("?");
            else Console.WriteLine("!");
        }
        else if (result == num1 + num2) Console.WriteLine("+");
        else if (result == num1 - num2) Console.WriteLine("-");
        else Console.WriteLine("!");
    }
}