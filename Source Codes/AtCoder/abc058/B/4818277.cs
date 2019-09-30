using System;

class Program
{
    static void Main(string[] args)
    {
        var o = Console.ReadLine();
        var e = Console.ReadLine();

        for (int i = 0; i < o.Length + e.Length; i++)
        {
            if (i % 2 == 1)
            {
                Console.Write(e[i / 2]);
            }
            else
            {
                Console.Write(o[i / 2]);
            }
        }
        Console.WriteLine();
    }
}