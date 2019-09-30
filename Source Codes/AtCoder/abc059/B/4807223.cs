using System;

class Program
{
    static void Main(string[] args)
    {
        var A = Console.ReadLine();
        var B = Console.ReadLine();

        if (A == B)
        {
            Console.WriteLine("EQUAL");
        }
        else if (A.Length == B.Length)
        {
            if (0 < A.CompareTo(B))
            {
                Console.WriteLine("GREATER");
            }
            else
            {
                Console.WriteLine("LESS");
            }
        }
        else if (A.Length < B.Length)
        {
            Console.WriteLine("LESS");
        }
        else
        {
            Console.WriteLine("GREATER");
        }
    }
}