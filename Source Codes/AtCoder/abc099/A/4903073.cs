using System;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n < 1000 ? "ABC" : "ABD");
    }
}