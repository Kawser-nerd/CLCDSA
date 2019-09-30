using System;

public class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        for (int cake = 0; cake <= n / 4; cake++)
        {
            for (int donut = 0; donut <= n / 7; donut++)
            {
                if (n == cake * 4 + donut * 7)
                {
                    Console.WriteLine("Yes");
                    return;
                }
            }
        }

        Console.WriteLine("No");
    }
}