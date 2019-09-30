using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray(); 
        int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        
        Console.WriteLine(a/10+a%10);
        Console.ReadLine();
    }
}