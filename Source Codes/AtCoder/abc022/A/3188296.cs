using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num = Convert.ToInt32(input[0]);
        var min = Convert.ToInt32(input[1]);
        var max = Convert.ToInt32(input[2]);
        var wigth = Convert.ToInt32(Console.ReadLine());

        var difs = new int[num - 1];
        for(var i = 1; i < num; i++)
        {
            difs[i - 1] = Convert.ToInt32(Console.ReadLine());
        }

        var counter = 0;
        if (wigth >= min && wigth <= max) counter++;
        for(var i = 0; i < num-1; i++)
        {
            wigth += difs[i];
            if (wigth >= min && wigth <= max) counter++;
        }

        Console.WriteLine(counter);
    }
}