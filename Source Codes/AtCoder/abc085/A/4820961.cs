using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray(); 
        //int a=int.Parse(Console.ReadLine());
        string a = Console.ReadLine();

        Console.WriteLine("2018" + a.Substring(4, a.Length-4));
        Console.ReadLine();
    }
}