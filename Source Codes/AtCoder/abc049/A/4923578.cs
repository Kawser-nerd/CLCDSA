using System;

class Program
{
    static void Main(string[] args)
    {
        var c = Console.ReadLine();
        switch (c)
        {
            case "a":
            case "i":
            case "u":
            case "e":
            case "o":
                Console.WriteLine("vowel");
                break;
            default:
                Console.WriteLine("consonant");
                break;
        }
    }
}