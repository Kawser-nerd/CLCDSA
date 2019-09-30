using System;

class Program
{
    static void Main(string[] args)
    {
        switch (Console.ReadLine())
        {
            case "7":
            case "5":
            case "3":
                Console.WriteLine("YES");
                return;
            default:
                Console.WriteLine("NO");
                return;
        }
    }
}