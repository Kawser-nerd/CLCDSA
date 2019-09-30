using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        Array.Sort(input);
        //int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(input[1]);
        Console.ReadLine();
    }
}