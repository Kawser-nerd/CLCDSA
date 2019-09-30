using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        string[] s = Console.ReadLine().Split('/').ToArray();
        s[0] = "2018";
        Console.WriteLine("{0}/{1}/{2}", s[0], s[1], s[2]);
    }
}