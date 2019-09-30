using System;

class Program
{
    static void Main(string[] args)
    {
        var ny = Console.ReadLine().Split(' ');
        var n = int.Parse(ny[0]);
        var y = int.Parse(ny[1]) / 1000;

        for (int i = 0; i <= y / 10; i++)
        {
            for (int j = 0; j <= (y - i * 10) / 5; j++)
            {
                var k = y - i * 10 - j * 5;
                if (i + j + k == n)
                {
                    Console.WriteLine($"{i} {j} {k}");
                    return;
                }
            }
        }

        Console.WriteLine("-1 -1 -1");
    }
}