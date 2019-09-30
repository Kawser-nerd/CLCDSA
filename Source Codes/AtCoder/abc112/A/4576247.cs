using System;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        if (n == 1) Console.WriteLine("Hello World");
        else {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            Console.WriteLine(a+b);
        }
    }
}