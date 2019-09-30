using System;
using System.Linq;
class Program
{
    static void Main()
    {
        double[] input = Console.ReadLine().Split().Select(i=>double.Parse(i)).ToArray();
 
        Console.WriteLine(Math.Ceiling(input[1]/input[0]));
        Console.ReadLine();
    }
}