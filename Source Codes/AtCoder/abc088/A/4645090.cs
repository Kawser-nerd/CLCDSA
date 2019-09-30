using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine()) % 500;
        var a = int.Parse(Console.ReadLine());

        if (n <= a)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}