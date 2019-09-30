using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        if (int.Parse(ab[0]) % int.Parse(ab[1]) == 0)
        {
            Console.WriteLine(0);
        }
        else
        {
            Console.WriteLine(1);
        }
    }
}