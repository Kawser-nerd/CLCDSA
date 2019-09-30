using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray(); 
        //int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        
        Console.WriteLine(Math.Max(input[0]*input[1],input[2]*input[3]));
        Console.ReadLine();
    }
}