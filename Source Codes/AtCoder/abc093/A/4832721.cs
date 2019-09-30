using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        string s = Console.ReadLine();
        Console.WriteLine(s.Contains('a') && s.Contains('b') && s.Contains('c') ? "Yes" : "No");
    }
}