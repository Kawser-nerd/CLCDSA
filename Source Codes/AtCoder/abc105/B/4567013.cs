using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        for (int i = 0; i <= n / 4; i++)
        {
            for (int j = 0; j <= n / 7; j++)
            {
                if (i * 4 + j * 7 == n)
                {
                    Console.WriteLine("Yes");
                    return;
                }
            }
        }
        Console.WriteLine("No");
    }
}