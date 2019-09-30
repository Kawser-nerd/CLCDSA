using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray(); 
        //int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        
        Console.WriteLine((double)input[0]/input[1]==(double)4/3?"4:3":"16:9");
        Console.ReadLine();
    }
}