using System;
class Program
{
    static int Main(string[] args)
    {
        switch (Console.ReadLine())
        {
            case "A":
                Console.WriteLine("T");
                break;
            case "T":
                Console.WriteLine("A");
                break;
            case "C":
                Console.WriteLine("G");
                break;
            case "G":
                Console.WriteLine("C");
                break;
        }
        return 0;
    }
}