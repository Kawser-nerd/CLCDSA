using System;
using System.Linq;
class Program
{
    static void Main()
    {
        string input = Console.ReadLine();
        if (input[input.Length - 1].ToString()=="T")
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
        Console.ReadLine();
    }
}