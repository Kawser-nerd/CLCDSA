using System;

class Program
{
    static void Main(string [] args)
    {
        var maxValue = 2025;
        var value = maxValue - int.Parse(Console.ReadLine());

        for (var i = 1 ; i <= value; i++)
        {
            if ((value % i) != 0) continue;
            if (i > 9 || value/i > 9) continue;
            Console.WriteLine(i + " x " + value/i);
        }
    }
}