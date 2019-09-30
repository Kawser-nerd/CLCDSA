using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray(); 
        //int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        
        Console.WriteLine(input[1]<=(double)input[0]/2? input[1]-1:input[0]-input[1]);
        Console.ReadLine();
    }
}