using System;

class Program
{
    static void Main(string[] args)
    {
        string s = Console.ReadLine();

        switch (s)
        {
            case "A":
                Console.WriteLine("T");
                break;
            case "T":
                Console.WriteLine("A");
                break;
            case "G":
                Console.WriteLine("C");
                break;
            case "C":
                Console.WriteLine("G");
                break;
            default:
                break;
        }

    }
}