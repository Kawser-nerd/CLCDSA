using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        if (n % 111 == 0)
        {
            Console.WriteLine(n);
        }
        else
        {
            Console.WriteLine((n / 111 + 1) * 111);
        }
    }
}