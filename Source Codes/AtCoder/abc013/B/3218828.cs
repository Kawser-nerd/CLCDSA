using System;

class Program
{
    static void Main(string[] args)
    {
        var now = Convert.ToInt32(Console.ReadLine());
        var num = Convert.ToInt32(Console.ReadLine());

        var result = 0;
        if (num >= now) result = num - now <= (10 - num) + now ? num - now : (10 - num) + now;
        else result = now - num < num + (10 - now) ? now - num : num + (10 - now);
        Console.WriteLine(result);
    }
}