using System;

class Program
{
    static void Main()
    {
        string a = Console.ReadLine();
        switch (a)
        {
            case "A":a = "T";break;
            case "T":a = "A";break;
            case "G": a = "C"; break;
            case "C": a = "G"; break;
        }
        Console.WriteLine(a);
    }
}