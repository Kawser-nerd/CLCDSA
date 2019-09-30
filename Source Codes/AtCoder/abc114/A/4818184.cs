using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        int input=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(input==3||input==5||input==7?"YES":"NO");
        Console.ReadLine();
    }
}