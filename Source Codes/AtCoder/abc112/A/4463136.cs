using System;

class Program
{
    static void Main(string[] args)
    {
        switch (Console.ReadLine())
        {
            case "1":
                Console.WriteLine("Hello World");
                return;
            case "2":
                Console.WriteLine(
                    int.Parse(Console.ReadLine()) +
                    int.Parse(Console.ReadLine()));
                return;
        }
    }
}