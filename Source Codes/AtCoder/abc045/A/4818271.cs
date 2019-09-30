using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //string[] input = Console.ReadLine().Split();
        int a=int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int c = int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(((double)(a+b)/2)*c);
        Console.ReadLine();
    }
}