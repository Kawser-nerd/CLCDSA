using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        //int a=int.Parse(Console.ReadLine());
        Console.WriteLine(input[1]-input[0]+1);
        Console.ReadLine();
    }
}