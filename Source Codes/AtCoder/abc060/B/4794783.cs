using System;

class Program
{
    static void Main(string[] args)
    {
        var x = Console.ReadLine().Split();
        var a = int.Parse(x[0]);
        var b = int.Parse(x[1]);
        var c = int.Parse(x[2]);

        for (int i = 0; i < b; i++)
        {
            if (a * i % b == c)
            {
                Console.WriteLine("YES");
                return;
            }
        }

        Console.WriteLine("NO");
    }
}