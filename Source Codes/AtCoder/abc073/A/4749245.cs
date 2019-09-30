using System;

class Program
{
    static void Main(string[] args)
    {
        var n = Console.ReadLine();
        if (n[0] == '9' || n[1] == '9')
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}