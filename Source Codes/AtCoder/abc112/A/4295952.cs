using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Numerics;

public class Program
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        if (n == 1)
        {
            Console.WriteLine("Hello World");
            Console.ReadLine();
            return;
        }

        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());


        Console.WriteLine(a + b);
        Console.ReadLine();
    }
}