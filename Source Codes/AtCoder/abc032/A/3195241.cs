using System;

class Program
{
    static void Main(string[] args)
    {
        var num1 = Convert.ToInt32(Console.ReadLine());
        var num2 = Convert.ToInt32(Console.ReadLine());
        var min = Convert.ToInt32(Console.ReadLine());

        for(var i = min; i < int.MaxValue; i++)
        {
            if (i % num1 == 0 && i % num2 == 0)
            {
                Console.WriteLine(i); break;
            }
        }
    }
}