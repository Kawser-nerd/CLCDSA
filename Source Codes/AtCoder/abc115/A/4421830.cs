using System;

class Program
{
    static void Main(string[] args)
    {
        switch (Console.ReadLine())
        {
            case "25":
                Console.WriteLine("Christmas");
                return;
            case "24":
                Console.WriteLine("Christmas Eve");
                return;
            case "23":
                Console.WriteLine("Christmas Eve Eve");
                return;
            case "22":
                Console.WriteLine("Christmas Eve Eve Eve");
                return;
        }
    }
}