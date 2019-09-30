using System;
class Program
{
    static void Main(string[] args)
    {
        string input = Console.ReadLine();
        if (input == "A")
            Console.WriteLine('T');
        if (input == "T")
            Console.WriteLine('A');
        if (input == "C")
            Console.WriteLine('G');
        if (input == "G")
            Console.WriteLine('C');
    }
}