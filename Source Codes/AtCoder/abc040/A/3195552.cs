using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num = Convert.ToInt32(input[0]);
        var blue = Convert.ToInt32(input[1]);

        if (blue <= num / 2) Console.WriteLine(blue - 1);
        else Console.WriteLine(num - blue);
    }
}