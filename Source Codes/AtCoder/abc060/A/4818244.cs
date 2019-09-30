using System;
using System.Linq;
class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        //int input=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(input[0][input[0].Length-1]==input[1][0]&&input[1][input[1].Length-1]==input[2][0]?"YES":"NO");
        Console.ReadLine();
    }
}